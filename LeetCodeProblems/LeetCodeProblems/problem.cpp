#include "problem.h"

Problem::Problem(std::string name, std::string description) : sName(name), sDescription(description) {}

Problem::~Problem()
{
}

bool Problem::Solve(Information input, Information output)
{
	std::cout << "Solve" << std::endl;

	if (ProbSolution == nullptr)
		return false;

	Information outputSol = ProbSolution(input);

	return outputSol.Compare(output);
}
