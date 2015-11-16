#include <cstring>
#include <cassert>

using namespace std;


char *brute_force_rotate_string(char *str, int rotate_len)
{
	assert(str);
	assert(rotate_len >= 0);

	int len = strlen(str);

	rotate_len %= len;

	for (int i = 0; i < rotate_len; ++i) {
		char t = str[0];
		for (int j = 1; j < len; ++j) {
			str[j-1] = str[j];
		}
		str[len-1] = t;
	}

	return str;
}

