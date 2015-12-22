
# CMake version
cmake_minimum_required (VERSION 2.8)


#set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} -Wall -Werror -g -std=c++11")
set(CMAKE_CXX_FLAGS "-g -Wall -Werror -std=c++11")

set(CMAKE_VERBOSE_MAKEFILE ON)

# Target name
project(find_max_sum_subarray)

add_executable(find_max_sum_subarray test_cases.cpp find_max_sum_subarray.cpp)

TARGET_LINK_LIBRARIES(find_max_sum_subarray gtest gtest_main pthread)


