/*
 * =====================================================================================
 *
 *       Filename:  string_toint.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2015 09:55:22 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */

#include <cassert>
#include <limits>

int string_toint(const char* str)
{
	int last = 0;
	int result = 0;
	bool negative = false;

	assert(str);

	if ('-' == *str) {
		negative = true;
		++str;
	}

	while (*str) {
		unsigned char v;
	
		if ('0' <= *str && *str <= '9') {
			v = *str-'0';
			result = result*10+v;
			if (result < last) {
				if (negative) {
					return -std::numeric_limits<int>::max();
				} else {
					return std::numeric_limits<int>::max();
				}
			} else {
				last = result;
			}
		} else {
			break;
		}
		++str;
	}

	if (negative) {
		result = -result;
	}

	return result;
}

