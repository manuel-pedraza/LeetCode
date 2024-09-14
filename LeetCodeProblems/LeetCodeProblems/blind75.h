#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include "structs.h"
#include "problemslist.h"

// Function List
std::string mergeAlternately(std::string word1, std::string word2);
std::string greatestCommonDivisorStrings(std::string str1, std::string str2);

// Wrappers
Information mergeAlternatelyWrapper(Information input);
Information greatestCommonDivisorStringsWrapper(Information input);

// Inits
ProblemManager mergeAlternatelyInit();
ProblemManager greatestCommonDivisorStringsInit();

// Main Init
void InitializeBlind75List();


extern ProblemList blind75list;

#endif