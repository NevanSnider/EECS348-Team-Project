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

class ExpressionTree {
private:
    Token token;
    std::shared_ptr<ExpressionTree> left;  
    std::shared_ptr<ExpressionTree> right;

    /**
     * Recursive function to print the tree in infix notation
     */
    void printInOrder(const std::shared_ptr<ExpressionTree>& node, std::ostream& out) const; 

public:
    /**
     * Create an ExpressionTree with a single node
     */
    ExpressionTree(Token token) : token(token), left(nullptr), right(nullptr) {}

    /**
     * Print the ExpressionTree in infix notation
     */
    void printExpression(std::ostream& out) const; 

    /**
     * Set the value of this node's token
     */ 
    void setNode(Token token);

    /**
     * Get the token stored in this node
     */ 
    Token getNode();

    /**
     * Set this node's left subtree
     */
    void setLHS(std::shared_ptr<ExpressionTree> subtree);

    /**
     * Get this node's left subtree 
     */
    std::shared_ptr<ExpressionTree> getLHS();

    /**
     * Set this node's right subtree
     */
    void setRHS(std::shared_ptr<ExpressionTree> subtree);

    /**
     * Get this node's right subtree
     */
    std::shared_ptr<ExpressionTree> getRHS();
};

#endif 
