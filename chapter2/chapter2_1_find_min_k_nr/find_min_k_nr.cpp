/*
 * =====================================================================================
 *
 *       Filename:  find_min_k_nr.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/09/2015 03:09:06 PM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <algorithm>
#include <cstring>
#include <cassert>

int find_min_k_by_sort(int *array, int size, int k, int *result)
{
	assert(array&&result);

	if (k <= 0) {
		return 0;
	}

	std::sort(array, array+size);
	
	if (size >= k) {
		memcpy(result, array, k*sizeof(int));
		return k;
	} else {
		memcpy(result, array, size*sizeof(int));
		return size;
	}
}


