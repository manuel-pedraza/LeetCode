#ifndef PROBLEM_H__
#define PROBLEM_H__

#include <iostream>
#include "information.h"

class Problem {

protected:
    typedef Information (*Solution)(Information);

public:
    Problem(std::string name, std::string description);
    ~Problem();
    bool Solve(Information input, Information output);
    Solution ProbSolution = nullptr;
    const std::string sName;
    const std::string sDescription;

private:
};

#endif // !PROBLEM_H__
