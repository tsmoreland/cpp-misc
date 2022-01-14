#include <iostream>
#include <intrin.h>
#include <string>

int main(int, char**) {

    #include <intrin.h>

    int cpu_info[4] = {-1};
    char cpu_brand[0x40]{};


    __cpuid(cpu_info, 0x80000002);
    memcpy(cpu_brand, cpu_info, sizeof(cpu_info));

    __cpuid(cpu_info, 0x80000003);
    memcpy(cpu_brand + 16, cpu_info, sizeof(cpu_info));

    __cpuid(cpu_info, 0x80000004);
    memcpy(cpu_brand + 32, cpu_info, sizeof(cpu_info));

    std::string cpu_brand_string{cpu_brand};

    std::cout << cpu_brand_string << "\n";

    return 0;
}
