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


namespace tsmoreland::periodic_monitor::test
{
    BOOST_AUTO_TEST_CASE(add__adds_to_items__when_item_not_present)
    {
        std::vector<int> processed{};

        auto processor = [&processed](std::vector<int> const&) {
            return processed;
        };
        test_monitor monitor(processor);
    
        monitor.add(1);

        BOOST_REQUIRE(monitor.contains(1));
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

        BOOST_REQUIRE(monitor.count_of(1) == 1);
    }
}
