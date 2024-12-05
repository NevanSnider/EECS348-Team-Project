#include "expression_tree.hpp" // includes ExpressionTree header file
#include <iostream>
#include <string>
#include <cmath> // to do exponentiation and modulo??

using namespace std; // to avoid repeating std::

void operation(shared_ptr<ExpressionNode>& node) {
    double leftVal = stod(node->left->token.display()); //check if valid?
    double rightVal = stod(node->right->token.display()); // check if valid?
    node->left= nullptr; // should remove children
    node->right=nullptr;
    char op = node->token.getValue(); // should be an operator

    switch (op) { // replace parent with value of children
        case '+': 
            node->value = leftVal + rightVal; 
            break;
        case '-':
            node->value = leftVal - rightVal;
            break;
        case '*':
            node->value = leftVal * rightVal;
        case '/':
            if (rightVal != 0) node->token = leftVal / rightVal;
            break;
        case '%':
            node->value = leftVal % rightVal; // fmod(leftVal, rightVal);
            break;
        case '^':
            node->value = pow(leftVal, rightVal);
            break;
        default:
            throw std::invalid_argument("recieved invalid operator");
    }
}

// evaluates by in-order recursion
shared_ptr<ExpressionNode> evaluator(shared_ptr<ExpressionNode>& node){
    if (node->left == nullptr && node->right == nullptr) return node;
    
    // if left node is an operator: go to left child
    if (node->left->token.getType() == Token::Type::OPERATOR) return evaluator(node->left);

    // replace the parent node with the expression evaluated with left and right child
    operation(node);

    // if right node is an operator: go to right child
    if (node->right->token.getType() == Token::Type::OPERATOR) return evaluator(node->right);

    return node; // assume the last node remaining stores the value of the answer
}

void evaluate(shared_ptr<ExpressionNode>& node) {
    if (!node) {
        return;
    } else {
        evaluator(node); // should call recursive function to evaluate expression
    }
}
  

