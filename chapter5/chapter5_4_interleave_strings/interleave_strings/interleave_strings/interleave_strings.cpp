#include "stdafx.h"

#include <cstring>

static bool _is_interleave_string_recursive(char *s1, char *s2, char *s3)
{
	// all strings reach end
	if (*s1 == '\0'&& *s2 == '\0' && *s3 == '\0') {
		return true;
	}

	if (*s3 == '\0') {
		return false;
	}

	if (*s1 == *s3) {
		if (_is_interleave_string_recursive(s1 + 1, s2, s3 + 1)) {
			return true;
		}
	}

	if (*s2 == *s3) {
		if (_is_interleave_string_recursive(s1, s2 + 1, s3 + 1)) {
			return true;
		}
	}

	return false;
}

bool is_interleave_string_by_recursive(char *s1, char *s2, char *s3)
{
	if (strlen(s1) + strlen(s2) != strlen(s3)) {
		return false;
	}

	return _is_interleave_string_recursive(s1, s2, s3);
}

bool is_interleave_string_by_dp(char *s1, char *s2, char *s3)
{
	int n = strlen(s1);
	int m = strlen(s2);
	int s = strlen(s3);

	if (n + m != s) {
		return false;
	}

	/*
	Just for test, so set dp as [100][100]
	*/
	bool dp[100][100] = { false };
	dp[0][0] = true;

	for (int i = 0; i <= n; ++i) {
		for (int j = 0; j <= m; ++j) {
			if (0 == i && 0 == j) {
				continue;
			}

			if ((i - 1 >= 0 && dp[i-1][j] && s1[i-1] == s3[i+j-1]) ||
				(j -1 >= 0 && dp[i][j-1] && s2[j-1] == s3[i+j-1])) {
				dp[i][j] = true;
			}
		}
	}

	return dp[n][m];

}
