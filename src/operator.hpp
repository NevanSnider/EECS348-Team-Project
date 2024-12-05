#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>
#include "token.hpp"
using namespace std;

class Operator : public Token
{
private:
    char op;
    int priority;

public:
    Operator(vector<char> token) : Token(token, 'o'){};

    void setPriority(char op);

    int getPriority();
};

#endif