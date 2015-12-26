#include <iostream>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

#include "three_flags_sort.hpp"

TEST(three_flags_sort_by_three_pointers, NormalTest)
{
	int array1[] = {0,1,2};
	int result1[] = {0,1,2};
	
	std::random_shuffle(array1, array1+3);
	three_flags_sort_by_three_pointers(array1, 3);
	ASSERT_TRUE(0 == memcmp(array1, result1, sizeof(result1)));

	int array2[] = {0,0,0,1,1,1,2,2,2};
	int result2[] = {0,0,0,1,1,1,2,2,2};
	std::random_shuffle(array2, array2+9);
	three_flags_sort_by_three_pointers(array2, 9);
	ASSERT_TRUE(0 == memcmp(array2, result2, sizeof(result2)));

	int array3[] = {0,0,0,0,1,1,2,2,2,2,2};
	int result3[] = {0,0,0,0,1,1,2,2,2,2,2};
	std::random_shuffle(array3, array3+11);
	three_flags_sort_by_three_pointers(array3, 11);
	ASSERT_TRUE(0 == memcmp(array3, result3, sizeof(result3)));
}

TEST(three_flags_sort_by_three_pointers, UnnormalTest)
{
	int array1[] = {1,1,2,2,2};
	int result1[] = {1,1,2,2,2};
	std::random_shuffle(array1, array1+5);
	three_flags_sort_by_three_pointers(array1, 5);
	ASSERT_TRUE(0 == memcmp(array1, result1, sizeof(result1)));

	int array2[] = {0,0,0,2};
	int result2[] = {0,0,0,2};
	std::random_shuffle(array2, array2+4);
	three_flags_sort_by_three_pointers(array2, 4);
	ASSERT_TRUE(0 == memcmp(array2, result2, sizeof(result2)));

	int array3[] = {0,0,1,1,1,1};
	int result3[] = {0,0,1,1,1,1};
	std::random_shuffle(array3, array3+6);
	three_flags_sort_by_three_pointers(array3,6);
	ASSERT_TRUE(0 == memcmp(array3, result3, sizeof(result3)));

	int array4[] = {0,0,0,0};
	int result4[] = {0,0,0,0};
	three_flags_sort_by_three_pointers(array4,4);
	ASSERT_TRUE(0 == memcmp(array4, result4, sizeof(result4)));

	int array5[] = {1,1,1,1};
	int result5[] = {1,1,1,1};
	three_flags_sort_by_three_pointers(array5,4);
	ASSERT_TRUE(0 == memcmp(array5, result5, sizeof(result5)));

	int array6[] = {2,2,2,2};
	int result6[] = {2,2,2,2};
	three_flags_sort_by_three_pointers(array6,4);
	ASSERT_TRUE(0 == memcmp(array6, result6, sizeof(result6)));
	
}

int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


