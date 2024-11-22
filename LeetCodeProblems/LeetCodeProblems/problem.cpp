#include "problem.h"

Problem::Problem(std::string name, std::string description, Difficulty diff) : sName(name), sDescription(description), difficulty(diff) {}

Problem::~Problem()
{
}

bool Problem::Solve(Information input, Information output)
{
	if (ProbSolution == nullptr)
		return false;

	Information outputSol = ProbSolution(input);

	const bool result = outputSol.Compare(output);

	// MESSAGE

	return result;
}
