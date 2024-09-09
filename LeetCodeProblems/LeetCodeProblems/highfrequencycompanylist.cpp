#include "highfrequencycompanylist.h"
#include <unordered_map>
#include "problemslist.h"

ProblemList highfreqlist;

// Function Solution
std::vector<int> twoSum(std::vector<int>& nums, int target) {
	std::unordered_map<int, int> mNums;

	for (int i = 0; i < nums.size(); i++) {
		const int NUM = nums[i];

		int compliment = target - NUM;
		if (mNums.find(compliment) != mNums.end()) {
			return std::vector<int>{ mNums[compliment], i };
		}


		mNums[NUM] = i;
	}

	return std::vector<int>();

	/*
	* My solution
	std::vector<int> aNums;

	for (int i = 0; i < nums.size(); i++) {
		const int NUM = nums[i];
		for (int j = aNums.size() - 1; i > 0 && j >= 0; j--) {

			if (aNums[j] + NUM == target) {
				return {j, i};
			}
		}

		aNums.push_back(NUM);
	}

	return {};
	*/
}

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	int iNum1 = l1 ? l1->val : 0;
	int iNum2 = l2 ? l2->val : 0;
	int iLo = 0;
	ListNode* l3 = new ListNode();
	ListNode* lTmp = l3;

	while (!(l1 == nullptr && l2 == nullptr)) {
		int num = iNum1 + iNum2 + iLo;
		iLo = num > 9 ? 1 : 0;
		num = num % 10;
		lTmp->val = num;


		if (l1 != nullptr) {
			l1 = l1->next;
			iNum1 = l1 ? l1->val : 0;
		}

		if (l2 != nullptr) {
			l2 = l2->next;
			iNum2 = l2 ? l2->val : 0;
		}

		if (l1 == nullptr && l2 == nullptr) {
			if (iLo == 1) {
				lTmp->next = new ListNode();
				lTmp = lTmp->next;
				lTmp->val = 1;
			}
			continue;
		}

		lTmp->next = new ListNode();
		lTmp = lTmp->next;

	}

	return l3;
}

// Wrappers
Information twoSumWrapper(Information i) {

	// Destruct Informations
	TypedProperty<std::vector<int>>* tpValues = dynamic_cast<TypedProperty<std::vector<int>>*>(i.GetPropByPos(0));
	TypedProperty<int>* tpNumber = dynamic_cast<TypedProperty<int>*>(i.GetPropByPos(1));

	// Validate Informations
	if (!(tpValues && tpNumber)) return Information();

	// Destruct true Informations
	std::vector<int> vals = tpValues->GetData();
	int number = tpNumber->GetData();

	// Apply Desired function
	std::vector<int> results = twoSum(vals, number);

	// Wrap result
	Property* out = new TypedProperty<std::vector<int>>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		// Destruct Informations
		TypedProperty<std::vector<int>>* out1 = dynamic_cast<TypedProperty<std::vector<int>>*>(p1);
		TypedProperty<std::vector<int>>* out2 = dynamic_cast<TypedProperty<std::vector<int>>*>(p2);

		// Validate Informations
		if (!(out1 && out2)) return false;

		std::vector<int> compOut1 = out1->GetData();
		std::vector<int> compOut2 = out2->GetData();

		if (compOut1.size() != compOut2.size()) return false;

		for (int i = 0; i < compOut1.size() && i < compOut2.size(); i++) {
			if (compOut1.at(i) != compOut2.at(i))
				return false;

		}

		return true;
	};

	return output;

}

// Problems Initializers
ProblemManager twoSumInit() {
	ProblemManager mTwoSum(Problem(
		"Two Sum",
		"Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.\n\r may assume that each input would have exactly one solution, and you may not use the same element twice.\n\rYou can return the answer in any order."
	));

	mTwoSum.SetSolution(twoSumWrapper);

	// Set Informations 
	// Input
	const std::string values = "values";
	const std::string target = "values";

	// Output
	const std::string output = "arrayToValidate";

	mTwoSum.SetInputs(std::vector<Information> { 
		Information(std::vector<Property*>{ 
			new TypedProperty<std::vector<int>>(values, { -11, 7, 3, 2, 1, 7, -10, 11, 21, 3 }), new TypedProperty<int>(target, 11) 
		}),

		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(values, { 2,7,11,15 }), new TypedProperty<int>(target, 9) }),
		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(values, { 3,2,4 }), new TypedProperty<int>(target, 6) }),
		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(values, { 3,3 }), new TypedProperty<int>(target, 6) }),
	});

	mTwoSum.SetOutputs(std::vector<Information> { 
		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(output, { 6, 8 }) }),
		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(output, { 0, 1 }) }),
		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(output, { 1, 2 }) }),
		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(output, { 0, 1 }) }),
	});

	return mTwoSum;
}


// Initializers
void InitializeHighFreqList()
{
	// Verify list isn't loaded
	if (!highfreqlist.Init()) return;

	// Initialize Problems Managers

	// TODO: Add func AddProblemManager to the list
	highfreqlist.AddProblemManager(twoSumInit());
}