#include "../src/lexer.hpp"
#include "../src/evaluator.hpp"
#include <sstream>
#include <stdexcept>
#include "testing.hpp"
#include "cases.hpp"

void TC01 () {
    const string expr = "(3+(4*2))-5";
    const string expected_tree = "((3 + (4 * 2)) - 5)";
    const double expected_value = 6;
    

    // Test lexer and parser together
    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    shared_ptr<ExpressionTree> tree = parse_expression(tokens);
    delete lexer;
    string repr = tree_repr(tree);
    if (expected_tree != repr) {
        ostringstream error;
        error << "Parse Failure" << endl;
        error << "Expected: " << expected_tree << endl;
        error << "Actual:   " << repr << endl;
        throw logic_error(error.str());
    }

    // Evaluate
    double result = evaluate(tree);
    if (result != expected_value) {
        ostringstream error;
        error << "Evaluation Failure" << endl;
        error << "Expected: " << expected_value << endl;
        error << "Actual:   " << result << endl;
        throw logic_error(error.str());
    }
}

void TC02 () {
    const string expr = "(-5)**2+(-5)**2";
    const string expected_tree = "((-5 ** 2) + (-5 ** 2))";
    const double expected_value = 50;

    // Test lexer and parser together
    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    shared_ptr<ExpressionTree> tree = parse_expression(tokens);
    delete lexer;
    string repr = tree_repr(tree);
    if (expected_tree != repr) {
        ostringstream error;
        error << "Parse Failure" << endl;
        error << "Expected: " << expected_tree << endl;
        error << "Actual:   " << repr << endl;
        throw logic_error(error.str());
    }

    // Evaluate
    double result = evaluate(tree);
    if (result != expected_value) {
        ostringstream error;
        error << "Evaluation Failure" << endl;
        error << "Expected: " << expected_value << endl;
        error << "Actual:   " << result << endl;
        throw logic_error(error.str());
    }
}

void TC03 () {
    const string expr = "-(+3+1)*(2-(3^2))";
    const string expected_tree = "(-(+3 + 1) * (2 - (3 ** 2)))";
    const double expected_value = 28;

    // Test lexer and parser together
    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    shared_ptr<ExpressionTree> tree = parse_expression(tokens);
    delete lexer;
    string repr = tree_repr(tree);
    if (expected_tree != repr) {
        ostringstream error;
        error << "Parse Failure" << endl;
        error << "Expected: " << expected_tree << endl;
        error << "Tokens:   " << tokens_repr(tokens) << endl;
        error << "Actual:   " << repr << endl;
        throw logic_error(error.str());
    }
    
    // Evaluate
    double result = evaluate(tree);
    if (result != expected_value) {
        ostringstream error;
        error << "Evaluation Failure" << endl;
        error << "Expected: " << expected_value << endl;
        error << "Actual:   " << result << endl;
        throw logic_error(error.str());
    }
}
