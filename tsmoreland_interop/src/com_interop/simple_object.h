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

#include <comdef.h>
#include <string>

namespace tsmoreland::interop::in_process_com_server {

    struct __declspec(uuid("B207098E-7400-4D5B-858E-98472004FA83")) simple_object_interface;
    using simple_object_interface_ptr = _com_ptr_t<_com_IIID<simple_object_interface, &__uuidof(simple_object_interface)>>; // NOLINT(clang-diagnostic-language-extension-token)

    /**
     * \brief COM interface for NET6 simple object.
     * \details Order of methods is important, it must match the order defined
     *          in the COM object as do the parameter types, names however can
     *          be different
     */
    // ReSharper disable once CppPolymorphicClassWithNonVirtualPublicDestructor
    struct __declspec(uuid("B207098E-7400-4D5B-858E-98472004FA83"))
    simple_object_interface : IUnknown { // NOLINT(clang-diagnostic-non-virtual-dtor)
        virtual HRESULT __stdcall get_name(BSTR* return_value) = 0;
        virtual HRESULT __stdcall put_name(BSTR value) = 0;
        virtual HRESULT __stdcall get_value(long* return_value) = 0;
        virtual HRESULT __stdcall put_value(long value) = 0;
        virtual HRESULT __stdcall calculate_area_of_a_circle(double radius, double* return_value) = 0;
    };

    [[nodiscard]] 
    auto create_simple_object() -> simple_object_interface_ptr;

    class simple_object_facade final {
        simple_object_interface_ptr object_{create_simple_object()};

    public:
        constexpr explicit simple_object_facade() = default;

        [[nodiscard]]
        auto name() const -> std::wstring;

        auto set_name(std::wstring const& value) -> void;

        [[nodiscard]]
        auto value() const -> long;

        auto set_value(long new_value) -> void;

        [[nodiscard]]
        auto calculate_area_of_circle(double const radius) const -> double;
    };


} // namespace tsmoreland::interop::in_process_com_server
