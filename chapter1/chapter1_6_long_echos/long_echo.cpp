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
#include <sstream>
#include <vector>
#include <algorithm>

int long_echo_string_by_iter(const char *str)
{
	if (!str) {
		return -1;
	}

	int len = strlen(str);
	int max = 0;

	for (int i = 0; i < len; ++i) {
		int j;
		int c;
		
		//odd case
		c = 1;
		for (j = 0; i-j-1 >= 0 && i+j+1 < len; ++j) {
			if (str[i-j-1] != str[i+j+1]) {
				break;
			}
			c = 1+2*(j+1);
		}
		
		if (c > max) {
			max = c;
		}

		//even case
		c = 0;
		for (j = 0; i-j >= 0 && i+j+1 < len; ++j) {
			if (str[i-j] != str[i+j+1]) {
				break;
			}
			c = 2*(j+1);
		}
		if (c > max) {
			max = c;
		}
	}	

	return max;
}

/*
Manacher:
1. Insert '#' between the chars including the head and tail;
2. Insert '$' before head;
3. P[i] is the echo string len based on i; id is the center id, mx is the id+P[id];
    if mx > i, P[i] >= min(P[2*id-i], mx-i)
*/
int long_echo_string_by_manacher(const char *str)
{	
	if (!str) {
		return -1;
	}

	std::stringstream tmp;
	tmp << '$';
	while (*str) {
		tmp << '#';
		tmp << *str;
		++str;
	}
	tmp << '#';

	
	std::string ss = tmp.str();
	const char *cstr = ss.c_str();
	std::vector<int> p(ss.size(), 1);

	int mx = 0;
	int max = 1;
	int i;
	int id;
	int len = ss.size();

	for (i = 0; i < len; ++i) {
		if (mx > i) {
			p[i] = std::min(p[2*id-i], mx-i);
		} else {
			p[i] = 1;
		}

		while (cstr[i-p[i]] == cstr[i+p[i]]) {
			p[i]++;
		}

		if (p[i]+i > mx) {
			mx = p[i]+i;
			id = i;
		}

		if (p[i] > max) {
			max = p[i];
		}
	}

	return max-1;
}

