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

#include "common.h"
#include "test_monitor.h"
#include <stdexcept>
#include <modern_win32/threading/event.h>

#pragma warning(disable : 4455)
using std::literals::chrono_literals::operator ""ms;
using std::literals::chrono_literals::operator ""s;

using modern_win32::threading::manual_reset_event;

namespace tsmoreland::periodic_monitor::test
{
    BOOST_AUTO_TEST_CASE(ctor__throws_invalid_argument__when_poll_period_less_than_or_equal_to_zero)
    {
        auto processor = [](std::vector<int> const&) {
            return std::vector<int>{};
        };
        BOOST_CHECK_THROW(test_monitor monitor(processor, std::chrono::milliseconds(-100), std::chrono::milliseconds(200)), std::invalid_argument);
    }
    
    BOOST_AUTO_TEST_CASE(ctor__throws_invalid_argument__when_life_time_less_than_or_equal_to_zero)
    {
        auto processor = [](std::vector<int> const&) {
            return std::vector<int>{};
        };
        BOOST_CHECK_THROW(test_monitor monitor(processor, std::chrono::milliseconds(100), std::chrono::milliseconds(-200)), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(ctor__throws_invalid_argument__when_life_time_less_poll_period)
    {
        auto processor = [](std::vector<int> const&) {
            return std::vector<int>{};
        };
        BOOST_CHECK_THROW(test_monitor monitor(processor, std::chrono::milliseconds(200), std::chrono::milliseconds(100)), std::invalid_argument);
    }

    BOOST_AUTO_TEST_CASE(add__adds_to_items__when_item_not_present)
    {
        std::vector<int> processed{};
        auto processor = [&processed](std::vector<int> const&) {
            return processed;
        };
        test_monitor monitor(processor);
    
        monitor.add(1);

        BOOST_CHECK(monitor.contains(1));
    }

    BOOST_AUTO_TEST_CASE(add__does_not_add__when_item_already_present)
    {
        std::vector<int> processed{};

        auto processor = [&processed](std::vector<int> const&) {
            return processed;
        };
        test_monitor monitor(processor);
    
        monitor.add(1);
        monitor.add(1);

        BOOST_CHECK(monitor.count_of(1) == 1);
    }

    BOOST_AUTO_TEST_CASE(add__updates_expiry__when_item_already_present)
    {
        std::vector<int> processed{};

        auto processor = [&processed](std::vector<int> const&) {
            return processed;
        };
        test_monitor monitor(processor);
    
        monitor.add(1);
        auto const first_timestamp = monitor.get_timestamp_or_nullopt(1);
        monitor.add(1);
        auto const second_timestamp = monitor.get_timestamp_or_nullopt(1);

        BOOST_REQUIRE(first_timestamp.has_value());
        BOOST_REQUIRE(second_timestamp.has_value());

        BOOST_CHECK(first_timestamp.value() < second_timestamp.value());
    }

    BOOST_AUTO_TEST_CASE(add__does_not_add__after_stop_has_been_called)
    {
        std::vector<int> processed{};
        auto processor = [&processed](std::vector<int> const&) {
            return processed;
        };
        test_monitor monitor(processor);

        monitor.stop();
        monitor.add(1);

        BOOST_CHECK(!monitor.contains(1));
    }

    BOOST_AUTO_TEST_CASE(start__does_not_call_process_items__before_poll_period_elsapsed)
    {
        bool invoked{ false };

        auto processor = [&invoked](std::vector<int> const&) {
            invoked = true;
            return std::vector<int>();
        };
        test_monitor monitor(processor);

        monitor.start();

        BOOST_CHECK(invoked == false);
    }

    BOOST_AUTO_TEST_CASE(start__calls_process_items__after_poll_period_elsapsed)
    {
        bool invoked{ false };

        auto processor = [&invoked](std::vector<int> const&) {
            invoked = true;
            return std::vector<int>();
        };
        test_monitor monitor(processor);

        monitor.start();
        std::this_thread::sleep_for(monitor.poll_period() + 100ms /* time to cover the lock */);

        BOOST_CHECK(invoked == true);
    }

    BOOST_AUTO_TEST_CASE(start__background_worker_removes_items__when_expired)
    {
        std::vector<int> processed{};

        auto processor = [&processed](std::vector<int> const&) {
            return processed;
        };
        test_monitor monitor(processor);

        monitor.add(1);
        monitor.start();

        // multiply by 2 to given a little extra time, typicall use wouldn't need this but
        // we're using low values to speed up the test
        std::this_thread::sleep_for(monitor.life_time() * 2);

        BOOST_CHECK(!monitor.contains(1));
    }

    BOOST_AUTO_TEST_CASE(stop__does_not_wait__when_wait_is_false)
    {
        std::vector<int> processed{};
        manual_reset_event wait_for_process{ false };
        manual_reset_event wait_for_stop{ false };
        

        auto processor = [&processed, &wait_for_process, &wait_for_stop](std::vector<int> const&) {
            std::ignore = wait_for_process.set();
            std::ignore = wait_for_stop.wait_one(2s);
            return processed;
        };

        test_monitor monitor(processor, 50ms, 500ms);

        monitor.start();

        BOOST_REQUIRE(wait_for_process.wait_one(2s));
        BOOST_REQUIRE(monitor.get_is_running());
        monitor.stop();
        bool const is_running = monitor.get_is_running();
        std::ignore = wait_for_stop.set();

        BOOST_CHECK(is_running);
    }

    BOOST_AUTO_TEST_CASE(stop__does_wait__when_wait_is_true)
    {
        std::vector<int> processed{};
        manual_reset_event wait_for_process{ false };
        manual_reset_event wait_for_stop{ false };
        

        auto processor = [&processed, &wait_for_process, &wait_for_stop](std::vector<int> const&) {
            std::ignore = wait_for_process.set();
            BOOST_REQUIRE(!wait_for_stop.wait_one(200ms));
            return processed;
        };

        test_monitor monitor(processor, 10ms, 500ms);

        monitor.start();

        BOOST_REQUIRE(wait_for_process.wait_one(2s));
        BOOST_REQUIRE(monitor.get_is_running());
        monitor.stop(true);
        bool const is_running = monitor.get_is_running();
        std::ignore = wait_for_stop.set(); // doing this here means the wait in processor should time out

        BOOST_CHECK(!is_running);
    }

    namespace
    {
        bool stop_wait_dataset[] = { true, false };
    }

    BOOST_DATA_TEST_CASE(stop__prevents_start_from_running__when_start_not_called_first, stop_wait_dataset, wait_value)
    {
        auto processor = [](std::vector<int> const&) {
            return std::vector<int>();
        };
        test_monitor monitor(processor, 10ms, 200ms);

        monitor.stop(wait_value);
        monitor.start();

        std::this_thread::sleep_for(100ms);

        BOOST_CHECK(!monitor.get_is_running());
    }

}
