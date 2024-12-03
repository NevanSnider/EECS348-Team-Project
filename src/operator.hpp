#ifndef OPERATOR_HPP
#define OPERATOR_HPP

#include <iostream>
#include <string>
using namespace std;

class Operator
{
private:
    char op;
    int priority;
    char name;

public:
    Operator(char op);
    void setPriority(char op);
    int getPriority();

//Constructor
Operator::Operator(char op) {
    name = op;
    setPriority(op);
}

//Setter method for priority
void Operator::setPriority(char op) {
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