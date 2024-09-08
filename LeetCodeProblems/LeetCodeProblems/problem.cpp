#include "problem.h"

Problem::Problem(std::string name, std::string description) : sName(name), sDescription(description)
{
	std::cout << "This is " << this->sName << " " << this->sDescription << std::endl;

}

Problem::Problem(std::string name, std::string description, Information(*solution)(Information))
{
}

Problem::Problem(std::string name, std::string description, Information(*solution)(Information), Information input, Information output)
{
}

Problem::~Problem()
{
}

bool Problem::Solve(Information input, Information output)
{
	return false;
}

bool Problem::Solve()
{
	return false;
}

void Problem::SetInputs(Information input)
{
}

void Problem::SetOutputs(Information output)
{
}

void Problem::SetSolution(Information(*f)(Information))
{
}
