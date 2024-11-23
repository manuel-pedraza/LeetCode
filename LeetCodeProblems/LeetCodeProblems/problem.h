#ifndef PROBLEM_H__
#define PROBLEM_H__

#include <iostream>
#include "information.h"
#include "difficulty.h"
#include "topics.h"

class Problem {

public:
    typedef Information (*Solution)(Information);
    Problem(std::string name, std::string description, Difficulty diff, std::vector<std::string> inputNames, std::vector<std::string> outputNames);
    ~Problem();
    bool Solve(Information input, Information output);
    Solution ProbSolution = nullptr;
    const Difficulty difficulty;
    const std::string sName;
    const std::string sDescription;
    std::vector<Topics> topics;
    std::vector<std::string> InputNames;
    std::vector<std::string> OutputNames;

};

#endif // !PROBLEM_H__
