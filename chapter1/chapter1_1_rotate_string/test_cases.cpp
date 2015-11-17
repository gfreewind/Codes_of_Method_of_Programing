#include <iostream>

#include <gtest/gtest.h>

#include "rotate_string.h"



TEST(BruteForceRotateString, PostiveRotate) 
{
	char test1[] = "1234567890";
	char test2[] = "1234567890";
	char test3[] = "1234567890";

	ASSERT_STREQ("2345678901", brute_force_rotate_string(test1, 1));
	ASSERT_STREQ("6789012345", brute_force_rotate_string(test2, 5));
	ASSERT_STREQ("3456789012", brute_force_rotate_string(test3, 12));
}

TEST(ThreeReverseRotateString, PostiveRotate) 
{
	char test1[] = "1234567890";
	char test2[] = "1234567890";
	char test3[] = "1234567890";
	char test4[] = "123456789";
	char test5[] = "123456789";

	ASSERT_STREQ("2345678901", three_reverse_rotate_string(test1, 1));
	ASSERT_STREQ("6789012345", three_reverse_rotate_string(test2, 5));
	ASSERT_STREQ("3456789012", three_reverse_rotate_string(test3, 12));
	ASSERT_STREQ("345678912", three_reverse_rotate_string(test4, 2));
	ASSERT_STREQ("912345678", three_reverse_rotate_string(test5, 8));
}


TEST(BruteForceRotateString, ZeroRotate)
{
	char test1[] = "1234567890";

	ASSERT_STREQ("1234567890", brute_force_rotate_string(test1, 0));
}

TEST(ThreeReverseRotateString, ZeroRotate)
{
	char test1[] = "1234567890";

	ASSERT_STREQ("1234567890", three_reverse_rotate_string(test1, 0));
}

TEST(BruteForceRotateString, NegativeRotate)
{
	char test1[] = "1234567890";
	char test2[] = "1234567890";

	ASSERT_STREQ("0123456789", brute_force_rotate_string(test1, -1));
	ASSERT_STREQ("9012345678", brute_force_rotate_string(test2, -12));
}

TEST(ThreeReverseRotateString, NegativeRotate)
{
	char test1[] = "1234567890";
	char test2[] = "1234567890";

	ASSERT_STREQ("0123456789", three_reverse_rotate_string(test1, -1));
	ASSERT_STREQ("9012345678", three_reverse_rotate_string(test2, -12));
}

TEST(BruteForceRotateString, NullStr)
{
	ASSERT_STREQ(NULL, brute_force_rotate_string(NULL, 2));
}

 
int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


