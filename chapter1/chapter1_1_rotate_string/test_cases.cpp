#include <iostream>

#include <gtest/gtest.h>

#include "rotate_string.h"



TEST(BruteForceRotateString, PostiveRotate) {
	char test1[] = "1234567890";
	char test2[] = "1234567890";
	char test3[] = "1234567890";
	char test4[] = "1234567890";

	ASSERT_STREQ("2345678901", brute_force_rotate_string(test1, 1));
	ASSERT_STREQ("1234567890", brute_force_rotate_string(test2, 0));
	ASSERT_STREQ("6789012345", brute_force_rotate_string(test3, 5));
	ASSERT_STREQ("3456789012", brute_force_rotate_string(test4, 12));
}
 
int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


