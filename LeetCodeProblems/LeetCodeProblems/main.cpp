#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <stdlib.h>

#include "highfrequencycompanylist.h"
#include "blind75.h"
#include "functions.h"
#include "screenfunctions.h"
#include "menustate.h"

int main() {

	InitializeHighFreqList();
	InitializeBlind75List();

	std::string userInput;
	int number = -1;
	ProblemList* pl = nullptr;
	int listIndex = -1;
	int problemIndex = -1;
	MenuState ms = MenuState::Main;

	std::cout << "\033[37m";

	do {
		ClearSreen();

		switch (ms)
		{
		case MenuState::Main:
			showMainMenu();
			break;
		case MenuState::ProblemManager:
			showProblemManagerList(ProblemList::allLists[listIndex]);
			break;
		default:
			break;
		}

		number = -1;
		std::getline(std::cin, userInput);

		try
		{
			number = atoi(userInput.c_str());
		}
		catch (const std::exception& exception)
		{
			number = -1;
		}

		std::transform(userInput.begin(), userInput.end(), userInput.begin(), [](auto c) {return std::toupper(c); });

		switch (ms)
		{
		case MenuState::Main:
			if (userInput != "Q")
				if (number - 1 < ProblemList::allLists.size()) {
					listIndex = number - 1;
					pl = ProblemList::allLists[listIndex];
					ms = MenuState::ProblemManager;
				}
			break;
		case MenuState::ProblemManager:
			if (userInput == "Q") {
				ms = MenuState::Main;
				listIndex = -1;
			}
			else {
				if (userInput == "A") {
					pl->SolveAll();
					std::cout << std::endl << "Press any key to continue";
					std::cin.get();
				}
				else if (number - 1 < pl->GetAllProblemNames().size()) {
					problemIndex = number - 1;
					pl->SolveByIndex(problemIndex);
					std::cout << std::endl << "Press any key to continue";
					std::cin.get();
				}

				ClearSreen();
			}

			userInput = "";
			break;
		default:
			break;
		}

	} while (!(ms == MenuState::Main && userInput == "Q"));

}