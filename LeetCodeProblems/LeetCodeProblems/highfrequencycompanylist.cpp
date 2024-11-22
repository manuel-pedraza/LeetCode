#include "highfrequencycompanylist.h"
#include <unordered_map>
#include "problemslist.h"
#include "functions.h"


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

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::vector<int>>(p1, p2);
		showAssertionResult<int>(hasPassed, received, expected);
		return hasPassed;
	};

	return output;

}

Information addTwoNumbersWrapper(Information i)
{
	// Destruct Informations
	TypedProperty<ListNode*>* tpListNode1 = dynamic_cast<TypedProperty<ListNode*>*>(i.GetPropByPos(0));
	TypedProperty<ListNode*>* tpListNode2 = dynamic_cast<TypedProperty<ListNode*>*>(i.GetPropByPos(1));

	// Validate Informations
	if (!(tpListNode1 && tpListNode2)) return Information();

	// Destruct true Informations
	ListNode* ln1 = tpListNode1->GetData();
	ListNode* ln2 = tpListNode2->GetData();

	// Apply Desired function
	ListNode* results = addTwoNumbers(ln1, ln2);

	// Wrap result
	Property* out = new TypedProperty<ListNode*>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		// Here we can't use auto Information::GeneralPropComparator, 'cause it's type is a complex struct

		// Destruct Informations
		TypedProperty<ListNode*>* out1 = dynamic_cast<TypedProperty<ListNode*>*>(p1);
		TypedProperty<ListNode*>* out2 = dynamic_cast<TypedProperty<ListNode*>*>(p2);

		// Validate Informations
		if (!(out1 && out2)) return false;

		ListNode* compOut1 = out1->GetData();
		ListNode* compOut2 = out2->GetData();

		if (!(compOut1 && compOut2)) return false;

		while (!(compOut1 == nullptr && compOut2 == nullptr)) {

			if (compOut1->val != compOut2->val) return false;

			compOut1 = compOut1->next;
			compOut2 = compOut2->next;

		}

		return true;
	};

	return output;
}

// Problems Initializers
ProblemManager twoSumInit() {
	ProblemManager mTwoSum(Problem(
		"Two Sum",
		"Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.\n\r may assume that each input would have exactly one solution, and you may not use the same element twice.\n\rYou can return the answer in any order.",
		Difficulty::Easy
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

ProblemManager addTwoNumbersInit()
{
	ProblemManager mAddTwoNumbers(Problem(
		"Add Two Numbers", "You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order, and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.\n\rYou may assume the two numbers do not contain any leading zero, except the number 0 itself.",
		Difficulty::Easy
	));

	mAddTwoNumbers.SetSolution(addTwoNumbersWrapper);

	// Set Informations 
	// Input
	const std::string listNode1 = "listNode1";
	const std::string listNode2 = "listNode2";

	// Output
	const std::string output = "listNodeRes";

	mAddTwoNumbers.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{
			new TypedProperty<ListNode*>(listNode1, new ListNode(2, new ListNode(4, new ListNode(3)))),
				new TypedProperty<ListNode*>(listNode2, new ListNode(5, new ListNode(6, new ListNode(4))))
		}),

			Information(std::vector<Property*>{ new TypedProperty<ListNode*>(listNode1, new ListNode(0)), new TypedProperty<ListNode*>(listNode2, new ListNode(0))}),

				Information(std::vector<Property*>{
				new TypedProperty<ListNode*>(listNode1, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))))),
					new TypedProperty<ListNode*>(listNode2, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(9)))))
			}),
	});

	mAddTwoNumbers.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<ListNode*>(output, new ListNode(7, new ListNode(0, new ListNode(8)))) }),
			Information(std::vector<Property*>{ new TypedProperty<ListNode*>(output, new ListNode(0)) }),
			Information(std::vector<Property*>{ new TypedProperty<ListNode*>(output, new ListNode(8, new ListNode(9, new ListNode(9, new ListNode(9, new ListNode(0, new ListNode(0, new ListNode(0, new ListNode(1))))))))) }),
	});

	return mAddTwoNumbers;
}


// Initializers
void InitializeHighFreqList()
{
	// Verify list isn't loaded
	if (!highfreqlist.Init()) return;

	// Initialize Problems Managers
	highfreqlist.AddProblemManager(twoSumInit());
	highfreqlist.AddProblemManager(addTwoNumbersInit());
}