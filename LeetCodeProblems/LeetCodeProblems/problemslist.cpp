#include "problemslist.h"
#include "problemmanager.h"
#include "screenfunctions.h"
#include "functions.h"

ProblemList::ProblemList(std::string name) : m_name(name)
{
}

ProblemList::~ProblemList()
{
	
}

bool ProblemList::Init()
{
	if (bHasBeenInitialized)
		return false;

	bHasBeenInitialized = true;
	allLists.push_back(this);

	return true;
}

void ProblemList::SolveAll()
{
	for (auto pmTmp : list) {
		pmTmp.SolveAll();
	}
}

void ProblemList::AddProblemManager(ProblemManager pm)
{
	list.push_back(pm);
}

bool ProblemList::SolveByName(std::string name)
{
	
	for (auto pmTmp : list)
		if (pmTmp.GetProblemName() == name) {
			std::cout << "Solving: " + name << " | Difficulty: ";
			showProblemDifficulty(pmTmp.GetProblemDifficulty());
			std::cout << "" << std::endl;
			return pmTmp.SolveAll();
		}

	return false;
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

std::string ProblemList::GetListName()
{
	return m_name;
}
