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

#include "com_environment.h"

#include <algorithm>
#include <exception>
#include <memory>
#include <sstream>
#include <string>

using std::exception;
using std::endl;
using std::hex;
using std::dec;
using std::make_unique;
using std::wstring_view;

#pragma warning(disable : 4455)
using std::literals::operator ""s;


namespace tsmoreland::sample
{
    com_environment::com_environment()
    {
        if (auto const hr = CoInitialize(nullptr);
            FAILED(hr)) {

            throw exception(("Failed to initialize COM: "s + to_string(hr)).c_str());
        }
    }

    com_environment::~com_environment()
    {
        CoUninitialize();
    }

    std::string com_environment::to_string(HRESULT const hr)
    {
        const auto szErrMsg = make_unique<TCHAR[]>(1024);
        if (FormatMessage(FORMAT_MESSAGE_FROM_SYSTEM, nullptr, hr, MAKELANGID(LANG_NEUTRAL, SUBLANG_DEFAULT), static_cast<LPWSTR>(szErrMsg.get()), 1024, nullptr) != 0) {
            wstring_view const view(szErrMsg.get());

            // unsafe or at least inaccurate string conversion, but enough for demo purposes
            std::string result{};
            std::ranges::transform(view,std::back_inserter(result),
                [](auto const wide_ch) {
                    return static_cast<char>(wide_ch);
                });

            return result;
        }
        else {
            std::stringstream ss{};
            ss << "Could not find a description for error 0x" << hex << hr << dec << endl;
            return ss.str();
        }
    }
}
