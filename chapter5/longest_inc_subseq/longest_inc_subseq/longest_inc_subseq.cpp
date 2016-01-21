#include <cassert>

#include <deque>
#include <vector>
#include <iterator>
#include <memory>
#include <algorithm>

using std::vector;
using std::deque;

class lcs {
public:
	enum dir {
		UP,
		LEFT,
		LEFT_UP,
	};
	enum dir dir;
	int size;
};

void longest_common_subseq(int *a1, int len1, int *a2, int len2, deque<int> &subseq)
{
	lcs dp[100][100];

	subseq.clear();

	for (int i = 0; i <= len1; ++i) {
		dp[i][0].dir = lcs::UP;
		dp[i][0].size = 0;
	}

	for (int j = 0; j < len2; ++j) {
		dp[0][j].dir = lcs::UP;
		dp[0][j].size = 0;
	}

	for (int i = 1; i <= len1; ++i) {
		for (int j = 1; j <= len2; ++j) {
			if (a1[i - 1] == a2[j - 1]) {
				dp[i][j].size = dp[i - 1][j - 1].size + 1;
				dp[i][j].dir = lcs::LEFT_UP;
			}
			else {
				if (dp[i - 1][j].size >= dp[i][j - 1].size) {
					dp[i][j].size = dp[i - 1][j].size;
					dp[i][j].dir = lcs::UP;
				}
				else {
					dp[i][j].size = dp[i][j - 1].size;
					dp[i][j].dir = lcs::LEFT;
				}
			}
		}
	}

	std::deque<char> sub;
	lcs tmp = dp[len1][len2];
	while (tmp.size) {
		if (tmp.dir == lcs::LEFT_UP) {
			len1--;
			len2--;
			sub.push_front(a1[len1]);
		}
		else if (tmp.dir == lcs::LEFT) {
			len2--;
		}
		else if (tmp.dir == lcs::UP) {
			len1--;
		}
		else {
			assert(0);
		}
		tmp = dp[len1][len2];
	}

	for (auto it = sub.begin(); it != sub.end(); ++it) {
		subseq.push_back(*it);
	}
}

void longest_inc_subseq_by_common_sub(int *a, int size, deque<int> &ret)
{
	std::unique_ptr<int[]> p(new int[size]);

	memcpy(p.get(), a, sizeof(a[0])*size);

	std::sort(p.get(), p.get()+size);
	
	longest_common_subseq(a, size, p.get(), size, ret);
}


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