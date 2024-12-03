#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>
#include <vector>
using namespace std;

class Value
{
private:
    int priority;

public:
    Value(vector<char> token);
    void setValue(vector<char> token);
    int getPriority();
    template <typename T>
    T getValue();

//Constructor
Value::Value(vector<char> token) {
    setValue(token);
    priority = -1;
}

//Setter method for value
void Value::setValue(vector<char> token) {
    if (find(token, '.') > 0) {
        //double value = convert token to double
    }
    else {
        //int value = convert token to int
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
    int find(vector<char> line, char elem) {
    for (int i=0; i < line.size(); i++) {
        if (line[i] == elem) return i;
    }
    return -1;
}

#endif