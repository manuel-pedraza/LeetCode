#ifndef HIGH_FREQUENCY_COMPANY_LIST_H_INCLUDED
#define HIGH_FREQUENCY_COMPANY_LIST_H_INCLUDED

#include <vector>
#include "structs.h"
#include "problemslist.h"

// Initializer
void InitializeHighFreqList();

// Function List
std::vector<int> twoSum(std::vector<int>& nums, int target);
ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);

// Wrappers
Information twoSumWrapper(Information i);
Information addTwoNumbersWrapper(Information i);

// Inits
ProblemManager twoSumInit();
ProblemManager addTwoNumbersInit();

// Main Init
void InitializeHighFreqList();

/*
class HighFrequencyCompanyList : ProblemList {

public:
	HighFrequencyCompanyList();
};

extern HighFrequencyCompanyList highfreqlist;
*/

extern ProblemList highfreqlist;

#endif