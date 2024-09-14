#include <iostream>
#include <vector>
#include <unordered_map>

#include "highfrequencycompanylist.h"
#include "blind75.h"


int main() {

	InitializeHighFreqList();
	InitializeBlind75List();
	std::cout << "\033[37m";
	//std::cout << (highfreqlist.SolveByName("Two Sum") ? "PASSED" : "FAILED") << std::endl;
	//std::cout << (highfreqlist.SolveByName("Add Two Numbers") ? "PASSED" : "FAILED") << std::endl;
	//std::cout << (blind75list.SolveByName("Merge Strings Alternately") ? "PASSED" : "FAILED") << std::endl;
	std::cout <<
		(blind75list.SolveByName("Greatest Common Divisor of Strings") ? "All tests have \033[34mPASSED"
			: "One test has \033[31mFAILED")
		<< "\033[37m" << std::endl;


	//p1.SetInputs(Information(std::vector<Property*>(pvalue1, pvalue2)));
	//Information i1();

	//Problem<std::vector<int>, std::vector<std::vector<int, int>> twoSum("hello", "there", twoSum);

	//p1.SetName("Hello there");
}