// Consumer.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "com_environment.h"

using tsmoreland::sample::com_environment;

int main()
{
    try {
        com_environment environment{};
        std::cout << "Hello World!\n";
        return 0;

    } catch (std::exception const&) {
        return -1;
    }

}

