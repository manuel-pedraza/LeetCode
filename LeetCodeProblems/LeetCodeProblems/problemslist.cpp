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
	for (ProblemManager pmTmp : list) {
		showProblemInfos(&pmTmp);
		const bool res = pmTmp.SolveAll();
		showProblemResults(res);
		pmTmp.SolveAll();
	}
}

void ProblemList::AddProblemManager(ProblemManager pm)
{
	list.push_back(pm);
}

bool ProblemList::SolveByName(std::string name)
{

	for (ProblemManager pmTmp : list)
		if (pmTmp.GetProblemName() == name) {
			showProblemInfos(&pmTmp);
			const bool res = pmTmp.SolveAll();
			showProblemResults(res);
			
			return res;
		}

	return false;
}

bool ProblemList::SolveByIndex(int index)
{
	if (index < list.size()) {
		ProblemManager pm = list[index];
		showProblemInfos(&pm);
		const bool res = pm.SolveAll();
		showProblemResults(res);

		return res;
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

std::vector<std::string> ProblemList::GetAllProblemNames()
{
	std::vector<std::string> lstNames;

	for (ProblemManager pm : list)
		lstNames.push_back(pm.GetProblemName());

	return lstNames;
}

std::string ProblemList::GetListName()
{
	return m_name;
}
