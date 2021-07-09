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

#include <comip.h>
#include <iostream>
#include <string>

#include <Windows.h>

namespace tsmoreland::sample
{
    class com_environment final
    {
    public:
        explicit com_environment();
        ~com_environment();
        com_environment(com_environment const&) = delete;
        com_environment(com_environment&&) noexcept = delete;
        com_environment& operator=(com_environment const ) = delete;
        com_environment& operator=(com_environment&&) noexcept = delete;

        [[nodiscard]]
        static std::string to_string(HRESULT const hr);
    };

    template <typename STDMETHOD_FUNCTOR>
    constexpr auto try_execute(STDMETHOD_FUNCTOR functor)
    {
        if (const HRESULT hr = functor();
            FAILED(hr)) {
            std::cout << com_environment::to_string(hr) << "\n";
            return false;
        }
        return true;
    }

    template<typename DESTINATION_INTERFACE, typename SOURCE_INTERFACE>
    auto convert(_com_ptr_t<_com_IIID<SOURCE_INTERFACE, &__uuidof(SOURCE_INTERFACE)>> const& source) -> _com_ptr_t<_com_IIID<DESTINATION_INTERFACE, &__uuidof(DESTINATION_INTERFACE)>>
    {
        return _com_ptr_t<_com_IIID<DESTINATION_INTERFACE, &__uuidof(DESTINATION_INTERFACE)>>(source);

    }

}

