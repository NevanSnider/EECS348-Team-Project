#ifndef PARSER_HPP
#define PARSER_HPP

#include <iostream>
#include <memory>
#include <vector>
#include "token.hpp"

class ExpressionTree {
private:
    Token token;
    std::shared_ptr<ExpressionTree> left;  
    std::shared_ptr<ExpressionTree> right;

    /**
     * Recursive function to print the tree in infix notation
     */
    void printInOrder(std::ostream& out); 

public:
    /**
     * Create an ExpressionTree with a single node
     */
    ExpressionTree(Token token) : token(token), left(nullptr), right(nullptr) {}

    /**
     * Print the ExpressionTree in infix notation
     */
    void printExpression(std::ostream& out); 

    /**
     * Set the value of this node's token
     */ 
    void setNode(Token token);

    /**
     * Get the token stored in this node
     */ 
    Token getNode() const;

    /**
     * Set this node's left subtree
     */
    void setLHS(std::shared_ptr<ExpressionTree> subtree);

    /**
     * Get this node's left subtree 
     */
    std::shared_ptr<ExpressionTree> getLHS() const;

    /**
     * Set this node's right subtree
     */
    void setRHS(std::shared_ptr<ExpressionTree> subtree);

    /**
     * Get this node's right subtree
     */
    std::shared_ptr<ExpressionTree> getRHS() const;
};

/**
 * Parse a given list of tokens into an Abstract Syntax Tree
 */
std::shared_ptr<ExpressionTree> parse_expression(std::vector<Token> const& tokens);

#endif 
