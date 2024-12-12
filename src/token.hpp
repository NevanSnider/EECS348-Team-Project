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
        double value;
        int sign;
    public:
        Token(vector<char> input, char t);
        
        char getType();
        char getOp();
        void setPriority(char op);
        int getPriority();
        int getSign();
        void setValue(vector<char> value);
        double getValue();
        int find(vector<char> line, char elem);
        double findNum(char elem);
        double extractNumeric(vector<char> input);

};

#endif