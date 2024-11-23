#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include <sstream>
#include "structs.h"
#include "problemslist.h"

// Function List
bool isVowel(char letter);
void showProblemInputs(std::vector<std::string> inputs);
void showHasPassed(bool passed);
void showAssertionResult(bool passed, std::string output, std::string expected);
void showAssertionResult(bool passed, bool output, bool expected);
void showAssertionIndexAndTotal(bool passed, int index, int total);
void showIndexAndTotal(int index, int total);
void showProblemDifficulty(Difficulty diff);

template<typename T>
std::string vectorToString(std::vector<T> vector) {
	std::ostringstream oss;


	if (!vector.empty())
	{
		oss << "[";

		int counter = 1;
		for (T e : vector) {
			oss << e;
			if (counter++ < vector.size())
				oss << ", ";
		}
		oss << "]";

		return oss.str();
	}

	return "";
}

template<typename T>
void showAssertionResult(bool passed, std::vector<T> output, std::vector<T> expected)
{
	if (typeid(T) == typeid(bool))
		std::cout << std::boolalpha;
	showAssertionResult(passed, vectorToString<T>(output), vectorToString<T>(expected));
}

#endif