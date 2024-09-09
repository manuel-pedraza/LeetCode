#ifndef PROBLEM_LIST_H__
#define PROBLEM_LIST_H__

#include <iostream>
#include <map>
#include "problemmanager.h"
#include "problem.h"

class ProblemList {

public:
	ProblemList();
	~ProblemList();
	bool Init();
	void SolveAll();
	void AddProblemManager(ProblemManager pm);
	bool SolveByName(std::string name);
	void AddFunction(std::string problemName, Problem::Solution solFunc);
private:
	bool bHasBeenInitialized = false;
	std::map<std::string, Problem::Solution> functionList;
	std::vector<ProblemManager> list;
};

#endif // !PROBLEM_LIST_H__
