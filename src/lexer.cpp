#include "lexer.hpp"
#include "token.hpp"
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Lexer constructor
Lexer::Lexer(vector<string> equation) {
    if (equation.empty()) {
        throw invalid_argument("Equation vector is empty.");
    }
    c_equation = convert(equation);
    c_equation = replace(c_equation);
}

// Tokenize the converted and replaced equation
vector<Token> Lexer::tokenization() {
    int count = countToks(c_equation);
    while (count >= 1) {
        tokens.front();
        int index = findIndex(c_equation);
        if (index == -1) {
            break;
        }
        if (index == 0) {
            c_equation.erase(c_equation.begin());
        }
        else if (index > 0) {
            vector<char> val(c_equation.begin(), c_equation.begin() + index);
            tokens.push_back(createToken(val));
            c_equation.erase(c_equation.begin(), c_equation.begin() + index);
        }
        else { // index == -1
            tokens.push_back(createToken(c_equation));
            break;
        }
        count--;
    }
    return tokens;
}

// Convert the first string in the vector to a vector of chars
vector<char> Lexer::convert(vector<string> original) {
    vector<char> converted;
    for (size_t i = 0; i < original[0].size(); i++) {
        converted.push_back(original[0][i]);
    }
    return converted;
}

// Replace '**' with '^' to handle exponentiation
vector<char> Lexer::replace(vector<char> input) {
    vector<char> output;
    size_t i = 0;
    while (i < input.size()) {
        // Handle '**' to '^'
        if (i + 1 < input.size() && input[i] == '*' && input[i + 1] == '*') {
            output.push_back('^');
            i += 2;
            continue;
        }
        // this replaces multiplication by parathnes with *...  ex. 5(4+1) --> 5 * (4 + 1)
        if (i + 1 < input.size() && isdigit(input[i]) && input[i + 1] == '(') {
            output.push_back(input[i]);
            output.push_back('*');
            i += 1;
            continue;
        }
        output.push_back(input[i]);
        i++;
    }
    return output;
}

bool Lexer::checkOp(char index) {
    vector<char> ops = {'+', '-', '*', '/', '%', '^', '(', ')'};
    for (size_t i = 0; i < ops.size(); i++) {
        if (ops[i] == index) {
            return true;
        }
    }
    return false;
}

// Find the index of the first operator in the equation
int Lexer::findIndex(vector<char> equation) {
    for (size_t i = 0; i < equation.size(); i++) {
        if (checkOp(equation[i])) {
            return static_cast<int>(i);
        }
    }
    return -1;
}

// Create a token based on the characters provided
Token Lexer::createToken(vector<char> tokenChars) {
    if (tokenChars.empty()) {
        throw invalid_argument("Token characters vector is empty.");
    }

    if (checkOp(tokenChars.front())) {
        // handles and checks for urnary minus
        if (tokenChars.front() == '-' && (tokens.empty() ||
            tokens.back().getType() == 'o' ||
            tokens.back().getOp() == '(')) {
            return Token(tokenChars, 'u');
        }
        return Token(tokenChars, 'o');
    }
    else {
        return Token(tokenChars, 'v');
    }
}

// Count the number of tokens in the equation
int Lexer::countToks(vector<char> eq) {
    int count = 0;
    size_t i = 0;
    while (i < eq.size()) {
        if (checkOp(eq[i])) {
            count++;
            i++;
        }
        else {
            int index = findIndex(vector<char>(eq.begin() + i, eq.end()));
            if (index == -1) {
                count++;
                break;
            }
            count++;
            i += static_cast<size_t>(index);
        }
    }
    return count;
}
