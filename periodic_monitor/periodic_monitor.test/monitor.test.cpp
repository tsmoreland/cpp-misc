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

        BOOST_REQUIRE(first_timestamp.has_value(), "expected value for timestamp");
        BOOST_REQUIRE(second_timestamp.has_value(), "expected value for timestamp");

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

}
