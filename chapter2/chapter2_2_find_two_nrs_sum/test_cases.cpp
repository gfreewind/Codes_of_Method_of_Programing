#include <iostream>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

#include "find_two_nrs_sum.hpp"

int main(int argc, char **argv) 
{
	int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
	int dup_array[] = {1, 1, 2, 2, 3, 3, 4, 4, 5, 5};

	std::random_shuffle(array, array+10);
	find_two_nrs_sum_by_endpoints(array, 10, 1);
	find_two_nrs_sum_by_endpoints(array, 10, 2);
	find_two_nrs_sum_by_endpoints(array, 10, 3);
	find_two_nrs_sum_by_endpoints(array, 10, 5);
	find_two_nrs_sum_by_endpoints(array, 10, 7);
	find_two_nrs_sum_by_endpoints(array, 10, 9);
	find_two_nrs_sum_by_endpoints(array, 10, 11);
	find_two_nrs_sum_by_endpoints(array, 10, 12);
	find_two_nrs_sum_by_endpoints(array, 10, 14);
	find_two_nrs_sum_by_endpoints(array, 10, 16);
	find_two_nrs_sum_by_endpoints(array, 10, 18);

	std::random_shuffle(dup_array, dup_array+10);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 2);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 3);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 4);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 5);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 6);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 7);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 8);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 9);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 10);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 11);
	find_two_nrs_sum_by_endpoints(dup_array, 10, 12);

	return 0;
}


