#include <iostream>
#include <string>
#include <vector>
#include "token.hpp"
using namespace std;


    int find(vector<char> line, char elem) {
        for (int i=0; i < line.size(); i++) {
            if (line[i] == elem) return i;
        }
        return -1;
    }

    //Token constructor
    Token::Token(vector<char> input, char t) {
        type = t;
        if (t == 'o') {
            op = input.front();
            setPriority(op);
        }
        else {
            setPriority('1');
            setValue(input);
        }
    }
    
    //Setter method for priority
    void Token::setPriority(char op) {
        switch (op) {
            case '(':
            priority = 1;
            break;
        case ')':
            priority = 1;
            break;
        case '^':
            priority = 2;
            break;
        case '*':
            priority = 3;
            break;
        case '/':
            priority = 3;
            break;
        case '%':
            priority = 3;
            break;
        case '+':
            priority = 4;
            break;
        case '-':
            priority = 4;
            break;
        default:
            priority = -1;
            break;
    }
    }

    template <typename T>
    T Token::getValue() {
        if (id == 'd'){
            return dval;
        }
        return ival;
    }

    char Token::getType() {
        return type;
    }

    //Getter method for priority
    int Token::getPriority() {
        return priority;
    }

    //Setter method for value
    void Token::setValue(vector<char> token) {
        if (find(token, '.') > 0) {
            //double value = convert token to double
        }
        else {
            //int value = convert token to int
        }
    } 



