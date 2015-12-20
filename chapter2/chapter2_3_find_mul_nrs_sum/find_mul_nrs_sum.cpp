/*
 * =====================================================================================
 *
 *       Filename:  find_mul_nrs_sum.cpp
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
#include <vector>
#include <iterator>

static void _print_result(std::vector<int> &result)
{
	for (auto it = result.begin(); it != result.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static void _find_two_nrs_sum_by_endpoints(int *array, int size, int sum, std::vector<int> &result)
{
	int *head = array;
	int *tail = array+size;

	--tail;
	
	int s;
	while (head < tail) {			
		s = *head + *tail;
		if (s > sum) {
			--tail;
		} else if (s < sum) {
			++head;
		} else {
			result.push_back(*head);
			result.push_back(*tail);
			_print_result(result);
			//Remove the last two.
			result.pop_back();
			result.pop_back();
			++head;
			--tail;
		}
	}	
}

static void _find_mul_nrs_sum_by_recursive(int *array, int size, int count, int sum, std::vector<int> &result)
{
	if (size <= 1) {
		return;
	}

	if (2 == count) {
		_find_two_nrs_sum_by_endpoints(array, size, sum, result);
		return;
	}

	for (int i = 0; i < size; ++i) {
		if (array[i] < sum) {
			std::swap(array[i], array[size-1]);
			result.push_back(array[size-1]);
			_find_mul_nrs_sum_by_recursive(array, size-1, count-1, sum-array[size-1], result);
			result.pop_back();
			std::swap(array[i], array[size-1]);
		}
	}
}


void find_mul_nrs_sum_by_recursive(int n, int sum)
{
	int array[n];

	for (int i = 0; i <n; ++i) {
		array[i] = i+1;
	}

	for (int i = 2; i < n-1; ++i) {
		std::vector<int> result;
		_find_mul_nrs_sum_by_recursive(array, n, i, sum, result);
	}
}

static void _sum_of_k_nrs(int cur, int k, int left, int m, std::vector<bool> x)
{
	x[k] = true;
	if (cur + k == m) {
		// That's we expected
		for (int i = 0; i <= k; ++i) {
			if (x[i]) {
				std::cout << i << " ";
			}
		}
		std::cout << std::endl;
	} else {
		if (cur+k+(k+1) <= m) {
			// Selected k, and go on
			_sum_of_k_nrs(cur+k, k+1, left-k, m, x);
		}
		if ((cur+(left-k) >= m) && (cur + (k+1) <= m)) {
			// Don't select k, and go on
			x[k] = false;
			_sum_of_k_nrs(cur, k+1, left-k, m, x);
		}
		
	}
}

void find_mul_nrs_sum_by_recusive2(int n, int m)
{
	std::vector<bool> x(n+1);
	int sum = (n+1)*n/2;

	if (1 > m || sum < m) {
		return;
	}

	_sum_of_k_nrs(0, 1, sum, m, x);
}



