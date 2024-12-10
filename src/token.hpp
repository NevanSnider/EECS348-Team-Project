#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Token {
    private:
        char type;
        int priority;
        char op;
        char id;
        double dval;
        int ival;
    public:
        Token(vector<char> input, char t);
        
        char getType();
        void setPriority(char op);
        int getPriority();
        void setValue(vector<char> value);
        template <typename T>
        T getValue();

};

#endif