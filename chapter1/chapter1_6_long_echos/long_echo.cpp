/*
 * =====================================================================================
 *
 *       Filename:  long_echo.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/01/2015 06:38:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <cstring>

int long_echo_string_by_iter(const char *str)
{
	if (!str) {
		return -1;
	}

	int len = strlen(str);
	int max = 0;

	for (int i = 0; i < len; ++i) {
		int j;
		//odd case
		for (j = 0; i-j-1 >= 0 && i+j+1 < len; ++j) {
			if (str[i-j-1] != str[i+j+1]) {
				break;
			}
		}
		if (j > max) {
			max = j;
		}

		//even case
		for (j = 0; i-j >= 0 && i+j+1 < len; ++j) {
			if (str[i-j] != str[i+j+1]) {
				break;
			}
		}
		if (j > max) {
			max = j;
		}
	}	

	return max;
}

