#ifndef VALUE_HPP
#define VALUE_HPP

#include <iostream>
#include <vector>
#include "token.hpp"
using namespace std;

class Value : public Token
{
private:
    int priority;
    
    //Function that returns whether or not the input is an operator
        //Used in setValue()
    int find(vector<char> line, char elem) {
    for (int i=0; i < line.size(); i++) {
        if (line[i] == elem) return i;
    }
    return -1;
}

public:
    //Constructor
    Value(vector<char> token) : Token(token, 'v') {};
    
    //Setter method for value
    void setValue(vector<char> token); 
    
    //Getter method for priority
    int getPriority();
    
    //Getter method for value
        //Can return either ints or doubles
    template <typename T>
    T getValue();


};

#endif