#include <iostream>
#include <string>
#include <vector>
#include "Token.hpp"
using namespace std;

    char type;
    //Token constructor
    Token::Token(vector<char> input, char t) {
        type = t;
    }
    
    char Token::getType() {
        return type;
    }


