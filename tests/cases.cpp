#include "../src/lexer.hpp"
#include <sstream>
#include <stdexcept>
#include "testing.hpp"
#include "cases.hpp"

void TC01 () {
    const string expr = "(3+(4*2))-5";
    const string expected_tree = "((3 + (4 * 2)) - 5)";

    // Test lexer and parser together
    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    shared_ptr<ExpressionTree> tree = parse_expression(tokens);
    delete lexer;
    string repr = tree_repr(tree);
    if (expected_tree != repr) {
        ostringstream error;
        error << "Expected: " << expected_tree << endl;
        error << "Actual:   " << repr << endl;
        throw logic_error(error.str());
    }
}

void TC02 () {
    const string expr = "(-5)**2+(-5)**2";
    const string expected_tree = "(((-5) ** 2) + ((-5) ** 2))";

    // Test lexer and parser together
    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    shared_ptr<ExpressionTree> tree = parse_expression(tokens);
    delete lexer;
    string repr = tree_repr(tree);
    if (expected_tree != repr) {
        ostringstream error;
        error << "Expected: " << expected_tree << endl;
        error << "Actual:   " << repr << endl;
        throw logic_error(error.str());
    }
}

void TC03 () {
    const std::string expr = "-5*(3+(-2))^2";
    const std::string expected_tree = "((-5) * ((3 + (-2)) ** 2))";

    // Test lexer and parser together
    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    shared_ptr<ExpressionTree> tree = parse_expression(tokens);
    delete lexer;
    string repr = tree_repr(tree);
    if (expected_tree != repr) {
        ostringstream error;
        error << "Expected: " << expected_tree << endl;
        error << "Actual:   " << repr << endl;
        throw logic_error(error.str());
    }
}
