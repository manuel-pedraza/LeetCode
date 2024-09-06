#include <iostream>
#include <vector>
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


int main() {
	std::vector<int> values{ -11,7,3,2,1,7,-10,11,21,3 };
	std::vector<int> res = twoSum(values, 11);

	std::cout << "Hello there";

}