/*
 * =====================================================================================
 *
 *       Filename:  string_permutation.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/17/2015 08:30:04 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <cassert>
#include <cstring>
#include <string>
#include <algorithm>
#include <iterator>
#include <iostream>

static void _string_permutation_by_recusive(std::string &ss, char *str, int len, int &count)
{
	if (len == 1) {
		std::cout << ss << std::endl;
		++count;
		return;
	}

	_string_permutation_by_recusive(ss, str+1, len-1, count);
	for (int i = 0; i < len-1; ++i) {
		std::swap(str[0], str[i+1]);
		_string_permutation_by_recusive(ss, str+1, len-1, count);
		std::swap(str[0], str[i+1]);
	}
}

void string_permutation_by_recursive(const char *str)
{
	std::string ss = str;
	int count = 0;

	_string_permutation_by_recusive(ss, const_cast<char*>(ss.c_str()), ss.length(), count);

	std::cout << "There are " << count << " permutation of " << str << std::endl;
}

static bool generate_next_string_promotion(char *str, int len)
{
	int i;

	if (len <= 1) {
		return false;
	}

	// Find the most right pos which is bigger than former
	for (i = len-2; i >= 0; --i) {
		if (str[i] < str[i+1]) {
			break;
		}
	}

	if (i < 0) {
		return false;
	}

	int k;
	// Find the first one which is bigger than str[i]
	for (k = len-1; k > i; --k) {
		if (str[k] > str[i]) {
			break;
		}
	}

	if (k == i) {
		return false;
	}

	std::swap(str[i], str[k]);
	std::reverse(str+i+1, str+len);

	return true;

}

void string_permutation_by_promotion(const char *str)
{
	std::string ss = str;
	int count = 0;

	std::sort(ss.begin(), ss.end());

	do {
		std::cout << ss << std::endl;
		++count;
	} while (generate_next_string_promotion(const_cast<char*>(ss.c_str()), ss.length()));

	std::cout << "There are " << count << " permutation of " << str << std::endl;
}


