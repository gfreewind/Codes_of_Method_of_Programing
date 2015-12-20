#include <iostream>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

#include "find_mul_nrs_sum.hpp"

int main(int argc, char **argv) 
{
	std::cout << "The numbers(1~10) of their sum are 11" << std::endl;
	find_mul_nrs_sum_by_recursive(10, 11);
	std::cout << "The numbers(1~1) of their sum are 3" << std::endl;
	find_mul_nrs_sum_by_recursive(10, 3);	
	std::cout << "The numbers(1~20) of their sum are 20" << std::endl;
	find_mul_nrs_sum_by_recursive(10, 20);
	return 0;
}


