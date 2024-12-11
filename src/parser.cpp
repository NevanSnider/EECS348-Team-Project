#include "parser.hpp"

/*********************
 * Parsing functions *
 *********************/

ExpressionTree* parse_expression(std::vector<Token>& tokens) {
    // parse implementation here

    ExpressionTree* exp = new ExpressionTree(tokens[0]);
    return exp;
}

/********************
 * Dsplay functions *
 ********************/

void ExpressionTree::printInOrder(std::ostream& out) {
    if (token.getType() == 'o') {
        out << '(';
        getLHS()->printInOrder(out);
        out << ' ';
    }
    out << token.getType(); // token class still needs a display function             
    if (token.getType() == 'o') {
        out << ' ';
        getRHS()->printInOrder(out);         
        out << ')';
    }
}

void ExpressionTree::printExpression(std::ostream& out = std::cout) {
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
