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

static int partion(int *array, int size, int k)
{
	int i, j;
	i = 0; 
	j = size-1;
	while (1) {
		while (array[i]<=array[k] && i < k) {
			i++;
		}

		while (array[j]>=array[k] && j > k) {
			j--;
		}

		if (i < j) {
			if (i < k && j > k) {
				std::swap(array[i], array[j]);
				i++;
				j--;
			} else if (i < k) {
				std::swap(array[i], array[k]);
				i = 0;
				j = size-1;
			} else if (j > k) {
				std::swap(array[j], array[k]);
				i = 0;
				j = size-1;
			}
			continue;
		}
		
		break;
	}

	return k;
}

int find_min_k_by_partition(int *array, int size, int k, int *result)
{
	assert(array && result);

	if (k <= 0) {
		return 0;
	}

	if (k >= size) {
		memcpy(result, array, size*sizeof(*array));
		return size;
	}

	partion(array, size, k);
 
	//Now array[0]~array[k] are smallest 
	memcpy(result, array, k*sizeof(*array));
	return k;
}

