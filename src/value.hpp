#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>
#include <string>
using namespace std;

class Value
{
private:
    int priority;

public:
    Value(char token[]);
    void setValue(char token[]);
    int getPriority();
    template <typename T>
    T getValue();

//Constructor
Value::Value(char token[]) {
    setValue(token);
    priority = -1;
}

//Setter method for value
void Value::setValue(char token[]) {
    if (find(token, '.') > 0) {
        double value = stod(token);
    }
    else {
        int value = stoi(token);
    }
}    

//Getter method for priority
int getPriority() {
    return priority;
}

//Getter method for value
    //Can return either ints or doubles
template <typename T>
T getValue() {
    return value;
}
};

//Function that returns whether or not the input is an operator
        //Used in setValue()
    int find(string line, char elem) {
    for (int i=0; i < line.length(); i++) {
        if (line[i] == elem) return i;
    }
    return -1;
}

#endif