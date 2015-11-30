
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(long_echo)

add_executable(long_echo test_cases.cpp long_echo.cpp)

TARGET_LINK_LIBRARIES(long_echo gtest gtest_main pthread)


