#ifndef BLIND75_H_INCLUDED
#define BLIND75_H_INCLUDED

#include <vector>
#include "structs.h"
#include "problemslist.h"

// Function List
std::string mergeAlternately(std::string word1, std::string word2);
std::string greatestCommonDivisorStrings(std::string str1, std::string str2);
std::vector<bool> kidsWithTheGreatestNumberOfCandies(std::vector<int>& candies, int extraCandies);
bool canPlaceFlowers(std::vector<int>& flowerbed, int flowersToBePlanted);

// Wrappers
Information mergeAlternatelyWrapper(Information input);
Information greatestCommonDivisorStringsWrapper(Information input);
Information kidsWithTheGreatestNumberOfCandiesWrapper(Information input);
Information canPlaceFlowersWrapper(Information input);

// Inits
ProblemManager mergeAlternatelyInit();
ProblemManager greatestCommonDivisorStringsInit();
ProblemManager kidsWithTheGreatestNumberOfCandiesInit();
ProblemManager canPlaceFlowersInit();

// Main Init
void InitializeBlind75List();

extern ProblemList blind75list;

#endif // !BLIND75