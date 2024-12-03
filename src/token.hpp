#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Value.hpp"
#include "Operator.hpp"
using namespace std;

class Token {
    private:
        char type;
        char ops[6] = {'+','-','*','/','%','^'};
    public:
        Token(vector<char> input);
        char setType(vector<char> input);
    
    //Token constructor
    Token::Token(vector<char> input) {
        char type = setType(input);
        if (type == 'v') {
            Value tok_v();
        }
        else {
            Operator tok_o(input.front());
        }
    }

    //Describes the function of the token, 'v' for number and 'o' for operator
    char setType(vector<char> input) {
        //If we are not changing the power operator than this method must be changed
        if (input.size() < 2 && find(ops, input.front())) {
            return 'o';
        }
        else {
            return 'v';
        }
    }

    //Function that returns whether or not the input is an operator
        //Used in setType()
    int find(string line, char elem) {
    for (int i=0; i < line.size(); i++) {
        if (line[i] == elem) return i;
    }
    return -1;
}
};

#endif