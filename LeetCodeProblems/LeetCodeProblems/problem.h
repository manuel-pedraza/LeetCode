#ifndef PROBLEM_H__
#define PROBLEM_H__

#include <iostream>
#include <vector>

template<class T, class U>
class Problem {

public:
    Problem(std::string name, std::string description);
    Problem(std::string name, std::string description, U (*solution)(T));
    Problem(std::string name, std::string description, U(*solution)(T), std::vector<T> inputs, std::vector<U> outputs);
    ~Problem();
    bool Solve(std::vector<T> inputs, std::vector<U> outputs);
    bool Solve();
    void SetInputs(std::vector<T> inputs);
    void SetOutputs(std::vector<U> outputs);
    void SetSolution( U(*f)(T) );

private:
    void Solution = nullptr;
    std::vector<T> lstInputs;
    std::vector<U> lstOutputs;
    const std::string sName;
    const std::string sDescription;
};


template<class T, class U>
inline Problem<T, U>::Problem(std::string name, std::string description) : sName(name), sDescription(description)
{
}

template<class T, class U>
inline Problem<T, U>::Problem(std::string name, std::string description, U(*Solution)(T)) : sName(name), sDescription(description)
{
}

template<class T, class U>
inline Problem<T, U>::Problem(std::string name, std::string description, U(*Solution)(T), std::vector<T> inputs, std::vector<U> outputs) : sName(name), sDescription(description)
{
}

template<class T, class U>
Problem<T, U>::~Problem()
{
}


template<class T, class U>
bool Problem<T, U>::Solve(std::vector<T> inputs, std::vector<U> outputs)
{
    return false;
}

template<class T, class U>
bool Problem<T, U>::Solve()
{
    return false;
}

template<class T, class U>
void Problem<T, U>::SetInputs(std::vector<T> inputs)
{
}

template<class T, class U>
void Problem<T, U>::SetOutputs(std::vector<U> outputs)
{
}

template<class T, class U>
void Problem<T, U>::SetSolution(U(*f)(T))
{
    Solution = f;
}


#endif // !PROBLEM_H__
