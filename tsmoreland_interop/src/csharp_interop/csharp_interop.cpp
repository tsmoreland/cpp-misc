//
// Copyright © 2022 Terry Moreland
// Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated
// documentation files (the "Software"), to deal in the Software without restriction, including without limitation the
// rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to
// permit persons to whom the Software is furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all copies or substantial portions of the
// Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE
// WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR
// COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR
// OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//

#include "common.h"
#include <iostream>

#include "com_environment.h"
#include "in_process_com_server_net_framework.h"

using tsmoreland::interop::csharp_interop::com_environment;
using tsmoreland::interop::in_process_com_server::net_framework::simple_net_framework_object_facade;

int main() {
    com_environment env{};

    simple_net_framework_object_facade net_framework_object{};

    net_framework_object.set_name(L"from C++");
    net_framework_object.set_value(397L);

    std::wcout << net_framework_object.name() << L" " << net_framework_object.value() << L"\n";

    double const area = net_framework_object.calculate_area_of_circle(2.0);
    std::wcout << L"area: " << area << std::endl;

    return 0;
}
