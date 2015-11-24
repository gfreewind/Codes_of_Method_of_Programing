/*
 * =====================================================================================
 *
 *       Filename:  echo_string.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  11/24/2015 10:23:55 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <cassert>

bool is_echo_string_by_endpoints(const char *str)
{
	if (!str || !str[0]) {
		return false;
	}

	const char *head = str;
	const char *tail = str;

	// Move to tail
	while (*(tail+1)) {
		++tail;
	}

	/* Only one char */
	if (tail - head == 0) {
		return false;
	}

	while (tail > head) {
		if (*tail != *head) {
			return false;
		}
		--tail;
		++head;
	}

	return true;
}
