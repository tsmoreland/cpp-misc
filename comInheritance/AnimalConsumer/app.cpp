// OopAnimalConsumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <Windows.h>
#include <iostream>

#include "com_environment.h"
#include "imports.h"

using tsmoreland::sample::com_environment;
using tsmoreland::sample::convert;
using tsmoreland::sample::try_execute;

using std::wcout;

int main()
{
    try {

        com_environment com{};

        AnimalProducerLib::IAnimalPtr animal{ nullptr };
        if (!try_execute([&animal]() { return animal.CreateInstance(__uuidof(AnimalProducerLib::Animal)); })) {
            wcout << L"Unable to create an animal object.\n";
        }

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

