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

#include <iostream>
#include "sample_monitor.h"

using tsmoreland::periodic_monitor::app::sample_monitor;

#pragma warning(push)
#pragma warning(disable : 4455)
using std::literals::chrono_literals::operator ""ms;
using std::literals::chrono_literals::operator ""s;
#pragma warning(pop)


int main()
{
    try {
        sample_monitor monitor{ 5s, 10s };

        int i;
        for (i = 0; i < 4; i++) {
            monitor.add(i);
        }

        std::cout << "start monitoring\n";
        monitor.start();

        std::this_thread::sleep_for(5s);

        std::cout << "add items\n";
        for (; i < 8; i++) {
            monitor.add(i);
        }

        std::this_thread::sleep_for(5s);

        std::cout << "add items\n";
        for (; i < 12; i++) {
            monitor.add(i);
        }

        std::this_thread::sleep_for(10s);
        std::cout << "stop monitoring\n";
        monitor.stop();

        return 0;

    } catch (...) {
        return -1;
    }
}

