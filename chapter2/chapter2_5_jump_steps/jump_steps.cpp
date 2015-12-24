/*
 * =====================================================================================
 *
 *       Filename:  jump_steps.cpp
 *
 *    Description:  
 *
 *        Version:  1.0
 *        Created:  12/24/2015 08:14:57 AM
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  YOUR NAME (), 
 *        Company:  
 *
 * =====================================================================================
 */
#include <vector>
#include <iostream>
#include <iterator>

static void _jump_steps_recursive(int steps, std::vector<int> &result);


static void print_result(std::vector<int> &result)
{
	for (auto it = result.begin(); it != result.end(); it++) {
		std::cout << *it << " ";
	}
	std::cout << std::endl;
}

static void _jump_two_steps(int steps, std::vector<int> &result)
{
	steps -= 2;
	result.push_back(2);
	_jump_steps_recursive(steps, result);
	result.pop_back();
}

static void _jump_one_step(int steps, std::vector<int> &result)
{
	--steps;
	result.push_back(1);
	_jump_steps_recursive(steps, result);
	result.pop_back();
}

static void _jump_steps_recursive(int steps, std::vector<int> &result)
{
	if (0 == steps) {
		print_result(result);
		return;
	}

	if (1 == steps) {
		_jump_one_step(steps, result);
	}
	else {
		_jump_one_step(steps, result);
		_jump_two_steps(steps, result);
	}
}

void jump_steps(int steps)
{
	std::vector<int> result;

	std::cout << "The method of jumpint steps " << steps << std::endl;	
	_jump_steps_recursive(steps, result);
}

