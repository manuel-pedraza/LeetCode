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
		if (pmTmp.GetProblemName() == name)
			pm = &pmTmp;
	}

	if (!pm)
		return false;

	pm->SolveAll();
	return true;

}
