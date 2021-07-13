// Consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "com_environment.h"
#include "imports.h"

using tsmoreland::sample::com_environment;
using tsmoreland::sample::try_execute;
using std::cout;
using std::wcout;

int main()
{
    try {
        com_environment environment{};

        ProducerLib::IGroupPtr field{ nullptr };

        IClassFactory* class_factory{ nullptr };

        if (auto const hr = CoGetClassObject(__uuidof(ProducerLib::Field), CLSCTX_LOCAL_SERVER, nullptr, IID_IClassFactory, reinterpret_cast<void**>(&class_factory)); // NOLINT(clang-diagnostic-language-extension-token)
            FAILED(hr)) {
            return -1;
        }
        IUnknown* unknown;
        if (auto const hr = class_factory->CreateInstance(nullptr, __uuidof(ProducerLib::IField), reinterpret_cast<void**>(&unknown)); // NOLINT(clang-diagnostic-language-extension-token)
            FAILED(hr)) {

            return -1;
        }
        class_factory->Release(); 


        if (auto const [success, hr] = try_execute(
            [&field]() {
                return field.CreateInstance(__uuidof(ProducerLib::Field), nullptr, CLSCTX_LOCAL_SERVER); // NOLINT(clang-diagnostic-language-extension-token)
                //return field.CreateInstance(__uuidof(ProducerLib::Field));// NOLINT(clang-diagnostic-language-extension-token)
            });  
            !success) { // NOLINT(clang-diagnostic-language-extension-token)
            HRESULT hresult = hr;
            wcout << "Failed to create instance, probably require to launch exe first (HRESULT " << std::hex <<  hresult << " \n";
            return -1;
        }

        wcout << "Finished.\n";

        return 0;

    } catch (std::exception const& ex) {
        cout << "Error " << ex.what() << "\n";
        return -1;
    }

}

