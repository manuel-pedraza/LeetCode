#include "blind75.h"
#include <numeric>
#include "functions.h"
#include <algorithm>
#include <iostream>
#include <cmath>

ProblemList blind75list;

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

Information mergeAlternatelyWrapper(Information input)
{
	// Destruct true Informations
	std::string word1 = input.GetValueByPos<std::string>(0);
	std::string word2 = input.GetValueByPos<std::string>(1);

	// Apply Desired function
	std::string results = mergeAlternately(word1, word2);

	// Wrap result
	Property* out = new TypedProperty<std::string>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
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
	Property* out = new TypedProperty<std::string>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
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
	Property* out = new TypedProperty<std::vector<bool>>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::vector<bool>>(p1, p2);
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
	Property* out = new TypedProperty<bool>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<bool>(p1, p2);
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
	Property* out = new TypedProperty<std::string>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
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
	Property* out = new TypedProperty<std::string>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		auto [hasPassed, received, expected] = Information::GeneralPropComparator<std::string>(p1, p2);
		showAssertionResult(hasPassed, received, expected);
		return hasPassed;
		
	};

	return output;
}

ProblemManager mergeAlternatelyInit()
{
	ProblemManager mMergeAlternately(Problem(
		"Merge Strings Alternately",
		"You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.\n\r Return the merged string.",
		Difficulty::Easy
	));

	mMergeAlternately.SetSolution(mergeAlternatelyWrapper);

	// Set Informations 
	// Input
	const std::string word1 = "word1";
	const std::string word2 = "word2";

	// Output
	const std::string output = "wordToValidate";

	mMergeAlternately.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>(word1, "abc"), new TypedProperty<std::string>(word2, "pqr")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(word1, "ab"), new TypedProperty<std::string>(word2, "pqrs")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(word1, "abcd"), new TypedProperty<std::string>(word2, "pq")}),
	});

	mMergeAlternately.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "apbqcr") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "apbqrs") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "apbqcd") }),
	});

	return mMergeAlternately;
}

ProblemManager greatestCommonDivisorStringsInit()
{
	ProblemManager mGreatestCommonDivisorStringsInit(Problem(
		"Greatest Common Divisor of Strings",
		"You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.\n\r Return the merged string.",
		Difficulty::Easy
	));

	mGreatestCommonDivisorStringsInit.SetSolution(greatestCommonDivisorStringsWrapper);

	// Set Informations 
	// Input
	const std::string str1 = "str1";
	const std::string str2 = "str2";

	// Output
	const std::string output = "stringToValidate";

	mGreatestCommonDivisorStringsInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "ADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBB"), new TypedProperty<std::string>(str2, "ADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBB")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA"), new TypedProperty<std::string>(str2, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "FBFKOXFBFKOXFBFKOXFBFKOXFBFKOX"), new TypedProperty<std::string>(str2, "FBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOXFBFKOX")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "ABABAB"), new TypedProperty<std::string>(str2, "ABA")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "ABCABC"), new TypedProperty<std::string>(str2, "ABC")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "ABABAB"), new TypedProperty<std::string>(str2, "ABAB")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "LEET"), new TypedProperty<std::string>(str2, "CODE")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "TAUXXTAUXXTAUXXTAUXXTAUXX"), new TypedProperty<std::string>(str2, "TAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXXTAUXX")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "ABCDEF"), new TypedProperty<std::string>(str2, "ABC")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "ABABABAB"), new TypedProperty<std::string>(str2, "ABAB")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "MANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAW"), new TypedProperty<std::string>(str2, "MANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAWMANSDOAW")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "MNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNM"), new TypedProperty<std::string>(str2, "MNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNMMNNWONOWNNM")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ"), new TypedProperty<std::string>(str2, "ABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZABCDEFGHIJKLMNOPQRSTUVWXYZ")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str1, "AAAAAAAAA"), new TypedProperty<std::string>(str2, "AAACCC")}),
	});

	mGreatestCommonDivisorStringsInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "ADADCCBBCBDCDDBABCBBADADCCBBCBDCDDBABCBB") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAAA") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "FBFKOX") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "ABC") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "AB") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "TAUXX") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "ABAB") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "MANSDOAWMANSDOAW") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "MNNWONOWNNMMNNWONOWNNM") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "ABCDEFGHIJKLMNOPQRSTUVWXYZ") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "") }),
	});

	return mGreatestCommonDivisorStringsInit;
}

ProblemManager kidsWithTheGreatestNumberOfCandiesInit()
{
	ProblemManager mKidsWithTheGreatestNumberOfCandies(Problem(
		"Kids With the Greatest Number of Candies",
		"There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.\n\rReturn a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.\n\rNote that multiple kids can have the greatest number of candies.",
		Difficulty::Easy
	));

	mKidsWithTheGreatestNumberOfCandies.SetSolution(kidsWithTheGreatestNumberOfCandiesWrapper);

	// Set Informations 
	// Input
	const std::string candies = "candies";
	const std::string extraCandies = "extraCandies";

	// Output
	const std::string output = "boolsArray";

	mKidsWithTheGreatestNumberOfCandies.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(candies, std::vector<int>{2, 3, 5, 1, 3}), new TypedProperty<int>(extraCandies, 3)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(candies, std::vector<int>{4, 2, 1, 1, 2}), new TypedProperty<int>(extraCandies, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(candies, std::vector<int>{12, 1, 12}), new TypedProperty<int>(extraCandies, 10)}),
	});

	mKidsWithTheGreatestNumberOfCandies.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::vector<bool>>(output, std::vector<bool>{true, true, true, false, true}) }),
			Information(std::vector<Property*>{ new TypedProperty<std::vector<bool>>(output, std::vector<bool>{true, false, false, false, false}) }),
			Information(std::vector<Property*>{ new TypedProperty<std::vector<bool>>(output, std::vector<bool>{true, false, true}) }),
	});

	return mKidsWithTheGreatestNumberOfCandies;
}

ProblemManager canPlaceFlowersInit()
{
	ProblemManager mCanPlaceFlowersInit(Problem(
		"Can Place Flowers",
		"You have a long flowerbed in which some of the plots are planted, and some are not. However, flowers cannot be planted in adjacent plots. Given an integer array flowerbed containing 0's and 1's, where 0 means empty and 1 means not empty, and an integer n, return true if n new flowers can be planted in the flowerbed without violating the no-adjacent-flowers rule and false otherwise.",
		Difficulty::Easy
	));

	mCanPlaceFlowersInit.SetSolution(canPlaceFlowersWrapper);

	// Set Informations 
	// Input
	const std::string flowerbed = "flowerbed";
	const std::string flowersToBePlanted = "flowersToBePlanted";

	// Output
	const std::string output = "boolResult";

	mCanPlaceFlowersInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{0, 0, 0, 0, 0}), new TypedProperty<int>(flowersToBePlanted, 3)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{0, 0, 0}), new TypedProperty<int>(flowersToBePlanted, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{0, 0, 1, 0, 0}), new TypedProperty<int>(flowersToBePlanted, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{0, 0}), new TypedProperty<int>(flowersToBePlanted, 2)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{1, 0}), new TypedProperty<int>(flowersToBePlanted, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{0, 0, 0}), new TypedProperty<int>(flowersToBePlanted, 2)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{0}), new TypedProperty<int>(flowersToBePlanted, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{1, 0, 0, 0, 1}), new TypedProperty<int>(flowersToBePlanted, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{1, 0, 0, 0, 1}), new TypedProperty<int>(flowersToBePlanted, 2)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{1, 0, 1, 0, 1, 0, 1}), new TypedProperty<int>(flowersToBePlanted, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{0, 0, 1, 0, 1}), new TypedProperty<int>(flowersToBePlanted, 1)}),
			Information(std::vector<Property*>{new TypedProperty<std::vector<int>>(flowerbed, std::vector<int>{1, 0, 0, 0, 1, 0, 0}), new TypedProperty<int>(flowersToBePlanted, 2)}),
	});

	mCanPlaceFlowersInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, false) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
			Information(std::vector<Property*>{ new TypedProperty<bool>(output, true) }),
	});

	return mCanPlaceFlowersInit;
}

ProblemManager reverseVowelsOfStringInit()
{
	ProblemManager mReverseVowelsOfStringInit(Problem(
		"Reverse Vowels of a String",
		"Given a string s, reverse only all the vowels in the string and return it. The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lowerand upper cases, more than once.",
		Difficulty::Easy
	));

	mReverseVowelsOfStringInit.SetSolution(reverseVowelsOfStringWrapper);

	// Set Informations 
	// Input
	const std::string str = "Input String";

	// Output
	const std::string output = "Output String";

	mReverseVowelsOfStringInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>(str, "IceCreAm")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str, "leetcode")}),
	});

	mReverseVowelsOfStringInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "AceCreIm") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "leotcede") }),
	});

	return mReverseVowelsOfStringInit;
}

ProblemManager reverseWordsInStringInit()
{
	ProblemManager mReverseWordsInStringInit(Problem(
		"Reverse Words in a String",
		"Given an input string s, reverse the order of the words. A word is defined as a sequence of non - space characters.The words in s will be separated by at least one space. Return a string of the words in reverse order concatenated by a single space. Note that s may contain leading or trailing spaces or multiple spaces between two words.The returned string should only have a single space separating the words.Do not include any extra spaces.",
		Difficulty::Medium
	));

	mReverseWordsInStringInit.SetSolution(reverseWordsInStringWrapper);

	// Set Informations 
	// Input
	const std::string str = "Input String";

	// Output
	const std::string output = "Output String";

	mReverseWordsInStringInit.SetInputs(std::vector<Information> {
		Information(std::vector<Property*>{new TypedProperty<std::string>(str, "the sky is blue")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str, "  hello world  ")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str, "a good   example")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str, "EPY2giL")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str, " 3c      2zPeO dpIMVv2SG    1AM       o       VnUhxK a5YKNyuG     x9    EQ  ruJO       0Dtb8qG91w 1rT3zH F0m n G wU")}),
			Information(std::vector<Property*>{new TypedProperty<std::string>(str, "a")}),
	});

	mReverseWordsInStringInit.SetOutputs(std::vector<Information> {
		Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "blue is sky the") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "world hello") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "example good a") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "EPY2giL") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "wU G n F0m 1rT3zH 0Dtb8qG91w ruJO EQ x9 a5YKNyuG VnUhxK o 1AM dpIMVv2SG 2zPeO 3c") }),
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "a") }),
	});

	return mReverseWordsInStringInit;
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
}
