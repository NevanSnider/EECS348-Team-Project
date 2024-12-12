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
    while (count >= 1) {
        int index = findIndex(c_equation);
        if (index == -1) {
            break;
        }
        if (index == 0) {
            if (c_equation.front() == '_') {
                vector<char> neg(c_equation.begin()+1, c_equation.end());
                tokens.push_back(createToken(neg, '-'));
            }
            else {
                tokens.push_back(createToken(c_equation, '+'));
            }
            c_equation.erase(c_equation.begin());
        }
        else {
            vector<char> val(c_equation.begin(), c_equation.begin()+index);
            if (c_equation.front() == '_') {
                vector<char> neg(val.begin()+1, val.end());
                tokens.push_back(createToken(neg, '-'));
            }
            else {
                tokens.push_back(createToken(val, '+'));
            }
            c_equation.erase(c_equation.begin(), c_equation.begin()+index);
        }
        count--;
    }
    if (c_equation.front() == '_') {
        vector<char> neg(c_equation.begin()+1, c_equation.end());
        tokens.push_back(createToken(neg, '-'));
            }
    else {
        tokens.push_back(createToken(c_equation, '+'));
    }
    
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
        else if (checkOp(input[i]) && input[i+1] == '-') {
            output.push_back(input[i]);
            if (checkNum(input[i+2])) {
                output.push_back('_');
                i++;
            }
        }
        else if (i == 0 && input[i] == '-') {
            output.push_back('_');
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

bool Lexer::checkNum(char index) {
    vector<char> nums = {'0','1','2','3','4','5','6','7','8','9'};
    for (int i=0; i < nums.size(); i++) {
        if (nums[i] == index) {
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

Token Lexer::createToken(vector<char> token, char sign) {
    if (checkOp(token.front())) {
        Token tok(token, 'o');
        return tok;
    }
    else {
        Token tok(token, 'v');
        tok.setSign(sign);
        return tok;
    }
}
    
int Lexer::countToks(vector<char> eq) {
    int count = 0, i = 0;
    while (i < eq.size() - 1) {
        if (checkOp(eq[i])) {
            i++;
        }
        else {
            vector<char> val(eq.begin()+i, eq.end());
            i += findIndex(val);
            if (findIndex(val) == -1) {
                return count;
            } 
        }
        count++;
    }
    return count;
}
