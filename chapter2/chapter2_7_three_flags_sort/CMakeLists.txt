
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(three_flags_sort)

add_executable(three_flags_sort test_cases.cpp three_flags_sort.cpp)

TARGET_LINK_LIBRARIES(three_flags_sort gtest gtest_main pthread)


