#include "token.hpp"
#include <cmath>

// Token constructor
Token::Token(const vector<char>& input, char t) {
    type = t;
    if (t == 'o' || t == 'u') { 
        op = input.front();
        setPriority(op);
    }
    else {
        setPriority('1');
        setValue(input);
    }
}

// Getter methods for value
char Token::getType() const {
    return type;
}

char Token::getOp() const {
    return op;
}

int Token::getPriority() const {
    return priority;
}

double Token::getValue() const {
    return value;
}

// Setter method for priority
void Token::setPriority(char opChar) {
    switch (opChar) {
        case '(':
            priority = 1;
            type = 'l';
            break;
        case ')':
            priority = 1;
            type = 'r';
            break;
        case '^':
            priority = 2;
            break;
        case '*':
        case '/':
        case '%':
            priority = 3;
            break;
        case '+':
        case '-':
            priority = (type == 'u') ? 2 : 4; // Higher priority for unary
            break;
        case 'u': // Defines the priority for unary
            priority = 2;
            break;
        default:
            priority = -1;
            break;
    }
}

void Token::setValue(const vector<char>& input) {
    value = extractNumeric(input);
}

int Token::find(const vector<char>& line, char elem) const {
    for (size_t i = 0; i < line.size(); i++) {
        if (line[i] == elem) return static_cast<int>(i);
    }
    return -1;
}

double Token::findNum(char elem) const {
    char nums[] = {'0','1','2','3','4','5','6','7','8','9'};
    double decimals[] = {0.0,1.0,2.0,3.0,4.0,5.0,6.0,7.0,8.0,9.0};
    for (int i = 0; i < 10; i++) {
        if (nums[i] == elem) return decimals[i];
    }
    return -1;
}

double Token::extractNumeric(const vector<char>& str_num) const {
    double num = 0.0, place;
    size_t i = 0, length = str_num.size();
    int dotIndex = find(str_num, '.');

    bool negative = str_num[0] == '-';
    if (negative) {
        dotIndex -= 1;
        i++;
    }
    
    if (dotIndex != -1) {
        int n = dotIndex;
        place = pow(10.0, n - 1);
    }
    else {
        place = pow(10.0, length - 1);
    }
    
    for (; i < length; i++) {
        if (str_num[i] == '.') continue;
        double digit = findNum(str_num[i]);
        if (digit == -1) continue; // Handle unexpected characters gracefully
        num += digit * place;
        place /= 10;
    }

    if (negative) {
        num *= -1;
    }

    return num;
}
