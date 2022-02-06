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

#pragma once

#import "libid:710b7819-07bc-47b6-a7f6-c6a69fb6e354" raw_interfaces_only, raw_native_types

#include <string>
#include <string_view>

namespace tsmoreland::interop::in_process_com_server::net_framework {
    

    [[nodiscard]]
    auto create_simple_net_framework_object()
        -> TSMoreland_Interop_InProcessComServer_NetFramework::ISimpleNetFrameworkObjectPtr;

    class simple_net_framework_object_facade final {
        TSMoreland_Interop_InProcessComServer_NetFramework::ISimpleNetFrameworkObjectPtr object_{create_simple_net_framework_object()};  // NOLINT(clang-diagnostic-unused-private-field)
    public:
        constexpr explicit simple_net_framework_object_facade() = default;
        
        [[nodiscard]]
        auto name() const -> std::wstring;

        auto set_name(std::wstring const& value) -> void;

        [[nodiscard]]
        auto value() const -> long;

        auto set_value(long new_value) -> void;

        [[nodiscard]]
        auto calculate_area_of_circle(double const radius) const -> double;
    };

}
