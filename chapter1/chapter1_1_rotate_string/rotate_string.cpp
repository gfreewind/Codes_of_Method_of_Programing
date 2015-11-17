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

	if (!str) {
		return NULL;
	}

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

static void reverse_string(char *str, int len)
{
	for (int i = 0; i < len/2; ++i) {
		char t = str[i];
		str[i] = str[len-1-i];
		str[len-1-i] = t;
	}
}

char *three_reverse_rotate_string(char *str, int rotate_len)
{

	if (!str) {
		return NULL;
	}

	int len = strlen(str);

	rotate_len %= len;

	if (rotate_len > 0) {
		reverse_string(str, rotate_len);
		reverse_string(str+rotate_len, len-rotate_len);
		reverse_string(str, len);
	} else {
		rotate_len = len+rotate_len;
		reverse_string(str, rotate_len);
		reverse_string(str+rotate_len, len-rotate_len);
		reverse_string(str, len);
	}

	return str;
}

char *rotate_string_by_word(char *str)
{
	if (!str) {
		return NULL;
	}

	int len = strlen(str);

	char *start, *end;

	start = end = str;

	while (start < str+len) {
		while (*end != ' ' && *end != '\0') {
			++end;
		}
		reverse_string(start, end-start);
		++end;
		start = end;
	}
	
	reverse_string(str, len);

	return str;
}


