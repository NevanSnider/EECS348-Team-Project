#include "parser.hpp"
#include <memory>
#include <stack>
#include <stdexcept>

/*********************
 * Parsing functions *
 *********************/

bool left_associative(Token const& token) {
    if (token.getType() != 'o' && token.getType() != 'u') {
        return false;
    }
    return !(token.getOp() == '^' || token.getType() == 'u');
}

// Converts tokens to postfix using Dijkstra's shunting yard algorithm.
std::vector<Token> postfix_notation (std::vector<Token> const& tokens) {
    std::vector<Token> output;
    std::stack<Token> ops;

    // process each token
    for (Token token : tokens) {
        switch (token.getType()) {
            case 'v': {
                output.push_back(token);
                break;
            }
            case 'o':
            case 'u': {
                while (!ops.empty() && ops.top().getType() != 'l') {
                    int o1_priority = token.getPriority();
                    int o2_priority = ops.top().getPriority();
                    if (
                        o1_priority > o2_priority ||
                        (o1_priority == o2_priority && 
                        left_associative(token))
                    ) {
                        output.push_back(ops.top());
                        ops.pop();
                    } else {
                        break;
                    }
                }

                ops.push(token);
                break;
            }
            case 'l': {
                ops.push(token);
                break;
            }
            case 'r': {
                bool matched = false;
                while (!ops.empty()) {
                    Token next = ops.top();
                    ops.pop();

                    if (next.getType() == 'l') {
                        matched = true;
                        break;
                    }

                    output.push_back(next);
                }

                if (!matched) {
                    throw invalid_argument("mismatched parentheses");
                }
                break;
            }
        }
    }

    // pop remaining operators
    while (!ops.empty()) {
        Token next = ops.top();
        ops.pop();

        // should be no parentheses left
        if (next.getType() == 'l' || next.getType() == 'r') {
            throw invalid_argument("mismatched parentheses");
        } else {
            output.push_back(next);
        }
    }

    return output;
}

// Recursively create a subtree from a vector in postfix notation.
std::shared_ptr<ExpressionTree> create_subtree(
    std::vector<Token> const& tokens,
    int* last_index_ptr
) {
    if (*last_index_ptr < 0) {
        throw invalid_argument("invalid expression");
    }

    // Read root token and decrement
    Token token = tokens[(*last_index_ptr)--];

    std::shared_ptr<ExpressionTree> subtree = std::make_shared<ExpressionTree>(token);

    // If it's an operator, look for operands
    if (token.getType() == 'o') {
        subtree->setRHS(create_subtree(tokens, last_index_ptr));
        subtree->setLHS(create_subtree(tokens, last_index_ptr));
    } else if (token.getType() == 'u') { // added to handle unary 
        subtree->setRHS(create_subtree(tokens, last_index_ptr));
        // unary operators usually only have one operand
    }

    return subtree;
}

std::shared_ptr<ExpressionTree> parse_expression(std::vector<Token> const& tokens) {
    std::vector<Token> postfix = postfix_notation(tokens);

    int last_index = postfix.size() - 1;
    auto tree = create_subtree(postfix, &last_index);
    if (last_index >= 0) {
        // not all tokens were used
        throw invalid_argument("invalid expression");
    }
    return tree;
}

/*********************
 * Display functions *
 *********************/

void ExpressionTree::printInOrder(std::ostream& out) {
    if (token.getType() == 'o' || token.getType() == 'u') {
        if (token.getType() == 'u') {
            out << token.getOp(); 
            bool also_unary = getRHS()->getNode().getType() == 'u';
            if (also_unary)
                out << '(';
            getRHS()->printInOrder(out);
            if (also_unary)
                out << ')';
        } else {
            out << '(';
            getLHS()->printInOrder(out);
            out << ' ';
            char op = token.getOp();
            
            if (op == '^') {
                out << "**";
            } else {
                out << op;
            }

            out << ' ';
            getRHS()->printInOrder(out);   
        }
    } else {
        out << token.getValue();
    }
    if (token.getType() == 'o') {
        out << ')';
    }
}

void ExpressionTree::printExpression(std::ostream& out) {
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
