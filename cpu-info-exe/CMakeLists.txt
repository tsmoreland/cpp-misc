cmake_minimum_required(VERSION 3.0.0)
project(cpuinfo VERSION 0.1.0)

set(CXX_STANDARD 20)
include(CTest)
enable_testing()

add_executable(cpuinfo main.cpp)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

if (MSVC)
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} /std:c++latest /W4")
    # Default debug flags are OK 
    set(CMAKE_CXX_FLAGS_RELEASE "{CMAKE_CXX_FLAGS_RELEASE} /O2")
endif()