#include <iostream>
#include <vector>
#include <unordered_map>

#include "problem.h"
#include "property.h"
#include "problemmanager.h"
#include "problemslist.h"


int main() {
	 std::vector<int> values{ -11,7,3,2,1,7,-10,11,21,3 };
	 std::vector<int> res = twoSum(values, 11);

	 Property* pvalue1 = new TypedProperty<std::vector<int>>("values", values);
	 Property* pvalue2 = new TypedProperty<int>("v2", 11);

	 Problem p1("Problem", "1");

	 p1.ProbSolution = [](Information i) { 
		
		 // Destruct Informations
		 TypedProperty<std::vector<int>>* tpValues = dynamic_cast<TypedProperty<std::vector<int>>*>(i.GetPropByPos(0));
		 TypedProperty<int>* tpNumber = dynamic_cast<TypedProperty<int>*>(i.GetPropByPos(1));

		 // Validate Informations
		 if (!(tpValues && tpNumber)) return Information();


		 // Destruct true Informations
		 std::vector<int> vals = tpValues->GetData();
		 int number = tpNumber->GetData();

		 // Apply function
		 std::vector<int> results = twoSum(vals, number);
		 
		 //std::vector<int> results{ -11,7,3,2,1,7,-10,11,21,3 };

		 // Wrap result
		 Property* out = new TypedProperty<std::vector<int>>("output", results);
		 Information output;
		 output.AddProperty(out);
		 //output.PropComparator = i.PropComparator;
		 output.PropComparator = [](Property* p1, Property* p2) {

			 // Destruct Informations
			 TypedProperty<std::vector<int>>* out1 = dynamic_cast<TypedProperty<std::vector<int>>*>(p1);
			 TypedProperty<std::vector<int>>* out2 = dynamic_cast<TypedProperty<std::vector<int>>*>(p2);

			 // Validate Informations
			 if (!(out1 && out2)) return false;

			 std::vector<int> compOut1 = out1->GetData();
			 std::vector<int> compOut2 = out2->GetData();

			 if (compOut1.size() != compOut2.size()) return false;

			 for (int i = 0; i < compOut1.size() && i < compOut2.size(); i++){
				 if (compOut1.at(i) != compOut2.at(i))
					 return false;

			 }

			 return true;
		 };

		 return output; 
	 };

	 Information inf1;
	 inf1.AddProperty(pvalue1);
	 inf1.AddProperty(pvalue2);
	 //Information inf1(std::vector<Property*>(pvalue1, pvalue2));
	 Information inf2;
	 inf2.AddProperty(new TypedProperty<std::vector<int>>("v2", std::vector<int>{6, 8}));

	 ProblemManager pm(p1);
	 bool hasPassed = pm.SolveByInformations(inf1, inf2);

	 std::cout << (hasPassed ? "LETS GOOO" : "BAAAAAD") << std::endl;


	 ProblemList pl(pm);
	 pl.SolveByName("Problem");

	 //p1.SetInputs(Information(std::vector<Property*>(pvalue1, pvalue2)));
	 //Information i1();

	 //Problem<std::vector<int>, std::vector<std::vector<int, int>> twoSum("hello", "there", twoSum);

	 //p1.SetName("Hello there");
}