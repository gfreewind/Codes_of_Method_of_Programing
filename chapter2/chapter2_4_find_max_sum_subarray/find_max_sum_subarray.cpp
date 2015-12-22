#include <vector>
#include <cassert>
#include <iostream>

void find_max_sum_subarray(int *array, int size)
{
	if (!array || 0 == size) {
		return;
	}

	int sum = array[0];
	int cur_sum = array[0];
	std::vector<int> sum_vec;
	std::vector<int> cur_vec;
	sum_vec.push_back(array[0]);
	cur_vec.push_back(array[0]);

	for (int i = 1; i < size; ++i) {
		if (cur_sum >= 0) {
			cur_sum += array[i];
			cur_vec.push_back(array[i]);
		} else {
			cur_sum = array[i];
			cur_vec.clear();
			cur_vec.push_back(array[i]);
		}

		if (cur_sum > sum) {
			sum = cur_sum;
			sum_vec = cur_vec;
		}
	}

	std::cout << "Max sum: " << sum << std::endl;
	for (auto it = sum_vec.begin(); it != sum_vec.end(); ++it) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

