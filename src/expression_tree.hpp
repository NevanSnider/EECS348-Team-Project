#ifndef EXPRESSION_TREE_HPP
#define EXPRESSION_TREE_HPP

#include <iostream>
#include <memory>
#include <string>
/*#include "token.hpp"*/

// Temporary mockup of what behavior the parser
// needs from the Lexer to construct a tree.
// It doesn't have to look like this but this is the
// basic information needed for parsing.
class Token {
public:
    enum class Type {
        OPERATOR,
        OPERAND,
        LEFT_PARENTHESIS,
        RIGHT_PARENTHESIS
    };

    Type getType();
    std::string display();

    // These are only needed for operators
    int getPrecedence(); 
    bool isLeftAssociative();
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
