#ifndef LEXER_HPP
#define LEXER_HPP

#include <iostream>
#include <vector>
#include <string>
#include "token.hpp"
using namespace std;

class Lexer {

    private:
        vector<char> c_equation;
        vector<Token> tokens;
    public:
        vector<char> convert(vector<string> original);
        vector<char> replace(vector<char> input);
        int findIndex(vector<char> equation);
        bool checkOp(char index);
        bool checkNum(char index);
        Token createToken(vector<char> token, char sign);
        Lexer(vector<string> equation);
        vector<Token> tokenization();
        int countToks(vector<char> eq);
};

#endif