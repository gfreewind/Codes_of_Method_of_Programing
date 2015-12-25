
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(odd_even_sort)

add_executable(odd_even_sort test_cases.cpp odd_even_sort.cpp)

TARGET_LINK_LIBRARIES(odd_even_sort gtest gtest_main pthread)


