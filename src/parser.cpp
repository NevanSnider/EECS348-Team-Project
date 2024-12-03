#include "expression_tree.hpp"
#include <iostream>
#include <vector>

ExpressionTree* parse(std::vector<Token>) {
    // parse implementation here

    ExpressionTree* exp = new ExpressionTree();
    return exp;
}

void ExpressionTree::printInOrder(const std::shared_ptr<ExpressionNode>& node, std::ostream& out) const {
    if (!node) return;

    if (node->token.getRole() > CONSTANT) out << "(";
    printInOrder(node->left, out);           
    out << node->token.display();                     
    printInOrder(node->right, out);         
    if (node->token.getRole() > CONSTANT) out << ")";
}

void ExpressionTree::printExpression(std::ostream& out = std::cout) const {
    printInOrder(root, out);
    out << std::endl;
}

void ExpressionTree::setRoot(const std::shared_ptr<ExpressionNode>& rootNode) {
    root = rootNode;
}

std::shared_ptr<ExpressionNode> ExpressionTree::getRoot() const {
    return root;
} 
