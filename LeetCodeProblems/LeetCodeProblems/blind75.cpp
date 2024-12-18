#include "blind75.h"
#include <numeric>
#include "functions.h"
#include "screenfunctions.h"
#include <algorithm>
#include <iostream>
#include <cmath>

ProblemList blind75list("Blind 75 List");

std::string mergeAlternately(std::string word1, std::string word2)
{
	const int iWordLength1 = word1.length();
	const int iWordLength2 = word2.length();
	const int lowestIndex = iWordLength1 == iWordLength2 ? iWordLength1 : iWordLength1 > iWordLength2 ? iWordLength2 : iWordLength1;
	std::string res = "";

	for (int i = 0; i < lowestIndex; i++) {
		res.push_back(word1[i]);
		res.push_back(word2[i]);
	}

	if (lowestIndex == iWordLength1)
		res += word2.substr(lowestIndex, word2.length() - lowestIndex);
	else
		res += word1.substr(lowestIndex, word1.length() - lowestIndex);


	return res;
}

std::string greatestCommonDivisorStrings(std::string str1, std::string str2)
{
	if (str1 == str2)
		return str1;
	else if (str1 + str2 != str2 + str1)
		return "";
	else {
		std::string greatestDivisorStr = "";
		const std::string smallestString = str1.length() > str2.length() ? str2 : str1;
		const std::string largestString = str1 == smallestString ? str2 : str1;

		if (largestString.length() % smallestString.length() == 0)
			return smallestString;

		// Find GCD of two numbers
		// Find Minimum of a and b
		int result = smallestString.length();
		while (result > 0) {
			if (smallestString.length() % result == 0 && largestString.length() % result == 0) {
				break;
			}
			result--;
		}

		// Return gcd of a and b
		return smallestString.substr(0, result);
	}
}

std::vector<bool> kidsWithTheGreatestNumberOfCandies(std::vector<int>& candies, int extraCandies)
{
	int highestNumber = *std::max_element(candies.begin(), candies.end());
	std::vector<bool> lstValidations;

	for (int c : candies)
		lstValidations.push_back(c + extraCandies >= highestNumber);

	return lstValidations;
}

bool canPlaceFlowers(std::vector<int>& flowerbed, int flowersToBePlanted)
{
	if (flowerbed.size() < flowersToBePlanted)
		return false;
	else if (flowerbed.size() == 1 && flowerbed[0] == 0 && flowersToBePlanted == 1)
		return true;

	bool hasLeftOne = false;
	int startZeroArray = -1;

	for (int i = 0; i < flowerbed.size() && flowersToBePlanted > 0; i++) {

		if (flowerbed[i] == 0) {
			if (startZeroArray == -1) {
				startZeroArray = i;
				hasLeftOne = (i - 1 >= 0 && flowerbed[i - 1] == 1);
			}

			if (i == flowerbed.size() - 1) {

				const int length = flowerbed.size() - (startZeroArray);


				const int margin = hasLeftOne ? 2 : 1;
				if (length >= margin) {
					flowersToBePlanted--;
					flowersToBePlanted -= std::floor((length - margin) / 2);
				}


			}

		}
		else {
			if (startZeroArray != -1) {

				const int length = (i + 1) - (startZeroArray + 1);

				const int margin = hasLeftOne ? 3 : 2;
				if (length >= margin) {
					flowersToBePlanted--;
					flowersToBePlanted -= std::floor((length - margin) / 2);
				}

				startZeroArray = -1;
				hasLeftOne = false;
			}

		}
	}


	/*
	int len = flowerbed.length;
		int i = 0;
		while(i < len && n > 0) {
			if(flowerbed[i] == 1) i += 2;
			else if(i == len - 1 || flowerbed[i + 1] == 0) {
				n--;
				i += 2;
			}
			else i += 3;
		}
		return n <= 0;
	*/

	return flowersToBePlanted <= 0;
}

std::string reverseVowelsOfString(std::string s)
{
	std::string out = "";
	std::map<int, char> chars;

	for (int i = 0; i < s.length(); i++)
		if (isVowel(s[i]))
			chars.emplace(std::make_pair(i, s[i]));

	if (chars.max_size() % 2 != 0) {
		auto it = next(chars.begin(), std::ceil((double)chars.max_size() / 2) - 1);
		chars.erase(it);
	}

	for (int i = 0; i < s.length(); i++) {
		if (isVowel(s[i]) && !chars.empty()) {
			out += std::prev(chars.end())->second;
			chars.erase(std::prev(chars.end())->first);
		}
		else
			out += s[i];

	}

	return out;

	/*
		char[] word = s.toCharArray();
		int start = 0;
		int end = s.length() - 1;
		String vowels = "aeiouAEIOU";
		while (start < end) {
			while (start < end && vowels.indexOf(word[start]) == -1) {
				start++;
			}
			while (start < end && vowels.indexOf(word[end]) == -1) {
				end--;
			}
			char temp = word[start];
			word[start] = word[end];
			word[end] = temp;

			start++;
			end--;
		}
		String answer = new String(word);
		return answer;
	*/
}

std::string reverseWordsInString(std::string s)
{
	if (s.length() == 1 && !std::isspace(s[0]))
		return s;

	bool hasFoundWord = false;
	int start = 0;
	int end = s.length() - 1;
	std::string lword = "";
	std::string rword = "";
	std::string lNewString = "";
	std::string rNewString = "";

	while (start < end) {
		hasFoundWord = false;
		while (start <= end && !(hasFoundWord && std::isspace(s[start]))) {

			if (hasFoundWord) {
				lword += s[start];

			}
			else if (!std::isspace(s[start])) {
				lword += s[start];
				hasFoundWord = true;

			}

			start++;
		}

		hasFoundWord = false;
		while (start < end && !(hasFoundWord && std::isspace(s[end]))) {

			if (hasFoundWord) {
				rword = s[end] + rword;

			}
			else if (!std::isspace(s[end])) {
				rword = s[end] + rword;
				hasFoundWord = true;

			}

			end--;
		}



		lNewString += rword + (start < end ? " " : "");
		rNewString = (start < end ? " " : "") + lword + rNewString;

		lword = "";
		rword = "";

	}

	if (lNewString.length() > 1 && std::isspace(lNewString[lNewString.length() - 1]))
		lNewString = lNewString.substr(0, lNewString.length() - 1);

	if (rNewString.length() > 1 && std::isspace(rNewString[0]))
		rNewString = rNewString.substr(1);

	return lNewString + (std::empty(lNewString) ? "" : " ") + rNewString;

	/*
	reverse(s.begin(), s.end());
		int n = s.size();
		int left = 0;
		int right = 0;
		int i = 0;
		while (i < n) {
			while (i < n && s[i] == ' ')
				i++;
			if (i == n)
				break;
			while (i < n && s[i] != ' ') {
				s[right++] = s[i++];
			}
			reverse(s.begin() + left, s.begin() + right);

			if (s[right - 1] == ' ')
				s.resize(right - 1);
			else
				s.resize(right)

			s[right++] = ' ';
			left = right;
			i++;
		}
		s.resize(right - 1);
		return s;
	*/
}

std::vector<int> productOfArrayExceptSelf(std::vector<int>& nums)
{
	std::vector<int> newNums(nums.size(), 0);

	int productOfAll = 1;
	int numberOfZeros = 0;
	int indexOfZero = -1;

	for (size_t i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) {
			numberOfZeros++;
			indexOfZero = i;
			if (numberOfZeros >= 2)
				return newNums;
		}
		else
			productOfAll *= nums[i];
	}

	if (numberOfZeros == 1 && indexOfZero != -1) {
		newNums[indexOfZero] = productOfAll;
	}
	else
		for (size_t i = 0; i < nums.size(); i++)
			newNums[i] = productOfAll / nums[i];

	return newNums;
	/*
	// Solution Without using division operator /
	std::vector<int> newNums(nums.size(), 0);

	int productOfAll = 1;
	int numberOfZeros = 0;
	int indexOfZero = -1;

	for (size_t i = 0; i < nums.size(); i++) {
		if (nums[i] == 0) {
			numberOfZeros++;
			indexOfZero = i;
			if (numberOfZeros >= 2)
				return newNums;
		}
		else
			productOfAll *= nums[i];
	}

	if (numberOfZeros == 1 && indexOfZero != -1) {
		newNums[indexOfZero] = productOfAll;
	}
	else
		for (size_t i = 0; i < nums.size(); i++)
			newNums[i] = productOfAll / nums[i];


	return newNums;
	*/
}

Information mergeAlternatelyWrapper(Information input)
{
	// Destruct true Informations
	std::string word1 = input.GetValueByPos<std::string>(0);
	std::string word2 = input.GetValueByPos<std::string>(1);

	// Apply Desired function
	std::string results = mergeAlternately(word1, word2);

	// Wrap result
	Property* out = new TypedProperty<std::string>(results);
	Information output;
	output.AddProperty(out);
	showProblemInputs(std::vector<std::string>{ word1, word2});

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
		showHasPassed(hasPassed);
		showAssertionResult(hasPassed, received, expected);

		return hasPassed;
	};

	return output;
}

Information greatestCommonDivisorStringsWrapper(Information input)
{
	// Destruct true Informations
	std::string str1 = input.GetValueByPos<std::string>(0);
	std::string str2 = input.GetValueByPos<std::string>(1);

	// Apply Desired function
	std::string results = greatestCommonDivisorStrings(str1, str2);

	// Wrap result
	Property* out = new TypedProperty<std::string>(results);
	Information output;
	output.AddProperty(out);
	showProblemInputs(std::vector<std::string>{ str1, str2});

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
		showHasPassed(hasPassed);
		showAssertionResult(hasPassed, received, expected);
		return hasPassed;

	};

	return output;
}

Information kidsWithTheGreatestNumberOfCandiesWrapper(Information input)
{
	// Destruct true Informations
	std::vector<int> candies = input.GetValueByPos<std::vector<int>>(0);
	int extraCandies = input.GetValueByPos<int>(1);

	// Apply Desired function
	std::vector<bool> results = kidsWithTheGreatestNumberOfCandies(candies, extraCandies);

	// Wrap result
	Property* out = new TypedProperty<std::vector<bool>>(results);
	Information output;
	output.AddProperty(out);
	showProblemInputs(std::vector<std::string>{ vectorToString<int>(candies), std::to_string(extraCandies)});

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::vector<bool>>(p1, p2);
		showHasPassed(hasPassed);
		showAssertionResult<bool>(hasPassed, received, expected);
		return hasPassed;

	};

	return output;
}

Information canPlaceFlowersWrapper(Information input)
{
	// Destruct true Informations
	std::vector<int> flowerbed = input.GetValueByPos<std::vector<int>>(0);
	int flowersToBePlanted = input.GetValueByPos<int>(1);

	// Apply Desired function
	bool results = canPlaceFlowers(flowerbed, flowersToBePlanted);

	// Wrap result
	Property* out = new TypedProperty<bool>(results);
	Information output;
	output.AddProperty(out);
	showProblemInputs(std::vector<std::string>{ vectorToString<int>(flowerbed), std::to_string(flowersToBePlanted)});


	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<bool>(p1, p2);
		showHasPassed(hasPassed);
		showAssertionResult(hasPassed, received, expected);
		return hasPassed;

	};

	return output;
}

Information reverseVowelsOfStringWrapper(Information input)
{
	// Destruct true Informations
	std::string inputStr = input.GetValueByPos<std::string>(0);

	// Apply Desired function
	std::string results = reverseVowelsOfString(inputStr);

	// Wrap result
	Property* out = new TypedProperty<std::string>(results);
	Information output;
	output.AddProperty(out);
	showProblemInputs(std::vector<std::string>{ inputStr});


	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
		showHasPassed(hasPassed);
		showAssertionResult(hasPassed, received, expected);
		return hasPassed;

	};

	return output;
}

Information reverseWordsInStringWrapper(Information input)
{
	// Destruct true Informations
	std::string inputStr = input.GetValueByPos<std::string>(0);

	// Apply Desired function
	std::string results = reverseWordsInString(inputStr);

	// Wrap result
	Property* out = new TypedProperty<std::string>(results);
	Information output;
	output.AddProperty(out);
	showProblemInputs(std::vector<std::string>{ inputStr});


	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
		showHasPassed(hasPassed);
		showAssertionResult(hasPassed, received, expected);
		return hasPassed;

	};

	return output;
}

Information productOfArrayExceptSelfWrapper(Information input)
{
	// Destruct true Informations
	std::vector<int> numbers = input.GetValueByPos<std::vector<int>>(0);

	// Apply Desired function
	std::vector<int> results = productOfArrayExceptSelf(numbers);

	// Wrap result
	Property* out = new TypedProperty<std::vector<int>>(results);
	Information output;
	output.AddProperty(out);
	showProblemInputs(std::vector<std::string>{ vectorToString<int>(numbers)});

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::vector<int>>(p1, p2);
		showHasPassed(hasPassed);
		showAssertionResult<int>(hasPassed, received, expected);
		return hasPassed;

	};

	return output;
}

ProblemManager mergeAlternatelyInit()
{
	ProblemManager mMergeAlternately(Problem(
		"Merge Strings Alternately",
		"You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.\n\r Return the merged string.",
		Difficulty::Easy,
		std::vector<std::string>{"word1", "word2"},
		std::vector<std::string>{"wordToValidate"}
	));


	mMergeAlternately.SetSolution(mergeAlternatelyWrapper);

	mMergeAlternately.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>("abc"), new TypedProperty<std::string>("pqr")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("ab"), new TypedProperty<std::string>("pqrs")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("abcd"), new TypedProperty<std::string>("pq")}),
	});

	mMergeAlternately.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::string>("apbqcr") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("apbqrs") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("apbqcd") }),
	});

	return mMergeAlternately;
}

ProblemManager greatestCommonDivisorStringsInit()
{
	ProblemManager mGreatestCommonDivisorStringsInit(Problem(
		"Greatest Common Divisor of Strings",
		"You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.\n\r Return the merged string.",
		Difficulty::Easy,
		std::vector<std::string>{"str1", "str2"},
		std::vector<std::string>{"stringToValidate"}
	));

	mGreatestCommonDivisorStringsInit.SetSolution(greatestCommonDivisorStringsWrapper);

	mGreatestCommonDivisorStringsInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>("ADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBB"), new TypedProperty<std::string>("ADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBB")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"), new TypedProperty<std::string>("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("FBFKOXFBFKOXFBFKOXFBFKOXFBFKOX"), new TypedProperty<std::string>("FBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOX")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("ABABAB"), new TypedProperty<std::string>("ABA")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("ABCABC"), new TypedProperty<std::string>("ABC")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("ABABAB"), new TypedProperty<std::string>("ABAB")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("LEET"), new TypedProperty<std::string>("CODE")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("TAUXXTAUXXTAUXXTAUXXTAUXX"), new TypedProperty<std::string>("TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("ABCDEF"), new TypedProperty<std::string>("ABC")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("ABABABAB"), new TypedProperty<std::string>("ABAB")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("MANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAW"), new TypedProperty<std::string>("MANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAW")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("MNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNM"), new TypedProperty<std::string>("MNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNM")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"), new TypedProperty<std::string>("ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("AAAAAAAAA"), new TypedProperty<std::string>("AAACCC")}),
	});

	mGreatestCommonDivisorStringsInit.SetOutputs(std::vector<Information>
	{
		Information(std::vector<Property*>{ new TypedProperty<std::string>("ADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBB") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("FBFKOX") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("ABC") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("AB") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("TAUXX") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("ABAB") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("MANSDOAWMANSDOAW") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("MNNWONOWNNMMNNWONOWNNM") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("ABCDEFGHIJKLMNOPQRSTUVWXYZ") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("") }),
	});

	return mGreatestCommonDivisorStringsInit;
}

ProblemManager kidsWithTheGreatestNumberOfCandiesInit()
{
	ProblemManager mKidsWithTheGreatestNumberOfCandies(Problem(
		"Kids With the Greatest Number of Candies",
		"There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.\n\rReturn a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.\n\rNote that multiple kids can have the greatest number of candies.",
		Difficulty::Easy,
		std::vector<std::string>{"candies", "extraCandies"},
		std::vector<std::string>{"boolsArray"}
	));

	mKidsWithTheGreatestNumberOfCandies.SetSolution(kidsWithTheGreatestNumberOfCandiesWrapper);

	mKidsWithTheGreatestNumberOfCandies.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{2, 3, 5, 1, 3}), new TypedProperty<int>(3)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{4, 2, 1, 1, 2}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{12, 1, 12}), new TypedProperty<int>(10)}),
	});

	mKidsWithTheGreatestNumberOfCandies.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::vector<bool>>(std::vector<bool>{true, true, true, false, true}) }),
			Information(std::vector<Property*>{ new TypedProperty<std::vector<bool>>(std::vector<bool>{true, false, false, false, false}) }),
			Information(std::vector<Property*>{ new TypedProperty<std::vector<bool>>(std::vector<bool>{true, false, true}) }),
	});

	return mKidsWithTheGreatestNumberOfCandies;
}

ProblemManager canPlaceFlowersInit()
{
	ProblemManager mCanPlaceFlowersInit(Problem(
		"Can Place Flowers",
		"You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.",
		Difficulty::Easy,
		std::vector<std::string>{"flowerbed", "flowersToBePlanted"},
		std::vector<std::string>{"boolResult"}
	));

	mCanPlaceFlowersInit.SetSolution(canPlaceFlowersWrapper);

	mCanPlaceFlowersInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{0, 0, 0, 0, 0}), new TypedProperty<int>(3)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{0, 0, 0}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{0, 0, 1, 0, 0}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{0, 0}), new TypedProperty<int>(2)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{1, 0}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{0, 0, 0}), new TypedProperty<int>(2)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{0}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{1, 0, 0, 0, 1}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{1, 0, 0, 0, 1}), new TypedProperty<int>(2)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{1, 0, 1, 0, 1, 0, 1}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{0, 0, 1, 0, 1}), new TypedProperty<int>(1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{1, 0, 0, 0, 1, 0, 0}), new TypedProperty<int>(2)}),
	});

	mCanPlaceFlowersInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(true) }),
	});

	return mCanPlaceFlowersInit;
}

ProblemManager reverseVowelsOfStringInit()
{
	ProblemManager mReverseVowelsOfStringInit(Problem(
		"Reverse Vowels of a String",
		"Given a string s, reverse only all the vowels in the string and return it. The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lowerand upper cases, more than once.",
		Difficulty::Easy,
		std::vector<std::string>{"Input String"},
		std::vector<std::string>{"Output String"}
	));

	mReverseVowelsOfStringInit.SetSolution(reverseVowelsOfStringWrapper);

	mReverseVowelsOfStringInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>("IceCreAm")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("leetcode")}),
	});

	mReverseVowelsOfStringInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::string>("AceCreIm") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("leotcede") }),
	});

	return mReverseVowelsOfStringInit;
}

ProblemManager reverseWordsInStringInit()
{
	ProblemManager mReverseWordsInStringInit(Problem(
		"Reverse Words in a String",
		"Given an input string s, reverse the order of the words. A word is defined as a sequence of non - space characters.The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space. Note that s may contain leading or trailing spaces or multiple spaces between two words.The returned string should only have a single space separating the words.Do not include any extra spaces.",
		Difficulty::Medium,
		std::vector<std::string>{"Input String"},
		std::vector<std::string>{"Output String"}
	));

	mReverseWordsInStringInit.SetSolution(reverseWordsInStringWrapper);

	mReverseWordsInStringInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>("the sky is blue")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("  hello world  ")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("a good   example")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("EPY2giL")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(" 3c      2zPeO dpIMVv2SG    1AM       o       VnUhxK a5YKNyuG     x9    EQ  ruJO       0Dtb8qG91w 1rT3zH F0m n G wU")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>("a")}),
	});

	mReverseWordsInStringInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::string>("blue is sky the") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("world hello") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("example good a") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("EPY2giL") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("wU G n F0m 1rT3zH 0Dtb8qG91w ruJO EQ x9 a5YKNyuG VnUhxK o 1AM dpIMVv2SG 2zPeO 3c") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>("a") }),
	});

	return mReverseWordsInStringInit;
}

ProblemManager productOfArrayExceptSelfInit()
{
	ProblemManager mProductOfArrayExceptSelfInit(Problem(
		"Product of Array Except Self",
		"Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].The product of any prefix or suffix of nums is guaranteed to fit in a 32 - bit integer.	You must write an algorithm that runs in O(n) time and without using the division operation.",
		Difficulty::Medium,
		std::vector<std::string>{"Numbers"},
		std::vector<std::string>{"Product numbers"}
	));

	mProductOfArrayExceptSelfInit.SetSolution(productOfArrayExceptSelfWrapper);

	mProductOfArrayExceptSelfInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{1, 2, 3, 4}) }),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(std::vector<int>{-1, 1, 0, -3, 3}) }),
	});

	mProductOfArrayExceptSelfInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(std::vector<int>{24, 12, 8, 6}) }),
			Information(std::vector<Property*>{ new TypedProperty<std::vector<int>>(std::vector<int>{ 0, 0, 9, 0, 0}) }),
	});

	return mProductOfArrayExceptSelfInit;
}


void InitializeBlind75List()
{
	// Verify list isn't loaded
	if (!blind75list.Init()) return;

	// Initialize Problems Managers
	blind75list.AddProblemManager(mergeAlternatelyInit());
	blind75list.AddProblemManager(greatestCommonDivisorStringsInit());
	blind75list.AddProblemManager(kidsWithTheGreatestNumberOfCandiesInit());
	blind75list.AddProblemManager(canPlaceFlowersInit());
	blind75list.AddProblemManager(reverseVowelsOfStringInit());
	blind75list.AddProblemManager(reverseWordsInStringInit());
	blind75list.AddProblemManager(productOfArrayExceptSelfInit());
}
