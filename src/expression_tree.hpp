#ifndef EXPRESSION_TREE_HPP
#define EXPRESSION_TREE_HPP

#include <iostream>
#include <memory>
#include <string>
/*#include "token.hpp"*/

// temporary mockup of what behavior the parser
// needs from the Token class to construct a tree
enum TokenRole {
    OPEN_GROUP,
    CLOSE_GROUP,
    CONSTANT,
    EXPONENT,
    MULTIPLY,
    ADD
};

class Token {
public:
    TokenRole getRole();
    std::string display();
};
// ---------------------

/**
 * Node of the expression tree 
 * contains a token and has its operands as children, if applicable
 */
struct ExpressionNode {
    Token token;
    std::shared_ptr<ExpressionNode> left;  
    std::shared_ptr<ExpressionNode> right; 

    ExpressionNode(Token token) : token(token), left(nullptr), right(nullptr) {}
};


class ExpressionTree {
private:
    std::shared_ptr<ExpressionNode> root; 

    /**
     * Recursive function to print the tree in infix notation
     */
    void printInOrder(const std::shared_ptr<ExpressionNode>& node, std::ostream& out) const; 

public:
    /**
     * Create an empty ExpressionTree
     */ 
    ExpressionTree() : root(nullptr) {}

    /**
     * Print the ExpressionTreeree in infix notation
     */
    void printExpression(std::ostream& out) const; 

    /**
     * Set the root node of the tree
     */ 
    void setRoot(const std::shared_ptr<ExpressionNode>& rootNode);

    /**
     * Get the root node of the tree
     */
    std::shared_ptr<ExpressionNode> getRoot() const;
};

#endif 
