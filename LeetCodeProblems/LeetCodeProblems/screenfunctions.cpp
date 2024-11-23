#include "screenfunctions.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
#include "functions.h"

void ClearSreen()
{
#if defined _WIN32
	system("cls");
	//clrscr(); // including header file : conio.h
#elif defined (__LINUX__) || defined(__gnu_linux__) || defined(__linux__)
	system("clear");
	//std::cout<< u8"\033[2J\033[1;1H"; //Using ANSI Escape Sequences 
#elif defined (__APPLE__)
	system("clear");
#endif
}

void showMainMenu()
{
	std::cout << "Lists of problems:" << std::endl;
	int counter = 1;
	for (ProblemList* pl : ProblemList::allLists) {
		std::cout << "	" << counter++ << ". " << pl->GetListName() << std::endl;
	}

}

void showProblemManagerList()
{

}

void showProblemResults()
{

}

void showProblemInputs(std::vector<std::string> inputs)
{
	std::cout << " | Inputs: ";

	int counter = 1;
	for (std::string i : inputs) {
		std::cout << i;
		if (counter++ < inputs.size())
			std::cout << ", ";
	}

	std::cout << " |";
}

void showHasPassed(bool passed)
{
	std::cout << std::endl << "	Status:";
	if (passed) {
		std::cout << "\033[32m - PASSED -";
	}
	else {
		std::cout << "\033[31m - FAILED -";
	}
}

void showAssertionResult(bool passed, std::string output, std::string expected)
{
	std::cout << std::endl;
	std::cout << "	\033[33mExpected: \033[37m";
	std::cout << expected << "\033[37m" << std::endl;
	std::cout << "	\033[34mReceived: \033[37m";
	std::cout << output << std::endl;

}

void showAssertionResult(bool passed, bool output, bool expected)
{

	const std::string out = output ? "true" : "false";
	const std::string exp = expected ? "true" : "false";

	showAssertionResult(passed, out, exp);
}


void showAssertionIndexAndTotal(bool passed, int index, int total)
{
	std::cout << "	" << index + 1 << "/" << total;
}

void showIndexAndTotal(int index, int total)
{
	std::cout << "	" << index + 1 << "/" << total;
}

void showProblemDifficulty(Difficulty diff)
{
	switch (diff) {
	case Difficulty::Easy:
		std::cout << " \033[42m\033[30mEasy";
		break;
	case Difficulty::Medium:
		std::cout << " \033[43m\033[30mMedium";
		break;
	case Difficulty::Hard:
		std::cout << " \033[41m\033[30mEasy";
		break;
	}

	std::cout << "\033[49m\033[37m ";
}
