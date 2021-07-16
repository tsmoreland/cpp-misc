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

#include <iostream>
#include "periodic_monitor/monitor.h"

namespace tsmoreland::periodic_monitor::app
{
    class sample_monitor final : public monitor<int>
    {
        using milliseconds = std::chrono::milliseconds;
        using optional_milliseconds = std::optional<std::chrono::milliseconds>;
    public:
        explicit sample_monitor(milliseconds const& poll_period, milliseconds const& life_time)
            : monitor<int>(poll_period, life_time)
        {
        }

    protected:
        std::vector<int> process_items(std::vector<int> const& items) final
        {
            std::vector<int> processed{};

            std::cout << "to process: ";
            for (auto const& item : items) {
                std::cout << item << " ";
            }
            std::cout << "\n";

            for (auto const& item : items) {
                if (item % 2 == 0) {
                    processed.push_back(item);
                    std::cout << "remove " << item << "\n";
                }
            }
            return processed;
        }
    };
}
