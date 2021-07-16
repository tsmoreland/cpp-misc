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
    template <typename TKEY>
    class monitor 
    {
        modern_win32::threading::manual_reset_event stop_event_{ false };
        std::map<TKEY, std::chrono::time_point<std::chrono::system_clock>> items_{};
        std::shared_mutex item_lock_;
        std::shared_mutex start_stop_lock_;
        std::optional<std::thread> worker_{};
        bool shutdown_{};
        std::chrono::milliseconds const poll_period_{};
        std::chrono::milliseconds const life_time_{};

    public:
        using time_point = std::chrono::time_point<std::chrono::system_clock>;

        void add(TKEY const& key) 
        {
            if (std::shared_lock lock{start_stop_lock_};
                shutdown_) {
                return;
            }

            std::unique_lock lock{item_lock_};
            std::ignore = items_.insert_or_assign(key, std::chrono::system_clock::now());
        }

        /// <summary>
        /// starts monitoring of the items
        /// </summary>
        /// <remarks>
        /// can only be called once, subsequent calls will be ignored
        /// </remarks>
        void start()
        {
            if (std::shared_lock lock{start_stop_lock_};
                shutdown_) {
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
            std::unique_lock lock{start_stop_lock_};
            if (!worker_.has_value()) {
                return;
            }
            shutdown_ = true;
            if (!stop_event_.set()) {
                // ... log?
            }

            if (wait && worker_.value().joinable()) {
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
        virtual std::vector<TKEY> process_items(std::vector<TKEY> const& items) = 0;

    private:
        void work() 
        {
            try {
                work_task();
            } catch (std::exception const&) {
                // ... log maybe?
            }

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
                if (shutdown = get_shutdown(); shutdown) {
                    return;
                }

                auto active_items = std::move(get_active_items());

                if (shutdown = get_shutdown(); shutdown) {
                    return;
                }

                std::vector<TKEY> processed{ process_items(active_items) };
                if (shutdown = get_shutdown(); shutdown) {
                    return;
                }

                clear_expired_and_processed(processed);

                if (shutdown = get_shutdown(); shutdown) {
                    return;
                }
            }

        }

        [[nodiscard]]
        bool get_shutdown()
        {
            std::shared_lock lock{ start_stop_lock_ };
            return shutdown_;
        }
        [[nodiscard]]
        std::vector<TKEY> get_active_items()
        {
            std::vector<TKEY> active_items{};
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
        void clear_expired_and_processed(std::vector<TKEY> const& to_remove)
        {
            std::unique_lock lock{ item_lock_ };
            std::erase_if(items_,
                [&to_remove, this](auto const& item) {
                    auto const& [key, value] = item;
                    return
                        std::chrono::system_clock::now() - value >= life_time_ ||
                        std::find(begin(to_remove), end(to_remove), key) != end(to_remove);
                });
        }

    };
}