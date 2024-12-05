#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>
#include <vector>
#include "token.hpp"
using namespace std;

class Operator : public Token
{
private:
    char op;
    int priority;

public:
    //Constructor
    Operator(vector<char> token) : Token(token, 'o') {
        op = token.front();
        setPriority(op);
    }
    
    //Setter method for priority
    void setPriority(char op) {
        switch (op) {
            case '^':
                priority = 3;
                break;
            case '*' || '/' || '%':
                priority = 2;
                break;
            default:
                priority = 3;
                break;
        }
    }
    
    //Getter method for priority
    int getPriority() {
        return priority;
    }
};

#endif