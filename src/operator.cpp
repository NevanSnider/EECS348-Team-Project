

#include <iostream>
#include <vector>
#include "operator.hpp"
using namespace std;

    char op;
    int priority;

    //Constructor
    Operator::Operator(vector<char> token) : Token(token, 'o'){
        op = token.front();
        setPriority(op);
    }

    //Setter method for priority
    void Operator::setPriority(char op) {
        switch (op) {
        case '(':
            priority = 1;
            break;
        case ')':
            priority = 1;
            break;
        case '^':
            priority = 2;
            break;
        case '*' || '/' || '%':
            priority = 3;
            break;
        default:
            priority = 4;
            break;
    }
    }

    //Getter method for priority
    int Operator::getPriority() {
        return priority;
    }

