#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath> // to do exponentiation and modulo

#include "evaluator.hpp"
#include "parser.hpp"
#include "token.hpp"

using namespace std; // to avoid repeating std::

// helper function to convert double values to vector<char>
vector<char> doubletoCharVector(double value) {
    string str = to_string(value);

    size_t dotPos = str.find('.');
    if (dotPos != string::npos) {
        str = str.substr(0, dotPos + 6); // limits to 5 digit decimal precision
    }

    vector<char> result(str.begin(), str.end());
    return result;
}

// performs operation
void operation(shared_ptr<ExpressionTree>& node) {
    if (!node->getLHS() || !node->getRHS()) throw invalid_argument("Invalid tree structure: missing children");

    double leftVal = node->getLHS()->getNode().getValue();
    double rightVal = node->getRHS()->getNode().getValue();
    char op = node->getNode().getOp(); // should be an operator

    double result;
    switch (op) { 
        case '+': result = leftVal + rightVal; break;
        case '-': result = leftVal - rightVal; break;
        case '*': result = leftVal * rightVal; break;
        case '/':
            if (rightVal != 0) { 
                result = leftVal / rightVal;
            } else {
                throw invalid_argument("Division by zero");
            }
            break;
        case '%':
            if (rightVal != 0) {
                result = fmod(leftVal, rightVal);
            } else {
                throw invalid_argument("Modulo by zero");
            }
            break;
        case '^': result = pow(leftVal, rightVal); break;
        default:
            throw invalid_argument("Received invalid operator" + string(1, op));
    }

    // replace node token with evaluation of children
    node->setNode(Token(doubletoCharVector(result), 'v'));
}

// evaluates by post-order recursion: don't need return because it changes the node's value
void evaluator(shared_ptr<ExpressionTree>& node){
    if (!node) return;

    // checks if it traversed to a leaf
    if (node->getLHS() == nullptr && node->getRHS() == nullptr) return;

    // go to left child
    if (node->getLHS()) evaluator(node->getLHS());

    // go to right child
    if (node->getRHS()) evaluator(node->getRHS());

    // replace the parent node with the expression evaluated with left and right child
    operation(node);
}

void evaluate(shared_ptr<ExpressionTree>& node) {
    if (!node) {
        throw invalid_argument( "Expression tree is empty." );
        return;
    } else {
        evaluator(node); // should call recursive function to evaluate expression
    }
}
