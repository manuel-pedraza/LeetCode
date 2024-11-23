#ifndef PROBLEM_LIST_H__
#define PROBLEM_LIST_H__

#include <iostream>
#include <map>
#include "problemmanager.h"
#include "problem.h"

class ProblemList {

public:
	ProblemList(std::string name);
	~ProblemList();
	bool Init();
	void SolveAll();
	void AddProblemManager(ProblemManager pm);
	bool SolveByName(std::string name);
	bool SolveByIndex(int index);
	void AddFunction(std::string problemName, Problem::Solution solFunc);
	std::vector<std::string> GetAllProblemNames();
	std::string GetListName();
	static inline std::vector<ProblemList*> allLists;

private:
	bool bHasBeenInitialized = false;
	std::map<std::string, Problem::Solution> functionList;
	std::vector<ProblemManager> list;
	std::string m_name;
};

#endif // !PROBLEM_LIST_H__
