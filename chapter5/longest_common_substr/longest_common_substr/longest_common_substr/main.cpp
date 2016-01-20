#include "stdafx.h"
#include <iostream>
#include <string>

#include "longest_common_substr.h"

using namespace std;

int main()
{
	char *s1 = "13455";
	char *s2 = "245576";
	std::string sub;

	longest_common_substr(s1, s2, sub);
	cout << "The longest substr of " << s1 << " and " << s2 << " is " << sub << endl;

	s1 = "243576";
	longest_common_substr(s1, s2, sub);
	cout << "The longest substr of " << s1 << " and " << s2 << " is " << sub << endl;

    return 0;
}

