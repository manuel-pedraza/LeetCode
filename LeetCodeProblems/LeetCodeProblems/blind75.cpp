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

void InitializeBlind75List()
{
	// Verify list isn't loaded
	if (!blind75list.Init()) return;

	// Initialize Problems Managers
	blind75list.AddProblemManager(mergeAlternatelyInit());
	blind75list.AddProblemManager(greatestCommonDivisorStringsInit());
}
