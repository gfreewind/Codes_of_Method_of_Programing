#include <iostream>
#include <limits>
#include <algorithm>
#include <gtest/gtest.h>

#include "find_min_k_nr.h"


TEST(find_min_k_nrs_by_sort, NormalTest)
{
	int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int result[20];
	int result1[] = {1};
	int result2[] = {1,2};
	int result10[] = {1,2,3,4,5,6,7,8,9,10};
	int result20[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int dup_array[] = {1,1,2,2,3,3,4,4,5,5};
	int dup_result[10];
	int dup_result1[] = {1};
	int dup_result2[] = {1,1};
	int dup_result5[] = {1,1,2,2,3};

	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_sort(array, 20, 1, result);
	ASSERT_TRUE(0 == memcmp(result1, result, sizeof(result1)));
	
	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_sort(array, 20, 2, result);
	ASSERT_TRUE(0 == memcmp(result2, result, sizeof(result2)));

	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_sort(array, 20, 10, result);
	ASSERT_TRUE(0 == memcmp(result10, result, sizeof(result10)));
	
	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_sort(array, 20, 20, result);
	ASSERT_TRUE(0 == memcmp(result20, result, sizeof(result20)));

	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_sort(dup_array, 10, 1, dup_result);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result1, sizeof(dup_result1)));
	
	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_sort(dup_array, 10, 2, dup_result);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result2, sizeof(dup_result2)));
	
	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_sort(dup_array, 10, 5, dup_result);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result5, sizeof(dup_result5)));
}

TEST(find_min_k_nrs_by_partition, NormalTest)
{
	int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int result[20];
	int result1[] = {1};
	int result2[] = {1,2};
	int result10[] = {1,2,3,4,5,6,7,8,9,10};
	int result20[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int dup_array[] = {1,1,2,2,3,3,4,4,5,5};
	int dup_result[10];
	int dup_result1[] = {1};
	int dup_result2[] = {1,1};
	int dup_result5[] = {1,1,2,2,3};

	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_partition(array, 20, 1, result);
	ASSERT_TRUE(0 == memcmp(result1, result, sizeof(result1)));
	
	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_partition(array, 20, 2, result);
	std::sort(result, result+2);
	ASSERT_TRUE(0 == memcmp(result2, result, sizeof(result2)));

	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_partition(array, 20, 10, result);
	std::sort(result, result+10);
	ASSERT_TRUE(0 == memcmp(result10, result, sizeof(result10)));
	
	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_partition(array, 20, 20, result);
	std::sort(result, result+20);
	ASSERT_TRUE(0 == memcmp(result20, result, sizeof(result20)));

	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_partition(dup_array, 10, 1, dup_result);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result1, sizeof(dup_result1)));
	
	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_partition(dup_array, 10, 2, dup_result);
	std::sort(dup_result, dup_result+2);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result2, sizeof(dup_result2)));
	
	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_partition(dup_array, 10, 5, dup_result);
	std::sort(dup_result, dup_result+5);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result5, sizeof(dup_result5)));
}

TEST(find_min_k_nrs_by_insert, NormalTest)
{
	int array[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int result[20];
	int result1[] = {1};
	int result2[] = {1,2};
	int result10[] = {1,2,3,4,5,6,7,8,9,10};
	int result20[] = {1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20};
	int dup_array[] = {1,1,2,2,3,3,4,4,5,5};
	int dup_result[10];
	int dup_result1[] = {1};
	int dup_result2[] = {1,1};
	int dup_result5[] = {1,1,2,2,3};

	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_insert(array, 20, 1, result);
	ASSERT_TRUE(0 == memcmp(result1, result, sizeof(result1)));
	
	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_insert(array, 20, 2, result);
	std::sort(result, result+2);
	ASSERT_TRUE(0 == memcmp(result2, result, sizeof(result2)));

	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_insert(array, 20, 10, result);
	std::sort(result, result+10);
	ASSERT_TRUE(0 == memcmp(result10, result, sizeof(result10)));
	
	std::random_shuffle(array, array+20);
	find_min_k_nrs_by_insert(array, 20, 20, result);
	std::sort(result, result+20);
	ASSERT_TRUE(0 == memcmp(result20, result, sizeof(result20)));

	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_insert(dup_array, 10, 1, dup_result);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result1, sizeof(dup_result1)));
	
	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_insert(dup_array, 10, 2, dup_result);
	std::sort(dup_result, dup_result+2);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result2, sizeof(dup_result2)));
	
	std::random_shuffle(dup_array, dup_array+10);
	find_min_k_nrs_by_insert(dup_array, 10, 5, dup_result);
	std::sort(dup_result, dup_result+5);
	ASSERT_TRUE(0 == memcmp(dup_result, dup_result5, sizeof(dup_result5)));
}


int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


