#include <deque>
#include <vector>
#include <iterator>

using std::vector;
using std::deque;

void longest_inc_subseq_by_dp(int *a, int size, deque<int> &ret)
{
	vector<deque<int>> liss;
	deque<int> lis;

	for (int i = 0; i < size; ++i) {
		lis.push_back(a[i]);

		for (auto it = liss.begin(); it != liss.end(); ++it) {
			if (a[i] > it->back() && it->size() >= lis.size()) {
				lis.clear();
				lis = *it;
				lis.push_back(a[i]);
			}
		}

		liss.push_back(lis);
		lis.clear();
	}

	for (auto it = liss.begin(); it != liss.end(); it++) {
		if (it->size() > ret.size()) {
			ret = *it;
		}
	}
}