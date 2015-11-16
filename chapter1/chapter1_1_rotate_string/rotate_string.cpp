#include <cstring>
#include <cassert>

using namespace std;

static void left_move_string_one_chr(char *str, int len)
{
	char t = str[0];

	for (int i = 1; i < len; ++i) {
		str[i-1] = str[i];
	}

	str[len-1] = t;
}

static void right_move_string_one_chr(char *str, int len)
{
	char t = str[len-1];

	for (int i = len-1; i > 0; --i) {
		str[i] = str[i-1];
	}

	str[0] = t;
}

char *brute_force_rotate_string(char *str, int rotate_len)
{
	assert(str);

	int len = strlen(str);

	rotate_len %= len;


	if (rotate_len >= 0) {
		for (int i = 0; i < rotate_len; ++i) {
			left_move_string_one_chr(str, len);
		}
	} else {
		rotate_len = -rotate_len;
		for (int i = 0; i < rotate_len; ++i) {
			right_move_string_one_chr(str, len);
		}
	}

	return str;
}

