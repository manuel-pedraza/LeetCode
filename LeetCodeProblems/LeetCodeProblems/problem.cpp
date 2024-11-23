#include "problem.h"
#include "functions.h"

Problem::Problem(std::string name, std::string description, Difficulty diff, std::vector<std::string> inputNames, std::vector<std::string> outputNames) : sName(name), sDescription(description), difficulty(diff), InputNames(inputNames), OutputNames(outputNames) 
{
}

Problem::~Problem()
{
}

bool Problem::Solve(Information input, Information output)
{
	if (ProbSolution == nullptr)
		return false;

	Information outputSol = ProbSolution(input);

	const bool result = outputSol.Compare(output);

	return result;
}
