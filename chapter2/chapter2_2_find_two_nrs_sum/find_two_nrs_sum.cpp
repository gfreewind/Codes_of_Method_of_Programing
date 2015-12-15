/*
 * =====================================================================================
 *
 *       Filename:  find_two_nrs_sum.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/16/2015 04:10:28 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <cassert>
#include <iostream>
#include <algorithm>

void find_two_nrs_sum_by_endpoints(int *array, int size, int sum)
{
	std::sort(array, array+size);

	int *head = array;
	int *tail = array+(size-1);
	int s;

	while (head < tail) {			
		s = *head + *tail;
		if (s > sum) {
			--tail;
		} else if (s < sum) {
			++head;
		} else {
			std::cout << *head << " + " << *tail;
			std::cout << " = " << sum << std::endl;
			++head;
			--tail;
		}
		
	}	
}


