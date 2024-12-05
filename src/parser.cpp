#include "parser.hpp"
#include <iostream>
#include <memory>
#include <vector>

/*********************
 * Parsing functions *
 *********************/

ExpressionTree* parse_expression(std::vector<Token> tokens) {
    // parse implementation here

    ExpressionTree* exp = new ExpressionTree(tokens[0]);
    return exp;
}

/********************
 * Dsplay functions *
 ********************/

void ExpressionTree::printInOrder(std::ostream& out) const {
    if (token.getType() == Token::Type::OPERATOR) out << "(";
    getLHS()->printInOrder(out);           
    out << token.display();                     
    getRHS()->printInOrder(out);         
    if (token.getType() == Token::Type::OPERATOR) out << ")";
}

void ExpressionTree::printExpression(std::ostream& out = std::cout) const {
    printInOrder(out);
    out << std::endl;
}

/*******************
 * Getters/Setters *
 *******************/

void ExpressionTree::setNode(Token tkn) {
    token = tkn;
}

Token ExpressionTree::getNode() const {
    return token;
}

void ExpressionTree::setLHS(std::shared_ptr<ExpressionTree> subtree) {
    left = subtree;
}

std::shared_ptr<ExpressionTree> ExpressionTree::getLHS() const {
    return left;
}

void ExpressionTree::setRHS(std::shared_ptr<ExpressionTree> subtree) {
    right = subtree;
}

std::shared_ptr<ExpressionTree> ExpressionTree::getRHS() const {
    return right;
}
