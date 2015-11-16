#include <cassert>
#include <cstring>
#include <algorithm>

/*
Check if all of the characters of string in pattern.
*/

bool brute_force_contain_chars(const char *pattern, const char *sub_string)
{

	if (!(pattern && sub_string)) {
		return false;
	}


	while (*sub_string) {
		const char *p = pattern;

		while (*p) {
			if (*sub_string == *p) {
				break;
			}
			++p;
		}

		
		if (!*p) {
			// Not found
			break;
		}
		sub_string++;
	}

	return !*sub_string;
}

bool char_table_contain_chars(const char *pattern, const char *sub_string)
{
	char pattern_tab[256] = { 0 };


	if (!(pattern && sub_string)) {
		return false;
	}

	while (*pattern) {
		unsigned char value = *pattern;
		pattern_tab[value] = true;
		++pattern;
	}

	while (*sub_string) {
		unsigned char value = *sub_string;
		if (!pattern_tab[value]) {
			return false;
		}
		++sub_string;
	}
	
	return true;
}

/*
Just a example
*/
bool prime_check_contain_chars(const char *pattern, const char *sub_string)
{
	unsigned int prime[] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 53,
							59, 61, 67, 71, 73, 79, 83, 89, 91, 97};
	unsigned long pattern_value = 1;

	if (!(pattern && sub_string)) {
		return false;
	}

	while (*pattern) {
		unsigned char value = *pattern-'a';

		assert(value < sizeof(prime)/sizeof(prime[0]));
		
		pattern_value *= prime[value];
		++pattern;
	}

	while (*sub_string) {
		unsigned char value = *sub_string-'a';

		assert(value < sizeof(prime)/sizeof(prime[0])); 

		if (pattern_value%prime[value] != 0) {
			return false;
		}
		sub_string++;
	}

	return true;
}

bool sort_contain_chars(const char *pattern, const char *sub_string)
{
#define TMP_BUF_LEN			(64)
	if (!(pattern && sub_string)) {
		return false;
	}


	int pattern_len = strlen(pattern);
	int sub_len = strlen(sub_string);

	if (!(pattern_len < TMP_BUF_LEN && sub_len < TMP_BUF_LEN)) {
		return false;
	}

	char tmp_pat[64];
	char tmp_sub[64];

	strcpy(tmp_pat, pattern);
	strcpy(tmp_sub, sub_string);

	std::sort(tmp_pat, tmp_pat+pattern_len);
	std::sort(tmp_sub, tmp_sub+sub_len);

	while (*sub_string) {
		while (*pattern) {
			if (*sub_string == *pattern) {
				break;
			} else if (*pattern < *sub_string) {
				++pattern;
				continue;
			} else {
				return false;
			}
		}

		if ('\0' == *pattern) {
			return false;
		}

		++sub_string;
	}

	return true;
}

bool bitmap_check_contain_chars(const char *pattern, const char *sub_string)
{
	if (!(pattern && sub_string)) {
		return false;
	}

	unsigned long pattern_sigs = 0;

	while (*pattern) {
		unsigned char value = *pattern;
		value = value - 'a';

		assert(value < sizeof(pattern_sigs)*8);

		pattern_sigs |= (1<<value);

		++pattern;
	}

	while (*sub_string) {
		unsigned char value = *sub_string;
		value = value - 'a';

		assert(value < sizeof(pattern_sigs)*8);

		if (!(pattern_sigs & (1 << value))) {
			return false;
		}
		++sub_string;
	}

	return true;
}


