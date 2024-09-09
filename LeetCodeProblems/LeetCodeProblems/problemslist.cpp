#include "problemslist.h"
#include "problemmanager.h"

ProblemList::ProblemList(ProblemManager pm)
{
}

ProblemList::~ProblemList()
{
}

void ProblemList::SolveAll()
{
	for (auto pmTmp : list) {
		pmTmp.SolveAll();
	}
}

bool ProblemList::SolveByName(std::string name)
{
	ProblemManager* pm = nullptr;

	for (auto pmTmp : list) {
		if (pmTmp.GetProblemName() == name) {
			pm = &pmTmp;
			break;
		}
	}

	if (!pm)
		return false;

	pm->SolveAll();
	return true;

}

void ProblemList::AddFunction(std::string problemName, Problem::Solution solFunc)
{
	ProblemManager* pm = nullptr;

	for (auto pmTmp : list) {
		if (pmTmp.GetProblemName() == problemName) {
			pm = &pmTmp;
			break;
		}
	}

	if (!pm) return;

	pm->SetSolution(solFunc);

	functionList[problemName] = solFunc;
}
