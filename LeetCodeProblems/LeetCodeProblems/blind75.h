#ifndef FUNCTIONS_H_INCLUDED
#define FUNCTIONS_H_INCLUDED

#include <vector>
#include "structs.h"
#include "problemslist.h"

// Function List
std::string mergeAlternately(std::string word1, std::string word2);

// Wrappers
Information mergeAlternatelyWrapper(Information input);

// Inits
ProblemManager mergeAlternatelyInit();

// Main Init
void InitializeBlind75List();


extern ProblemList blind75list;

#endif