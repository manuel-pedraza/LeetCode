#include "blind75.h"
#include <numeric>
#include "functions.h"

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
	return std::vector<bool>();
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
	TypedProperty<std::vector<int>>* tpListNode1 = dynamic_cast<TypedProperty<std::vector<int>>*>(input.GetPropByPos(0));
	TypedProperty<int>* tpListNode2 = dynamic_cast<TypedProperty<int>*>(input.GetPropByPos(1));

	// Validate Informations
	if (!(tpListNode1 && tpListNode2)) return Information();

	// Destruct true Informations
	std::vector<int> ln1 = tpListNode1->GetData();
	int ln2 = tpListNode2->GetData();

	// Apply Desired function
	std::vector<bool> results = kidsWithTheGreatestNumberOfCandies(ln1, ln2);

	// Wrap result
	Property* out = new TypedProperty<std::vector<bool>>("output", results);
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
			Information(std::vector<Property*>{ new TypedProperty<std::string>(output, "ALWAYS FAILED TEST") }),
	});

	return mGreatestCommonDivisorStringsInit;
}

ProblemManager kidsWithTheGreatestNumberOfCandiesInit()
{
	ProblemManager mKidsWithTheGreatestNumberOfCandies(Problem(
		"Merge Strings Alternately",
		"There are n kids with candies. You are given an integer array candies, where each candies[i] represents the number of candies the ith kid has, and an integer extraCandies, denoting the number of extra candies that you have.\n\rReturn a boolean array result of length n, where result[i] is true if, after giving the ith kid all the extraCandies, they will have the greatest number of candies among all the kids, or false otherwise.\n\rNote that multiple kids can have the greatest number of candies.",
		Difficulty::Easy
	));

	mKidsWithTheGreatestNumberOfCandies.SetSolution(mergeAlternatelyWrapper);

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

void InitializeBlind75List()
{
	// Verify list isn't loaded
	if (!blind75list.Init()) return;

	// Initialize Problems Managers
	blind75list.AddProblemManager(mergeAlternatelyInit());
	blind75list.AddProblemManager(greatestCommonDivisorStringsInit());
}
