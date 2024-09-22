#include "functions.h"
#include <stdlib.h>
#include <conio.h>
#include <stdio.h>
#include <Windows.h>
//https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
//https://stackoverflow.com/questions/9965710/how-to-change-text-and-background-color

void showAssertionResult(bool passed, std::string output, std::string expected)
{
	if (passed) {
		std::cout << "\033[32m - PASSED" << std::endl;
	}
	else {
		std::cout << "\033[31m - FAILED" << std::endl;
	}
	std::cout << "	\033[33mExpected: \033[37m";
	std::cout << expected << "\033[37m | ";
	std::cout << "\033[34mReceived: \033[37m";
	std::cout << output << std::endl;

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
	switch (diff){
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
