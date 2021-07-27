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

#include <periodic_monitor/monitor.h>

namespace tsmoreland::periodic_monitor::test
{
    template <typename TCALLBACK, typename TNOTIFICATION>
    class test_monitor : public monitor<int>
    {
        using milliseconds = std::chrono::milliseconds;
        TCALLBACK const& callback_;
        TNOTIFICATION const& handler_;
    public:
        explicit test_monitor(TCALLBACK const& callback, TNOTIFICATION const& handler, std::chrono::milliseconds const& poll_period, std::chrono::milliseconds const& life_time)
            : monitor<int>(poll_period, life_time)
            , callback_{ callback }
            , handler_{ handler }
        {
        }

        explicit test_monitor(TCALLBACK const& callback, TNOTIFICATION const& handler)
            : monitor<int>(milliseconds(100), milliseconds(150))
            , callback_{ callback }
            , handler_{ handler }
        {
        }

        constexpr auto get_is_running() const noexcept -> bool
        {
            return is_running();
        }

        [[nodiscard]]
        constexpr auto get_items() const noexcept -> std::map<int, std::chrono::time_point<std::chrono::system_clock>> const&
        {
            return items();
        }

        [[nodiscard]]
        auto contains(int const value) const -> bool
        {
            return items().count(value) != 0;
        }

        [[nodiscard]]
        auto count_of(int const value) const -> std::map<int, std::chrono::system_clock>::size_type
        {
            return items().count(value);
        }

        [[nodiscard]]
        auto get_timestamp_or_nullopt(int value) const -> std::optional<std::chrono::time_point<std::chrono::system_clock>>
        {
            return contains(value)
                ? std::optional(items().at(value))
                : std::nullopt;
        }

    protected:
        [[nodiscard]]
        std::vector<int> process_items(std::vector<int> const& items) override
        {
            return callback_(items);
        }

        void notify_expired(std::vector<int> const& items) override
        {
            handler_(items);
        }
    };

}
