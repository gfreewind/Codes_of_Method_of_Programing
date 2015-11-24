#include <iostream>
#include <limits>
#include <gtest/gtest.h>

#include "string_toint.h"


TEST(string_toint, NormalTest)
{
	ASSERT_EQ(1, string_toint("1"));
	ASSERT_EQ(123, string_toint("123"));
	ASSERT_EQ(123456789, string_toint("123456789"));
	ASSERT_EQ(-1, string_toint("-1"));
	ASSERT_EQ(-123, string_toint("-123"));
	ASSERT_EQ(-123456789, string_toint("-123456789"));
}

TEST(string_toint, EdgeTest)
{
	ASSERT_EQ(0, string_toint("0"));
	ASSERT_EQ(std::numeric_limits<int>::max(), string_toint("999999999999999999"));
	ASSERT_EQ(-std::numeric_limits<int>::max(), string_toint("-999999999999999999"));
}

TEST(string_toint, InvalidInput)
{
	ASSERT_EQ(0, string_toint("adbdfasdf"));
	ASSERT_EQ(0, string_toint("adfd233"));
	ASSERT_EQ(123, string_toint("123dfsadfdsf"));
}
 
int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


