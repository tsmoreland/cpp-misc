//
// Copyright © 2021 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), 
// to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, 
// and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, 
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, 
// WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
// 

#pragma once

#include <chrono>
#include <optional>
#include <shared_mutex>
#include <map>
#include <stdexcept>
#include <tuple>
#include <thread>

#include "modern_win32/threading/event.h"

namespace tsmoreland::periodic_monitor
{
    template <typename ITEM>
    class monitor 
    {
        modern_win32::threading::manual_reset_event stop_event_{ false };
        std::map<ITEM, std::chrono::time_point<std::chrono::system_clock>> items_{};
        std::shared_mutex item_lock_;
        std::shared_mutex start_stop_lock_;
        std::optional<std::thread> worker_{};
        std::atomic<bool> shutdown_{};
        std::atomic<bool> is_running_{};
        std::chrono::milliseconds const poll_period_{};
        std::chrono::milliseconds const life_time_{};

    public:
        static_assert(std::is_trivial_v<ITEM>, "item should be trivial to construct/copy/etc...");

        /// <summary>
        /// Returns the poll period in milliseconds 
        /// </summary>
        /// <returns>the poll period in milliseconds</returns>
        [[nodiscard]]
        constexpr auto poll_period() const noexcept -> std::chrono::milliseconds
        {
            return poll_period_;
        }

        /// <summary>
        /// Returns the item life time in milliseconds
        /// </summary>
        /// <returns>item life time in milliseconds</returns>
        [[nodiscard]]
        constexpr auto life_time() const noexcept -> std::chrono::milliseconds
        {
            return life_time_;
        }

        /// <summary>
        /// adds <paramref name="value"/> to the collection of items using current time as its time stamp.
        /// </summary>
        /// <param name="value">item to add</param>
        void add(ITEM const& value) 
        {
            if (shutdown_) {
                return;
            }

            std::unique_lock lock{item_lock_};
            std::ignore = items_.insert_or_assign(value, std::chrono::system_clock::now());
        }

        /// <summary>
        /// starts monitoring of the items
        /// </summary>
        /// <remarks>
        /// can only be called once, subsequent calls will be ignored
        /// </remarks>
        void start()
        {
            if (shutdown_) {
                return;
            }

            std::unique_lock lock{start_stop_lock_};
            if (worker_.has_value()) {
                return;
            }
            worker_ = std::optional(std::thread(&monitor::work, this));
        }
        /// <summary>
        /// stops monitoring optionally waiting for processing to complete
        /// </summary>
        /// <param name="wait"></param>
        void stop(bool wait = false)
        {
            shutdown_ = true;
            if (!stop_event_.set()) {
                // ... log?
            }

            if (wait && worker_.has_value() && worker_.value().joinable()) {
                worker_.value().join();
            }

        }

        /// <summary>
        /// constructs a new instance of the monitor class with given poll period, lifetime and optional minimum delay
        /// </summary>
        /// <param name="poll_period">period between polling/processoing the items</param>
        /// <param name="life_time">life time of items to be processed</param>
        /// <exception cref="std::invalid_argument">
        /// if any of the arguments are less than or equal to zero (in the case of minimum delay this check only applies if a value is provided)
        /// </exception>
        explicit monitor(std::chrono::milliseconds const& poll_period, std::chrono::milliseconds const& life_time)
            : poll_period_{ poll_period }
            , life_time_{ life_time }
        {
            if (poll_period_ <= std::chrono::seconds(0)) {
                throw std::invalid_argument("poll period must be greater than 0");
            }
            if (life_time_ <= std::chrono::seconds(0)) {
                throw std::invalid_argument("life time period must be greater than 0");
            }

            if (life_time_ < poll_period_) {
                throw std::invalid_argument("life time must be greater than poll period so it has a chance to be seen once");
            }

        }
        virtual ~monitor()
        {
            stop(true);
        }
        monitor(monitor const&) = delete;
        monitor(monitor &&) noexcept = delete;
        monitor& operator=(monitor const&) = delete;
        monitor& operator=(monitor &&) noexcept = delete;

    protected:
        /// <summary>
        /// called periodically, when imlemented is used to process items who are within the provided life time of items
        /// </summary>
        /// <param name="items">collection of items to process container
        /// </param>
        /// <returns>
        /// items that have been processed and which can be removed 
        /// </returns>
        [[nodiscard]]
        virtual std::vector<ITEM> process_items(std::vector<ITEM> const& items) = 0;

        /// <summary>
        /// called when expired items are removed to allow any
        /// </summary>
        /// <param name="items"></param>
        virtual void notify_expired(std::vector<ITEM> const& items) = 0;

        /// <summary>
        /// Returns all items as a constant reference
        /// </summary>
        /// <returns>all items as a constant reference</returns>
        /// <remarks>
        /// primarily intended for debugging and testing
        /// </remarks>
        [[nodiscard]]
        constexpr auto items() const noexcept -> std::map<ITEM, std::chrono::time_point<std::chrono::system_clock>> const&
        {
            return items_;
        }

        /// <summary>
        /// Returns true if the monitor has been started; otherwise, false
        /// </summary>
        /// <returns>true if the monitor has been started; otherwise, false</returns>
        [[nodiscard]]
        constexpr auto is_running() const noexcept -> bool
        {
            return is_running_;
        }
    private:
        void work() 
        {
            class in_scope final
            {
                std::atomic<bool>& value_;
            public:
                explicit in_scope(std::atomic<bool>& value)
                    : value_{ value }
                {
                    value_ = true;
                }
                ~in_scope()
                {
                    value_ = false;
                }
                in_scope(in_scope const&) = delete;
                in_scope(in_scope&&) noexcept = delete;
                in_scope& operator=(in_scope const&) = delete;
                in_scope& operator=(in_scope&&) noexcept = delete;
            };

            in_scope running{ is_running_ };

            try {
                work_task();
            } catch (std::exception const&) {
                // ... log maybe?
            }
            is_running_ = false;

        }
        void work_task() 
        {
            bool shutdown;

            if (shutdown = get_shutdown(); shutdown) {
                return;
            }

            while (!shutdown) {
                std::ignore = stop_event_.wait_one(poll_period_);

                // the following is repetitive but need after anything that may take some time, including
                // entering a lock
                if (shutdown_) {
                    return;
                }

                auto active_items = std::move(get_active_items());

                if (shutdown_) {
                    return;
                }

                std::vector<ITEM> processed{ process_items(active_items) };
                if (shutdown_) {
                    return;
                }

                clear_expired_and_processed(processed);

                if (shutdown_) {
                    return;
                }
            }

        }

        [[nodiscard]]
        bool get_shutdown() const noexcept
        {
            return shutdown_;
        }
        [[nodiscard]]
        std::vector<ITEM> get_active_items()
        {
            std::vector<ITEM> active_items{};
            std::shared_lock lock{ item_lock_ };
            if (items_.empty()) {
                return active_items;
            }

            for (auto const& [key, value] : items_) {
                if ((std::chrono::system_clock::now() - value) < life_time_) {
                    active_items.push_back(key);
                }
            }
            return active_items;
        }
        void clear_expired_and_processed(std::vector<ITEM> const& to_remove)
        {
            std::vector<ITEM> expired{};

            {
                std::unique_lock lock{ item_lock_ }; 

                for (auto const& item : items_) {
                    if (auto const& [key, value] = item;
                        std::chrono::system_clock::now() - value >= life_time_ &&
                        std::find(begin(to_remove), end(to_remove), key) == end(to_remove)) {
                        expired.push_back(key);
                    }
                }
                std::erase_if(items_,
                    [&to_remove, this](auto const& item) {
                        auto const& [key, value] = item;
                        return
                            std::find(begin(to_remove), end(to_remove), key) != end(to_remove) ||
                            std::chrono::system_clock::now() - value >= life_time_;
                    });
            }

            notify_expired(expired);

        }

    };
}