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
#include "simple_object.h"
#include "com_exception.h"

using tsmoreland::interop::csharp_interop::com_exception;

namespace tsmoreland::interop::in_process_com_server {

    constexpr auto simple_object_class_iid = "{1D08A280-9B0A-40FF-90D9-1ED751B11AD8}";

    auto create_simple_object() -> simple_object_interface_ptr {

        simple_object_interface_ptr object{};
        if (HRESULT const hr = object.CreateInstance(simple_object_class_iid); FAILED(hr)) {
            throw com_exception(hr);
        }
        return object.Detach();
    }

    auto simple_object_facade::name() const -> std::wstring {
        BSTR value{};
        if (HRESULT const hr = object_->get_name(&value); FAILED(hr)) {
            throw com_exception(hr);
        }

        std::wstring converted_value{value, SysStringLen(value)};
        SysFreeString(value);
        return converted_value;
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    auto simple_object_facade::set_name(std::wstring const& value) -> void {
        _bstr_t com_value(value.c_str());
        if (HRESULT const hr = object_->put_name(com_value.Detach()); FAILED(hr)) {
            throw com_exception(hr);
        }
    }

    auto simple_object_facade::value() const -> long {
        long value{};
        if (HRESULT const hr = object_->get_value(&value); FAILED(hr)) {
            throw com_exception(hr);
        }
        return value;
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    auto simple_object_facade::set_value(long new_value) -> void {
        if (HRESULT const hr = object_->put_value(new_value); FAILED(hr)) {
            throw com_exception(hr);
        }
    }

    auto simple_object_facade::calculate_area_of_circle(double const radius) const -> double {
        double result{};
        if (HRESULT const hr = object_->calculate_area_of_a_circle(radius, &result); FAILED(hr)) {
            throw com_exception(hr);
        }
        return result;
    }


}
