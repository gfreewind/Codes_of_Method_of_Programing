/*
 * =====================================================================================
 *
 *       Filename:  three_flags_sort.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/26/2015 02:38:04 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <algorithm>


void three_flags_sort_by_three_pointers(int *array, int size)
{
	if (!(array && size)) {
		return;
	}

	int *head = array;
	int *tail = array+size-1;
	int *current = array;

	while (current <= tail) {
		if (0 == *current) {
			std::swap(*head, *current);
			++head;
			//Because current starts from 0, so could increase one
			++current;
		} else if (1 == *current) {
			++current;
		} else if (2 == *current) {
			std::swap(*tail, *current);
			--tail;
		}
	}
}
