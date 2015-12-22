#include <iostream>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

#include "find_max_sum_subarray.hpp"

int main(int argc, char **argv) 
{
	int array1[] = {1, -2, 3, 10, -4, 7, 2, -5};

	find_max_sum_subarray(array1, sizeof(array1)/sizeof(array1[0]));

	return 0;
}


