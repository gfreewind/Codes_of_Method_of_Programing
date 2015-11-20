#include <iostream>
#include "string_permutation.h"



int main(int argc, char **argv) 
{
	string_permutation_by_recursive("1");
	string_permutation_by_recursive("12");
	string_permutation_by_recursive("123");
	string_permutation_by_recursive("1234");

	string_permutation_by_promotion("1");
	string_permutation_by_promotion("12");
	string_permutation_by_promotion("123");
	string_permutation_by_promotion("1234");

	return 0;
}


