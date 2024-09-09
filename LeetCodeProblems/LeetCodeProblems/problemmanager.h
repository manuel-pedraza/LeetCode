#ifndef PROBLEM_MANAGER_H__
#define PROBLEM_MANAGER_H__

#include <iostream>
#include "problem.h"

class ProblemManager {

public:
	ProblemManager(Problem prob);
	~ProblemManager();
	void SetInputs(std::vector<Information> inputs);
	void SetOutputs(std::vector<Information> outputs);
	bool SolveAll();
	bool SolveByIndex(int index);
	bool SolveByInformations(Information in, Information out);
	bool ValidateLists();
	bool IsEmpty();
	std::string GetProblemName();
	void SetSolution(Problem::Solution func);
private:
	Problem problem;
	std::vector<Information> inputs;
	std::vector<Information> outputs;
};

#endif // !PROBLEM_MANAGER_H__
