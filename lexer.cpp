#include <iostream>
#include <vector>
#include <string>
#include "token.hpp"
#include "operator.hpp"
#include "value.hpp"
#include "lexer.hpp"
using namespace std;


Lexer::Lexer(vector<string> equation) {
    c_equation = convert(equation);
    c_equation = replace(c_equation);
}

vector<Token> Lexer::tokenization() {
    vector<Token> tokens;
    while (c_equation.size() > 0) {
        int index = findIndex(c_equation);
        if (index == 0) {
            tokens.push_back(createToken(c_equation));
            c_equation.erase(c_equation.begin());
        }
        else {
            vector<char> val(c_equation.begin(), c_equation.begin()+index);
            tokens.push_back(createToken(val));
            c_equation.erase(c_equation.begin(), c_equation.begin()+index);
        }
    }
    return tokens;
}

vector<char> Lexer::convert(vector<string> original) {
    vector<char> converted;
    for (int i=0; i < original.size(); i++) {
        converted.push_back(original[0][i]);
    }
    return converted;
}

vector<char> Lexer::replace(vector<char> input) {
    vector<char> output;
    int i = 0;
    while (i < input.size()) {
        if (input[i] == '*' && input[i+1] == '*') {
            output.push_back('^');
            i++;
        }
        else {
            output.push_back(input[i]);
        }
        i++;
    }
    return output;
}

bool Lexer::checkOp(char index) {
    vector<char> ops = {'+','-','*','/','%','^','(',')'};
    for (int i=0; i < ops.size(); i++) {
        if (ops[i] == index) {
            return true;
        }
    }
    return false;
}

int Lexer::findIndex(vector<char> equation) {
    for (int i=0; i < equation.size(); i++) {
        if (checkOp(equation[i])) {
            return i;
        }
    }
    return -1;
}

Token Lexer::createToken(vector<char> token) {
    if (checkOp(token.front())) {
        Operator tok(token);
        return tok;
    }
    else {
        Value tok(token);
        return tok;
    }
}