#ifndef EXPRESSION_TREE_HPP
#define EXPRESSION_TREE_HPP

#include <iostream>
#include <memory>
#include <string>

enum class NodeType {
    OPERATOR,  
    OPERAND    
};

// Structure for an Expression Tree Node
struct ExpressionNode {
    NodeType type;                 
    std::string value;             
    std::shared_ptr<ExpressionNode> left;  
    std::shared_ptr<ExpressionNode> right; 

    // Constructor
    ExpressionNode(NodeType type, const std::string& value)
        : type(type), value(value), left(nullptr), right(nullptr) {}
};

// Expression Tree Class
class ExpressionTree {
private:
    std::shared_ptr<ExpressionNode> root; 

    // Recursive function to print the tree in infix notation
    void printInOrder(const std::shared_ptr<ExpressionNode>& node, std::ostream& out) const {
        if (!node) return;

        if (node->type == NodeType::OPERATOR) out << "(";
        printInOrder(node->left, out);           
        out << node->value;                     
        printInOrder(node->right, out);         
        if (node->type == NodeType::OPERATOR) out << ")";
    }

public:
    // Constructor
    ExpressionTree() : root(nullptr) {}

    // Set the root of the tree
    void setRoot(const std::shared_ptr<ExpressionNode>& rootNode) {
        root = rootNode;
    }

    // Print the expression tree in infix notation
    void printExpression(std::ostream& out = std::cout) const {
        printInOrder(root, out);
        out << std::endl;
    }

    // Get the root node for evaluation purposes
    std::shared_ptr<ExpressionNode> getRoot() const {
        return root;
    }
};

#endif 
