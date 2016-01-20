// main.cpp: 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>

#include "interleave_strings.h"

using namespace std;

int main()
{
	char *s1 = "aabcc";
	char *s2 = "dbbca";
	char *s3 = "aadbbcbcac";

	if (is_interleave_string_by_recursive(s1, s2, s3)) {
		cout << "Recursive: True" << endl;
	}
	else {
		cout << "Recursive: False" << endl;
	}

	if (is_interleave_string_by_dp(s1, s2, s3)) {
		cout << "DP: True" << endl;
	}
	else {
		cout << "DP: False" << endl;
	}

	s1 = "aabcc";
	s2 = "dbbca";
	s3 = "accabdbbca";

	if (is_interleave_string_by_recursive(s1, s2, s3)) {
		cout << "Recursive: True" << endl;
	}
	else {
		cout << "Recursive: False" << endl;
	}

	if (is_interleave_string_by_dp(s1, s2, s3)) {
		cout << "DP: True" << endl;
	}
	else {
		cout << "DP: False" << endl;
	}


	return 0;
}

