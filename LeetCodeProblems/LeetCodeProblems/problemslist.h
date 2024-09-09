#ifndef PROBLEM_LIST_H__
#define PROBLEM_LIST_H__

#include <iostream>
#include "problemmanager.h"

class ProblemList {

public:
	ProblemList(ProblemManager pm);
	~ProblemList();
	void SolveAll();
	bool SolveByName(std::string name);
private:
	std::vector<ProblemManager> list;
};

#endif // !PROBLEM_LIST_H__
