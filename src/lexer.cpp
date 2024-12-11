#include <iostream>
#include <vector>
#include <string>
#include "token.hpp"
#include "lexer.hpp"
using namespace std;


Lexer::Lexer(vector<string> equation) {
    c_equation = convert(equation);
    c_equation = replace(c_equation);
}


vector<Token> Lexer::tokenization() {
    int count = countToks(c_equation);
    while (count > 1) {
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
        count--;
    }
    tokens.push_back(createToken(c_equation));
    
    return tokens;
}


vector<char> Lexer::convert(vector<string> original) {
    vector<char> converted;
    for (int i=0; i < original[0].size(); i++) {
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
        Token tok(token, 'o');
        return tok;
    }
    else {
        Token tok(token, 'v');
        return tok;
    }
}
    
int Lexer::countToks(vector<char> eq) {
    int count = 0, i = 0;
    while (i < eq.size()) {
        if (checkOp(eq[i])) {
            i++;
        }
        else {
            vector<char> val(eq.begin()+i, eq.end());
            i = findIndex(val);
        }
        count++;
    }
    return count;
}