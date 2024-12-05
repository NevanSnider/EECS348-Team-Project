#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"
using namespace std;

    char type;
    //Token constructor
    Token::Token(vector<char> input, char t) {
        if (input.front() == '(') {
            type = 'l';
        }
        else if (input.front() == ')') {
            type = 'r';
        }
        else {
            type = t;
        }
    }
    
    char Token::getType() {
        return type;
    }


