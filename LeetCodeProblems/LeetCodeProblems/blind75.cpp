#include "blind75.h"

ProblemList blind75list;

std::string mergeAlternately(std::string word1, std::string word2)
{
	return std::string();
}

Information mergeAlternatelyWrapper(Information input)
{
	// Destruct Informations
	TypedProperty<std::string>* tpWord1 = dynamic_cast<TypedProperty<std::string>*>(input.GetPropByPos(0));
	TypedProperty<std::string>* tpWord2 = dynamic_cast<TypedProperty<std::string>*>(input.GetPropByPos(1));

	// Validate Informations
	if (!(tpWord1 && tpWord2)) return;

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

		if (compOut1 != compOut2) return false;
		
		return true;
	};

	return output;
}

ProblemManager mergeAlternatelyInit()
{
	ProblemManager mMergeAlternately(Problem(
		"Merge Strings Alternately",
		"You are given two strings word1 and word2. Merge the strings by adding letters in alternating order, starting with word1. If a string is longer than the other, append the additional letters onto the end of the merged string.\n\r Return the merged string."
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

void InitializeBlind75List()
{
	// Verify list isn't loaded
	if (!blind75list.Init()) return;

	// Initialize Problems Managers
	//leet75list.AddProblemManager();
}
