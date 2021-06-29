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

#include <Windows.h>
#include <iostream>

#include "com_environment.h"
#include "imports.h"

using tsmoreland::sample::com_environment;
using tsmoreland::sample::convert;
using tsmoreland::sample::try_execute;

using std::wcout;

int main()  // NOLINT(bugprone-exception-escape)
{
    try {

        com_environment com{};

        // isn't really need for is effectively a class factory, doing it mostly to show returning something more complex than BSTR or LONG
        AnimalProducerLib::IAnimalCrudPtr repository{ nullptr };
        if (!try_execute([&repository]() { return repository.CreateInstance(__uuidof(AnimalProducerLib::AnimalCrud)); })) {  // NOLINT(clang-diagnostic-language-extension-token)
            wcout << L"Unable to create an animal object.\n";
        }

        AnimalProducerLib::IAnimalPtr animal{ repository->CreateAnimal() };

        auto const com_name = animal->Name();
        std::wstring const name{ com_name };

        wcout << L"name: " << name << L"\n";

        auto animal2 = convert<AnimalProducerLib::IAnimal2, AnimalProducerLib::IAnimal>(animal);
        wcout << L"Top speed: " << animal2->TopSpeed() << L"\n";
        // rely on scope when using _com_ptr_t, we can call Release here and it does release, but so does the destructor
        // so this starts a time-bomb.  Basing this off a single run that blew up with this added
        //animal2->Release(); 

        auto animal3 = convert<AnimalProducerLib::IAnimal3, AnimalProducerLib::IAnimal>(animal);
        auto const can_swim = (animal3->CanSwim() == VARIANT_TRUE)
            ? L"yes"
            : L"no";
        wcout << L"Can swim: " << can_swim << L"\n";

    } catch (std::exception const& ex) {

        std::cout << ex.what() << "\n";
    }

    return 0;
}

