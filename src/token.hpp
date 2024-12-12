// token.hpp
#ifndef TOKEN_HPP
#define TOKEN_HPP

#include <vector>
using namespace std;

class Token {
    private:
        char type;
        int priority;
        char op;
        double value;
        int sign;
    public:
        Token(const vector<char>& input, char t);
        
        char getType() const;
        char getOp() const;
        void setPriority(char op);
        int getPriority() const;
        void setValue(const vector<char>& input);
        double getValue() const;
        int find(const vector<char>& line, char elem) const;
        double findNum(char elem) const;
        double extractNumeric(const vector<char>& input) const;
};

#endif
