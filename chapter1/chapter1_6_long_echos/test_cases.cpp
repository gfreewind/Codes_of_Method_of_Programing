#include <iostream>
#include <limits>
#include <gtest/gtest.h>

#include "long_echo.h"

TEST(long_echo_string_by_iter, OddEchos)
{
	ASSERT_EQ(1, long_echo_string_by_iter("abcde"));
	ASSERT_EQ(3, long_echo_string_by_iter("abcdc"));
	ASSERT_EQ(5, long_echo_string_by_iter("abcdcb"));
}

TEST(long_echo_string_by_iter, EvenEchos)
{
	ASSERT_EQ(2, long_echo_string_by_iter("abcdd"));
	ASSERT_EQ(4, long_echo_string_by_iter("abccbe"));
}

TEST(long_echo_string_by_iter, EdgeTest)
{
	ASSERT_EQ(-1, long_echo_string_by_iter(NULL));
	ASSERT_EQ(0, long_echo_string_by_iter(""));
	ASSERT_EQ(2, long_echo_string_by_iter("aabcdefg"));
	ASSERT_EQ(3, long_echo_string_by_iter("abcdefghg"));
	ASSERT_EQ(10, long_echo_string_by_iter("abcdeedcba"));
	ASSERT_EQ(13, long_echo_string_by_iter("abcdefgfedcba"));
}

int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


