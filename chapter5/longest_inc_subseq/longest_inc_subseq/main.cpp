// main.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <iterator>

#include "longest_inc_subseq.h"

using namespace std;

static void print_result(deque<int> &ret)
{
	for (auto it = ret.begin(); it != ret.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	int a1[] = { 5,6,7,1,2,8 };
	deque<int> ret;

	longest_inc_subseq_by_dp(a1, sizeof(a1) / sizeof(a1[0]), ret);
	print_result(ret);

	int a2[] = { 5,6,1,2,3,4,2 };
	ret.clear();
	longest_inc_subseq_by_dp(a2, sizeof(a2) / sizeof(a2[0]), ret);
	print_result(ret);

	int a3[] = { 1,2,3,9,10,11,12,4,5,6,7,8};
	ret.clear();
	longest_inc_subseq_by_dp(a3, sizeof(a3) / sizeof(a3[0]), ret);
	print_result(ret);

    return 0;
}

