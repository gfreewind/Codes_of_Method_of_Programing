
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(string_permutation)

add_executable(string_permutation test_cases.cpp string_permutation.cpp)

TARGET_LINK_LIBRARIES(string_permutation gtest gtest_main pthread)


