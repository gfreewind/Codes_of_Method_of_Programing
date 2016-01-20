#include <string>

void longest_common_substr(char *s1, char *s2, std::string &substr)
{
	substr = "";

	char *str;
	char *p;

	if (strlen(s1) >= strlen(s2)) {
		str = s1;
		p = s2;
	}
	else {
		str = s2;
		p = s1;
	}

	std::string max;
	std::string tmp;
	
	while (*p) {
		char *c = str;
		while (*c) {
			if (*c == *p) {
				int i = 0;
				do {
					tmp.push_back(*(p+i));
					++i;
				} while (*(c + i) == *(p + i));

				if (tmp.length() > max.length()) {
					max = tmp;
				}
				tmp.clear();

			}
			++c;
		}

		++p;
	}

	substr = max;
}
