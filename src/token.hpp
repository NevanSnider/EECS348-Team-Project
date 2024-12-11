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
        double value;
    public:
        Token(vector<char> input, char t);
        
        char getType();
        void setPriority(char op);
        int getPriority();
        void setValue(vector<char> value);
        double getValue();
        int find(vector<char> line, char elem);
        double findNum(char elem);
        double extractNumeric(vector<char> input);

};

#endif