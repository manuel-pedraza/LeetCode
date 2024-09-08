#ifndef PROBLEM_MANAGER_H__
#define PROBLEM_MANAGER_H__

#include <iostream>
#include "problem.h"

class ProblemManager {

public:
	ProblemManager(Problem prob);
	~ProblemManager();
	void SetInput(Information input);
	void SetOutput(Information output);
private:
	Problem problem;
	Information inputProps;
	Information outputProps;
	std::vector<Information> inputs;
	std::vector<Information> outputs;
};

#endif // !PROBLEM_MANAGER_H__
