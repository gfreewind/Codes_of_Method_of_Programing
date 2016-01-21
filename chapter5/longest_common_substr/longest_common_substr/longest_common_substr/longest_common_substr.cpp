#include <cstring>
#include <cassert>

#include <memory>
#include <string>
#include <deque>
#include <iterator>

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

void longest_common_substr(char *s1, char *s2, std::string &substr)
{
	int len1 = strlen(s1);
	int len2 = strlen(s2);
	lcs dp[100][100];

	substr.clear();

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
			if (s1[i - 1] == s2[j - 1]) {
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
			sub.push_front(s1[len1]);
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
		substr.push_back(*it);
	}
}
