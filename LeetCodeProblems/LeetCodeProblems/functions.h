#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include "structs.h"
#include "problemslist.h"

// Function List
void showAssertionResult(bool passed, std::string output, std::string expected);
void showAssertionResult(bool passed, bool output, bool expected);
void showAssertionIndexAndTotal(bool passed, int index, int total);
void showIndexAndTotal(int index, int total);
void showProblemDifficulty(Difficulty diff);

template<typename T>
void showAssertionResult(bool passed, std::vector<T> output, std::vector<T> expected)
{
	if (passed) {
		std::cout << "\033[32m - PASSED" << std::endl;
	}
	else {
		std::cout << "\033[31m - FAILED" << std::endl;
	}


	if (typeid(T) == typeid(bool))
		std::cout << std::boolalpha;

	int counter = 1;
	std::cout << "	\033[33mExpected: \033[37m[";

	for (T e : expected) {
		std::cout << e ;
		if(counter < expected.size())
			std::cout << ", ";
		counter++;
	}

	std::cout << "]\033[37m | ";
	std::cout << "\033[34mReceived: \033[37m[";

	counter = 1;
	for (T o : output) {
		std::cout << o;
		if (counter < output.size())
			std::cout << ", ";
		counter++;
	}
		

	std::cout << "]" << std::endl;

}

#endif