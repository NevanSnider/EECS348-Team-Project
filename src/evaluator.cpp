#include <iostream>
#include <string>
#include <stdexcept>
#include <cmath> // to do exponentiation and modulo

using namespace std; // to avoid repeating std::

void operation(shared_ptr<ExpressionTree>& node) {
    if (!node->getLHS() || !node->getRHS()) throw invalid_argument("Invalid tree structure: missing children");

    leftVal = node->getLHS()->getNode().getValue();
    rightVal = node->getLHS()->getNode().getValue();

    char op = node->getNode().getOp(); // should be an operator

    switch (op) { // replace node with evaluation of children
        case '+': 
            node->setNode(Value(leftVal + rightVal));
            break;
        case '-':
            node->setNode(Value(leftVal - rightVal));
            break;
        case '*':
            node->setNode(Value(leftVal * rightVal));
            break;
        case '/':
            if (rightVal != 0)
                { node->setNode(Value(leftVal / rightVal)); //floor division
            } else {
                throw invalid_argument("Division by zero");
            }
            break;
        case '%':
            node->setNode(Value( fmod(leftVal, rightVal) ));
            break;
        case '^':
            node->setNode(Value( pow(leftVal, rightVal) ));
            break;
        default:
            throw invalid_argument("Recieved invalid operator" + string(1, op));
    }
}

// evaluates by post-order recursion: don't need return because it changes the actual node rather than makes a copy?
void evaluator(shared_ptr<ExpressionTree>& node){
    if (!node) return;

    if (node->getLHS() == nullptr && node->getRHS() == nullptr) return;
    
    // if left node is an operator: go to left child
    if (node->getLHS()->getNode().getType() == Token::Type::OPERATOR) evaluator(node->getLHS());

    // if right node is an operator: go to right child
    if (node->getRHS()->getNode().getType() == Token::Type::OPERATOR) evaluator(node->getRHS());

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
  
