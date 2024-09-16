#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include "structs.h"
#include "problemslist.h"

// Function List
void showAssertionResult(bool passed, std::string output, std::string expected);
void showAssertionIndexAndTotal(bool passed, int index, int total);
void showIndexAndTotal(int index, int total);
void showProblemDifficulty(Difficulty diff);

#endif