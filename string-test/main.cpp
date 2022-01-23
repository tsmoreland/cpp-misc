#include <iostream>
#include <string>
#include <Windows.h>
#include <processenv.h>
#include <algorithm>
#include <ranges>

int main(int argc, char** argv) {
    if (argc < 2) {
        std::cout << "insufficient args\n";
    }
    std::string const arg{argv[1]};

    std::string env_path{};
    env_path.reserve(2048);
    DWORD const size = static_cast<DWORD>(env_path.capacity() * sizeof(char));

    DWORD result = GetEnvironmentVariableA(arg.c_str(), &env_path[0], size);
    // this works but the size of env_path is wrong so it doesn't really work, use a char[2048] and then pass that to a string

    if (0 != result) {
        std::cout << "Env Path: (" <<  result << ") " << env_path << "\n";
    } else {
        std::cout << "Failed: (" << result << ") - "  << GetLastError() << "\n";
    }
    std::cout << std::flush;

    char buffer[2048];
    result = GetEnvironmentVariableA(arg.c_str(), buffer, sizeof buffer);
    if (0 != result) {
        env_path = {buffer, result};
        std::cout << "Env Path: (" <<  result << ") " << env_path.c_str() << "\n";
        std::cout << "transformed: \n";
        auto upper = env_path | std::views::transform([](char const& ch) { return static_cast<char>(toupper(ch)); });
        for (char const& ch : upper) {
            std::cout << ch;
        }
        std::cout << "\n";

        auto match = std::ranges::find(upper, ';');
        if (match != upper.end()) {
            std::cout << "found ;, now to attempt a split string\n";
        }

    } else {
        std::cout << "Failed: (" << result << ") - "  << GetLastError() << "\n";
    }
    std::cout << std::flush;

    return 0;
}
