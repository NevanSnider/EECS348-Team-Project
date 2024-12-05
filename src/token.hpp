#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Token {
    private:
        char type;
    public:
        Token(vector<char> input, char t){};
        
        char getType();

};

#endif