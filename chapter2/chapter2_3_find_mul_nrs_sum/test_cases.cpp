#include <iostream>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

#include "find_mul_nrs_sum.hpp"

int main(int argc, char **argv) 
{
	std::cout << "The numbers(1~10) of their sum are 11" << std::endl;
	find_mul_nrs_sum_by_recusive2(10, 11);
	std::cout << "The numbers(1~1) of their sum are 3" << std::endl;
	find_mul_nrs_sum_by_recusive2(1, 3);	
	std::cout << "The numbers(1~20) of their sum are 20" << std::endl;
	find_mul_nrs_sum_by_recusive2(20, 20);	
	std::cout << "The numbers(1~4) of their sum are 10" << std::endl;
	find_mul_nrs_sum_by_recusive2(4, 10);
	std::cout << "The numbers(1~4) of their sum are 12" << std::endl;
	find_mul_nrs_sum_by_recusive2(4, 12);
	return 0;
}


