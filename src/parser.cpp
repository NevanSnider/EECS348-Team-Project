#include "parser.hpp"
#include <memory>
#include <stack>

/*********************
 * Parsing functions *
 *********************/

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
            case 'o': {
                while (!ops.empty() && ops.top().getType() != 'l') {
                    int priority = ops.top().getPriority();
                    if (priority <= token.getPriority() ||
                        (priority < token.getPriority() 
                        && ops.top().getOp() == '^')
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
                    output.push_back(next);

                    if (next.getType() == 'l') {
                        matched = true;
                        break;
                    }
                }

                if (!matched) {
                    // TODO: throw parsing error
                }
            }
        }
    }

    // pop remaining operators
    while (!ops.empty()) {
        Token next = ops.top();
        ops.pop();

        // should be no parentheses left
        if (next.getType() != 'o') {
            // TODO: throw parsing error
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
        // Incomplete expression
        // TODO: throw error
    }

    // Read root token and decrement
    Token token = tokens[*last_index_ptr--];
    ExpressionTree* subtree = new ExpressionTree(token);

    // If it's an operator, look for operands
    if (token.getType() == 'o') {
        subtree->setRHS(create_subtree(tokens, last_index_ptr));
        subtree->setLHS(create_subtree(tokens, last_index_ptr));
    }

    return std::shared_ptr<ExpressionTree>(subtree);
}

std::shared_ptr<ExpressionTree> parse_expression(std::vector<Token> const& tokens) {
    std::vector<Token> postfix = postfix_notation(tokens);

    int last_index = postfix.size() - 1;
    return create_subtree(postfix, &last_index);
}

/*********************
 * Display functions *
 *********************/

void ExpressionTree::printInOrder(std::ostream& out) {
    if (token.getType() == 'o') {
        out << '(';
        getLHS()->printInOrder(out);
        out << ' ';
        char op = token.getOp();
        
        if (op == '^') {
            out << "**";
        } else {
            out << op;
        }
    } else {
        out << token.getValue();
    }
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
