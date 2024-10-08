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

Information mergeAlternatelyWrapper(Information input)
{
	// Destruct Informations
	TypedProperty<std::string>* tpWord1 = dynamic_cast<TypedProperty<std::string>*>(input.GetPropByPos(0));
	TypedProperty<std::string>* tpWord2 = dynamic_cast<TypedProperty<std::string>*>(input.GetPropByPos(1));

	// Validate Informations
	if (!(tpWord1 && tpWord2)) throw Information();

	// Destruct true Informations
	std::string word1 = tpWord1->GetData();
	std::string word2 = tpWord2->GetData();

	// Apply Desired function
	std::string results = mergeAlternately(word1, word2);

	// Wrap result
	Property* out = new TypedProperty<std::string>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		// Destruct Informations
		TypedProperty<std::string>* out1 = dynamic_cast<TypedProperty<std::string>*>(p1);
		TypedProperty<std::string>* out2 = dynamic_cast<TypedProperty<std::string>*>(p2);

		// Validate Informations
		if (!(out1 && out2)) return false;

		std::string compOut1 = out1->GetData();
		std::string compOut2 = out2->GetData();

		const bool hasPassed = compOut1 == compOut2;
		showAssertionResult(hasPassed, compOut1, compOut2);

		return hasPassed;
	};

	return output;
}

Information greatestCommonDivisorStringsWrapper(Information input)
{
	// Destruct Informations
	TypedProperty<std::string>* tpWord1 = dynamic_cast<TypedProperty<std::string>*>(input.GetPropByPos(0));
	TypedProperty<std::string>* tpWord2 = dynamic_cast<TypedProperty<std::string>*>(input.GetPropByPos(1));

	// Validate Informations
	if (!(tpWord1 && tpWord2)) throw Information();

	// Destruct true Informations
	std::string str1 = tpWord1->GetData();
	std::string str2 = tpWord2->GetData();

	// Apply Desired function
	std::string results = greatestCommonDivisorStrings(str1, str2);

	// Wrap result
	Property* out = new TypedProperty<std::string>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		// Destruct Informations
		TypedProperty<std::string>* out1 = dynamic_cast<TypedProperty<std::string>*>(p1);
		TypedProperty<std::string>* out2 = dynamic_cast<TypedProperty<std::string>*>(p2);

		// Validate Informations
		if (!(out1 && out2)) return false;

		std::string compOut1 = out1->GetData();
		std::string compOut2 = out2->GetData();

		const bool hasPassed = compOut1 == compOut2;

		showAssertionResult(hasPassed, compOut1, compOut2);

		return hasPassed;
	};

	return output;
}

Information kidsWithTheGreatestNumberOfCandiesWrapper(Information input)
{
	// Destruct Informations
	TypedProperty<std::vector<int>>* tpCandles = dynamic_cast<TypedProperty<std::vector<int>>*>(input.GetPropByPos(0));
	TypedProperty<int>* tpExtraCandles = dynamic_cast<TypedProperty<int>*>(input.GetPropByPos(1));

	// Validate Informations
	if (!(tpCandles && tpExtraCandles)) return Information();

	// Destruct true Informations
	std::vector<int> candies = tpCandles->GetData();
	int extraCandies = tpExtraCandles->GetData();

	// Apply Desired function
	std::vector<bool> results = kidsWithTheGreatestNumberOfCandies(candies, extraCandies);

	// Wrap result
	Property* out = new TypedProperty<std::vector<bool>>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		// Destruct Informations
		TypedProperty<std::vector<bool>>* out1 = dynamic_cast<TypedProperty<std::vector<bool>>*>(p1);
		TypedProperty<std::vector<bool>>* out2 = dynamic_cast<TypedProperty<std::vector<bool>>*>(p2);

		// Validate Informations
		if (!(out1 && out2)) return false;

		std::vector<bool> compOut1 = out1->GetData();
		std::vector<bool> compOut2 = out2->GetData();

		if (compOut1.size() != compOut2.size()) return false;

		bool hasPassed = true;

		for (int i = 0; i < compOut1.size() && i < compOut2.size(); i++) {
			if (compOut1.at(i) != compOut2.at(i)) {
				hasPassed = false;
				break;
			}

		}

		showAssertionResult<bool>(hasPassed, compOut1, compOut2);
		return hasPassed;
	};

	return output;
}

Information canPlaceFlowersWrapper(Information input)
{
	// Destruct Informations
	TypedProperty<std::vector<int>>* tpFlowerbed = dynamic_cast<TypedProperty<std::vector<int>>*>(input.GetPropByPos(0));
	TypedProperty<int>* tpFlowersToBePlanted = dynamic_cast<TypedProperty<int>*>(input.GetPropByPos(1));

	// Validate Informations
	if (!(tpFlowerbed && tpFlowersToBePlanted)) return Information();

	// Destruct true Informations
	std::vector<int> flowerbed = tpFlowerbed->GetData();
	int flowersToBePlanted = tpFlowersToBePlanted->GetData();

	// Apply Desired function
	bool results = canPlaceFlowers(flowerbed, flowersToBePlanted);

	// Wrap result
	Property* out = new TypedProperty<bool>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		// Destruct Informations
		TypedProperty<bool>* out1 = dynamic_cast<TypedProperty<bool>*>(p1);
		TypedProperty<bool>* out2 = dynamic_cast<TypedProperty<bool>*>(p2);

		// Validate Informations
		if (!(out1 && out2)) return false;

		bool compOut1 = out1->GetData();
		bool compOut2 = out2->GetData();

		bool hasPassed = compOut1 == compOut2;

		showAssertionResult(hasPassed, compOut1, compOut2);
		return hasPassed;
	};

	return output;
}

Information reverseVowelsOfStringWrapper(Information input)
{
	// Destruct Informations
	TypedProperty<std::string>* tpInputStr = dynamic_cast<TypedProperty<std::string>*>(input.GetPropByPos(0));

	// Validate Informations
	if (!(tpInputStr)) return Information();

	// Destruct true Informations
	std::string inputStr = tpInputStr->GetData();

	// Apply Desired function
	std::string results = reverseVowelsOfString(inputStr);

	// Wrap result
	Property* out = new TypedProperty<std::string>("output", results);
	Information output;
	output.AddProperty(out);

	// Set Prop Comparator
	output.PropComparator = [](Property* p1, Property* p2) {

		// Destruct Informations
		TypedProperty<std::string>* out1 = dynamic_cast<TypedProperty<std::string>*>(p1);
		TypedProperty<std::string>* out2 = dynamic_cast<TypedProperty<std::string>*>(p2);

		// Validate Informations
		if (!(out1 && out2)) return false;

		std::string compOut1 = out1->GetData();
		std::string compOut2 = out2->GetData();

		bool hasPassed = compOut1 == compOut2;

		showAssertionResult(hasPassed, compOut1, compOut2);
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
}
