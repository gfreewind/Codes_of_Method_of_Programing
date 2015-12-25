#include <iostream>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

#include "odd_even_sort.hpp"

static void print_result(int *array, int size)
{
	for (int i = 0; i < size; ++i) {
		std::cout << array[i] << " ";
	}
	std::cout << std::endl;
}

TEST(odd_even_sort_1, NormalTest)
{
	int array1[] = {1,2,3,4,5,6,7,8,9};
	
	odd_even_sort_1(array1, 9);
	print_result(array1, 9);

	int array2[] = {1,2,3,4,5,6,7,8};
	odd_even_sort_1(array2, 8);
	print_result(array2, 8);

	int array3[] = {2,3,4,5,6,7,8,9};
	odd_even_sort_1(array3, 8);
	print_result(array3, 8);

	int array4[] = {2,3,4,5,6,7,8};
	odd_even_sort_1(array4, 7);
	print_result(array4, 7);
}

TEST(odd_even_sort_1, UnormalTest)
{
	int array1[] = {1};

	odd_even_sort_1(array1, 1);
	print_result(array1, 1);

	int array2[] = {9,8,7,6,5};
	odd_even_sort_1(array2, 5);
	print_result(array2, 5);
}

int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


