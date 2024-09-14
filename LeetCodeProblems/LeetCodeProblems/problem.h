#ifndef PROBLEM_H__
#define PROBLEM_H__

#include <iostream>
#include "information.h"
#include "difficulty.h"
#include "topics.h"

class Problem {

public:
    typedef Information (*Solution)(Information);
    Problem(std::string name, std::string description, Difficulty diff);
    ~Problem();
    bool Solve(Information input, Information output);
    Solution ProbSolution = nullptr;
    const Difficulty difficulty;
    const std::string sName;
    const std::string sDescription;
    std::vector<Topics> topics;

};

#endif // !PROBLEM_H__
