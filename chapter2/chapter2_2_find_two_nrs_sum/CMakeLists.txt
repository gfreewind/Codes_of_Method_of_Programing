
# CMake version
cmake_minimum_required (VERSION 2.8)


set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(find_two_nrs_sum)

add_executable(find_two_nrs_sum test_cases.cpp find_two_nrs_sum.cpp)

TARGET_LINK_LIBRARIES(find_two_nrs_sum gtest gtest_main pthread)


