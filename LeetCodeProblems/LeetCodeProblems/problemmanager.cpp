#include "problemmanager.h"

ProblemManager::ProblemManager(Problem prob) : problem(prob) {

}

ProblemManager::~ProblemManager()
{
}

void ProblemManager::SetInputs(std::vector<Information> inputs)
{
	this->inputs = inputs;
}

void ProblemManager::SetOutputs(std::vector<Information> outputs)
{
	this->outputs = outputs;
}

bool ProblemManager::SolveAll()
{

	if (!ValidateLists() || !ValidateLists())
		return false;

	for (int i = 0; i < inputs.size() && i < outputs.size(); i++)
		if (!this->SolveByIndex(i))
			return false;

	return true;
}

bool ProblemManager::SolveByIndex(int index)
{
	if (!ValidateLists() || !ValidateLists())
		return false;

	return this->problem.Solve(inputs.at(index), outputs.at(index));

}

bool ProblemManager::SolveByInformations(Information in, Information out)
{
	if (!ValidateLists() || !IsEmpty())
		return false;

	return this->problem.Solve(in, out);

}

bool ProblemManager::ValidateLists()
{
	return inputs.size() == outputs.size();
}

bool ProblemManager::IsEmpty()
{
	return inputs.size() == 0 && outputs.size() == 0;
}

std::string ProblemManager::GetProblemName()
{
	return problem.sName;
}

void ProblemManager::SetSolution(Problem::Solution func)
{
	problem.ProbSolution = func;
}
