//
// Copyright © 2022 Terry Moreland
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
#include "in_process_com_server_net_framework.h"
#include "com_exception.h"

using tsmoreland::interop::csharp_interop::com_exception;

namespace tsmoreland::interop::in_process_com_server::net_framework {
    

    auto create_simple_net_framework_object() -> TSMoreland_Interop_InProcessComServer_NetFramework::ISimpleNetFrameworkObjectPtr {
        TSMoreland_Interop_InProcessComServer_NetFramework::ISimpleNetFrameworkObjectPtr object{};
        if (HRESULT const hr = object.CreateInstance(__uuidof(TSMoreland_Interop_InProcessComServer_NetFramework::SimpleNetFrameworkObject)); 
            FAILED(hr)) {
            throw com_exception(hr);
        }
        return object.Detach();
    }

    auto simple_net_framework_object_facade::name() const -> std::wstring {

        BSTR value{};
        if (HRESULT const hr = object_->get_Name(&value); FAILED(hr)) {
            throw com_exception(hr);
        }

        std::wstring converted_value{value, SysStringLen(value)};
        SysFreeString(value);
        return converted_value;
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    auto simple_net_framework_object_facade::set_name(std::wstring const& value) -> void {
        _bstr_t com_value(value.c_str());
        if (HRESULT const hr = object_->put_Name(com_value.Detach()); FAILED(hr)) {
            throw com_exception(hr);
        }

    }

    auto simple_net_framework_object_facade::value() const -> long {
        long value{};
        if (HRESULT const hr = object_->get_Value(&value); FAILED(hr)) {
            throw com_exception(hr);
        }
        return value;
    }

    // ReSharper disable once CppMemberFunctionMayBeConst
    auto simple_net_framework_object_facade::set_value(long new_value) -> void {
        if (HRESULT const hr = object_->put_Value(new_value); FAILED(hr)) {
            throw com_exception(hr);
        }

    }

    auto simple_net_framework_object_facade::calculate_area_of_circle(double const radius) const -> double {

        double result{};
        if (HRESULT const hr = object_->CalculateAreaOfACircle(radius, &result); FAILED(hr)) {
            throw com_exception(hr);
        }
        return result;
    }

}
