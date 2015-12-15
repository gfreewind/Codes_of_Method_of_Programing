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

int find_min_k_nrs_by_sort(int *array, int size, int k, int *result)
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
	j = size-2;

	//swap array[size-1] and array[k]
	std::swap(array[size-1], array[k]);
	while (1) {
		while (array[i] < array[size-1] && i <= j) {
			i++;
		}

		while (array[j] >= array[size-1] && j > i) {
			j--;
		}

		if (i >= j) {
			break;
		}

		std::swap(array[i], array[j]);
		++i;
		--j;
	}
	std::swap(array[size-1], array[i]);

	return i+1;
}

int find_min_k_nrs_by_partition(int *array, int size, int k, int *result)
{
	assert(array && result);

	if (k <= 0) {
		return 0;
	}

	if (k >= size) {
		memcpy(result, array, size*sizeof(*array));
		return size;
	}

	int *a = array;
	int s = size;
	int c = k;
	int ret;

	while (1) {
		if (s > 2) {
			ret = partion(a, s, c);
			if (ret == c) {
				// from a[0] to a[ret] are the smallest k numbers
				break;
			} else if (ret > c) {
				// continue partion
				s = ret;
			} else {
				// a[0] .. a[ret] are the results. we need to find others
				a = a + ret;
				s = s-ret;
				c = c - ret;
			}
		} else if (s == 2) {
			if (a[0] >= a[1]) {
				std::swap(a[0], a[1]);
			}
			break;
		} else {
			break;
		}
	}
 
	//Now array[0]~array[k] are smallest 
	memcpy(result, array, k*sizeof(*array));
	return k;
}

int find_min_k_nrs_by_insert(int *array, int size, int k, int *result)
{
	assert(array && result);

	if (k <= 0) {
		return 0;
	}

	if (k >= size) {
		memcpy(result, array, size*sizeof(*array));
		return size;
	}

	for (int i = k; i < size; ++i) {
		int max = 0;
		
		for (int j = 1; j < k; ++j) {
			if (array[j] > array[max]) {
				max = j;
			}
		}

		if (array[max] > array[i]) {
			std::swap(array[max], array[i]);
		}
	}

	memcpy(result, array, k*sizeof(*array));
	return k;
}

/*
Current heap is right, just insert new one to tail,then compare it
Left child: 2i+1;
Right child: 2i+2;
*/
static void max_heapify(int *array, int node, int max_size)
{
	int left, right, largest;

	do {
		largest = node;
		left = 2*node+1;
		if (array[left] > array[largest] && left < max_size) {
			largest = left;
		}
		right = 2*node+2;
		if (array[right] > array[largest] && right < max_size) {
			largest = right;
		}
		if (largest == node) {
			// It is on right pos;
			break;
		} else {
			std::swap(array[largest], array[node]);
			node = largest;
		}
	} while (1);
}

static void build_max_heap(int *array, int size)
{
	if (size <= 1) {
		return;
	}

	for (int i = (size-1)/2; i >= 0; --i) {
		max_heapify(array, i, size);
	}
}

void heap_sort(int *array, int size)
{
	if (1 == size) {
		return;
	}

	build_max_heap(array, size);

	for (int i = size-1; i > 0; --i) {
		std::swap(array[0], array[i]);
		max_heapify(array, 0, i);
	}
}


int find_min_k_nrs_by_heap_sort(int *array, int size, int k, int *result)
{
	
	assert(array && result);

	if (k <= 0) {
		return 0;
	}

	if (k >= size) {
		memcpy(result, array, size*sizeof(*array));
		return size;
	}

	
	build_max_heap(array, k);

	for (int i = k; i < size; ++i) {
		if (array[i] < array[0]) {
			std::swap(array[i], array[0]);
			max_heapify(array, 0, k);
		}
	}

	memcpy(result, array, k*sizeof(*array));

	return k;
}

