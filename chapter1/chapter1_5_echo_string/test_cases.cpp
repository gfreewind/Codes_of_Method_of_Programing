#include <iostream>
#include <limits>
#include <gtest/gtest.h>

#include "echo_string.h"


TEST(is_echo_string_by_endpoints, NormalTest)
{
	ASSERT_FALSE(is_echo_string_by_endpoints("abc"));
	ASSERT_TRUE(is_echo_string_by_endpoints("aa"));
	ASSERT_TRUE(is_echo_string_by_endpoints("abcba"));
	ASSERT_FALSE(is_echo_string_by_endpoints("abcabcabc"));
	ASSERT_TRUE(is_echo_string_by_endpoints("abcddcba"));
}

TEST(is_echo_string_by_endpoints, EdgeTest)
{
	ASSERT_FALSE(is_echo_string_by_endpoints("a"));
	ASSERT_FALSE(is_echo_string_by_endpoints(""));
	ASSERT_FALSE(is_echo_string_by_endpoints(NULL));
}


int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


