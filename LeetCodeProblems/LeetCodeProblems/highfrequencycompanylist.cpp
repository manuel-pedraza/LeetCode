#include "highfrequencycompanylist.h"
#include <unordered_map>

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
