#include <iostream>
#include <string>
#include <vector>
#include <cmath>
#include "token.hpp"
using namespace std;

    //Returns the index of a given character in a char vector
    //If the character is not found, -1 is returned
    int Token::find(vector<char> line, char elem) {
        for (int i=0; i < line.size(); i++) {
            if (line[i] == elem) return i;
        }
        return -1;
    }
    
    //Takes a single digit number and converts it to the specified double value
    double Token::findNum(char elem) {
    char nums[] = {'0','1','2','3','4','5','6','7','8','9'};
    double decimals[] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    for (int i=0; i < 10; i++) {
        if (nums[i] == elem) return decimals[i];
    }
    return -1;
}
    //Takes a number in a char vector and converts it to a double
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
        else if (t == 'u') {
            sign = -1;
            priority = -1;

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

    //Getter method for sign
    int Token::getSign() {
        return sign;
    }

    //Getter method for value
    double Token::getValue() {
        return value;
    }

    //Getter method for type
    char Token::getType() {
        return type;
    }
    
    //Getter method for operator type
    char Token::getOp() {
        return op;
    }

    //Getter method for priority
    int Token::getPriority() {
        return priority;
    }

    //Setter method for value
    void Token::setValue(vector<char> token) {
        value = extractNumeric(token);
    }
    



