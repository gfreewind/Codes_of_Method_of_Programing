#include <iostream>

#include <gtest/gtest.h>

#include "contain_chars.h"


TEST(brute_force_contain_chars, Normal)
{
	ASSERT_TRUE(brute_force_contain_chars("abcdef", "adf"));
	ASSERT_FALSE(brute_force_contain_chars("abcdef", "addif"));
	ASSERT_TRUE(brute_force_contain_chars("abcdef", "aabbcc"));
}

TEST(brute_force_contain_chars, Unnormal)
{
	ASSERT_TRUE(brute_force_contain_chars("abc", ""));
	ASSERT_TRUE(brute_force_contain_chars("", ""));
	ASSERT_FALSE(brute_force_contain_chars("", "abc"));
	ASSERT_FALSE(brute_force_contain_chars("abc", NULL));
	ASSERT_FALSE(brute_force_contain_chars(NULL, NULL));
}

TEST(char_table_contain_chars, Normal)
{
	ASSERT_TRUE(char_table_contain_chars("abcdef", "adf"));
	ASSERT_FALSE(char_table_contain_chars("abcdef", "addif"));
	ASSERT_TRUE(char_table_contain_chars("abcdef", "aabbcc"));
}

TEST(char_table_contain_chars, Unnormal)
{
	ASSERT_TRUE(char_table_contain_chars("abc", ""));
	ASSERT_TRUE(char_table_contain_chars("", ""));
	ASSERT_FALSE(char_table_contain_chars("", "abc"));
	ASSERT_FALSE(char_table_contain_chars("abc", NULL));
	ASSERT_FALSE(char_table_contain_chars(NULL, NULL));
}

TEST(prime_check_contain_chars, Normal)
{
	ASSERT_TRUE(prime_check_contain_chars("abcdef", "adf"));
	ASSERT_FALSE(prime_check_contain_chars("abcdef", "addif"));
	ASSERT_TRUE(prime_check_contain_chars("abcdef", "aabbcc"));
}

TEST(prime_check_contain_chars, Unnormal)
{
	ASSERT_TRUE(prime_check_contain_chars("abc", ""));
	ASSERT_TRUE(prime_check_contain_chars("", ""));
	ASSERT_FALSE(prime_check_contain_chars("", "abc"));
	ASSERT_FALSE(prime_check_contain_chars("abc", NULL));
	ASSERT_FALSE(prime_check_contain_chars(NULL, NULL));
}

TEST(sort_contain_chars, Normal)
{
	ASSERT_TRUE(sort_contain_chars("abcdef", "adf"));
	ASSERT_FALSE(sort_contain_chars("abcdef", "addif"));
	ASSERT_TRUE(sort_contain_chars("abcdef", "aabbcc"));
}

TEST(sort_contain_chars, Unnormal)
{
	ASSERT_TRUE(sort_contain_chars("abc", ""));
	ASSERT_TRUE(sort_contain_chars("", ""));
	ASSERT_FALSE(sort_contain_chars("", "abc"));
	ASSERT_FALSE(sort_contain_chars("abc", NULL));
	ASSERT_FALSE(sort_contain_chars(NULL, NULL));
}

TEST(bitmap_check_contain_chars, Normal)
{
	ASSERT_TRUE(bitmap_check_contain_chars("abcdef", "adf"));
	ASSERT_FALSE(bitmap_check_contain_chars("abcdef", "addif"));
	ASSERT_TRUE(bitmap_check_contain_chars("abcdef", "aabbcc"));
}

TEST(bitmap_check_contain_chars, Unnormal)
{
	ASSERT_TRUE(bitmap_check_contain_chars("abc", ""));
	ASSERT_TRUE(bitmap_check_contain_chars("", ""));
	ASSERT_FALSE(bitmap_check_contain_chars("", "abc"));
	ASSERT_FALSE(bitmap_check_contain_chars("abc", NULL));
	ASSERT_FALSE(bitmap_check_contain_chars(NULL, NULL));
}

 
int main(int argc, char **argv) 
{
	testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}


