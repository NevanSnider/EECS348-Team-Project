#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "token.hpp"
using namespace std;


    int Token::find(vector<char> line, char elem) {
        for (int i=0; i < line.size(); i++) {
            if (line[i] == elem) return i;
        }
        return -1;
    }
    
    double Token::findNum(char elem) {
    char nums[] = {'0','1','2','3','4','5','6','7','8','9'};
    double decimals[] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    for (int i=0; i < 10; i++) {
        if (nums[i] == elem) return decimals[i];
    }
    return -1;
}

    double Token::extractNumeric(vector<char> str_num) {
        double num, place;
        int i = 0, length = str_num.size();
        if (find(str_num, '.') > -1) {
            int n = find(str_num, '.') - i;
            place = pow(10.0, n-1);
        }
        else {
            int n = length;
            place = pow(10.0, n-1);
        }
        for (i; i < length; i++) {
            if (str_num[i] == '.') continue;
            num = i==0 ? place*findNum(str_num[i]) : num + place*findNum(str_num[i]);
            place /= 10;
        }
        return num;
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
            type = 'l';
            break;
        case ')':
            priority = 1;
            type='r';
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

    double Token::getValue() {
        return value;
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
        value = extractNumeric(token);
    }
    



