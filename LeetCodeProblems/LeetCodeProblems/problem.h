#ifndef PROBLEM_H__
#define PROBLEM_H__

#include <iostream>
#include "information.h"

class Problem {

public:
    Problem(std::string name, std::string description);
    Problem(std::string name, std::string description, Information (*solution)(Information));
    Problem(std::string name, std::string description, Information(*solution)(Information), Information input, Information output);
    ~Problem();
    bool Solve(Information input, Information output);
    bool Solve();
    void SetInputs(Information input);
    void SetOutputs(Information output);
    void SetSolution(Information(*f)(Information) );

private:
    //void Solution = nullptr;
    Information input;
    Information output;
    const std::string sName;
    const std::string sDescription;
};

#endif // !PROBLEM_H__
