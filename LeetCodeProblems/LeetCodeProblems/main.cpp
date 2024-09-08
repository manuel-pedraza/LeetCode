#include <iostream>
#include <vector>
#include <unordered_map>

#include "problem.h"
#include "property.h"

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



//Definition for singly-linked list.
struct ListNode {
	int val;
	ListNode* next;
	ListNode() : val(0), next(nullptr) {}
	ListNode(int x) : val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) : val(x), next(next) {}
};

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

int main() {
	 std::vector<int> values{ -11,7,3,2,1,7,-10,11,21,3 };
	 std::vector<int> res = twoSum(values, 11);
	 
	 std::cout << "Hello there";

	 Property* pvalue1 = new TypedProperty<std::vector<int>>("values", values);
	 Property* pvalue2 = new TypedProperty<int>("v2", 11);

	 Problem p1("Problem", "1");

	 p1.ProbSolution = [](Information i) { 
		
		 std::cout << "Entered Lambda Func" << std::endl;
		 // Destruct Informations
		 TypedProperty<std::vector<int>>* tpValues = dynamic_cast<TypedProperty<std::vector<int>>*>(i.GetPropByPos(0));
		 TypedProperty<int>* tpNumber = dynamic_cast<TypedProperty<int>*>(i.GetPropByPos(1));

		 // Validate Informations
		 if (!(tpValues && tpNumber)) return Information();

		 std::cout << "Passed Validations" << std::endl;

		 // Destruct true Informations
		 std::vector<int> vals = tpValues->GetData();
		 int number = tpNumber->GetData();

		 // Apply function
		 std::vector<int> results = twoSum(vals, number);
		 
		 //std::vector<int> results{ -11,7,3,2,1,7,-10,11,21,3 };

		 // Wrap result
		 Property* out = new TypedProperty<std::vector<int>>("output", results);
		 Information output;
		 output.AddProperty(out);
		 //output.PropComparator = i.PropComparator;
		 output.PropComparator = [](Property* p1, Property* p2) {

			 // Destruct Informations
			 TypedProperty<std::vector<int>>* out1 = dynamic_cast<TypedProperty<std::vector<int>>*>(p1);
			 TypedProperty<std::vector<int>>* out2 = dynamic_cast<TypedProperty<std::vector<int>>*>(p2);

			 // Validate Informations
			 if (!(out1 && out2)) return false;

			 std::vector<int> compOut1 = out1->GetData();
			 std::vector<int> compOut2 = out2->GetData();

			 if (compOut1.size() != compOut2.size()) return false;

			 for (int i = 0; i < compOut1.size() && i < compOut2.size(); i++){
				 if (compOut1.at(i) != compOut2.at(i))
					 return false;

			 }

			 return true;
		 };

		 return output; 
	 };

	 Information inf1;
	 inf1.AddProperty(pvalue1);
	 inf1.AddProperty(pvalue2);
	 //Information inf1(std::vector<Property*>(pvalue1, pvalue2));
	 Information inf2;
	 inf2.AddProperty(new TypedProperty<std::vector<int>>("v2", std::vector<int>{6, 8}));

	 bool hasPassed = p1.Solve(inf1, inf2);

	 std::cout << (hasPassed ? "LETS GOOO" : "BAAAAAD") << std::endl;

	 //p1.SetInputs(Information(std::vector<Property*>(pvalue1, pvalue2)));
	 //Information i1();

	 //Problem<std::vector<int>, std::vector<std::vector<int, int>> twoSum("hello", "there", twoSum);

	 //p1.SetName("Hello there");
}