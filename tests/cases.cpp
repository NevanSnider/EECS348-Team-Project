#include "../src/lexer.hpp"
#include "../src/evaluator.hpp"
#include <sstream>
#include <stdexcept>
#include "testing.hpp"
#include "cases.hpp"

void TC01 () {
    //                      whitespace tolerance
    const string expr = "( 3 + ( \t\n  4  *2)  )- 5";
    const string expected_tree = "((3 + (4 * 2)) - 5)";
    const double expected_value = 6;
    

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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
    const string expr = "(3-(4+1))*(64/4%3) ";
    const string expected_tree = "((3 - (4 + 1)) * ((64 / 4) % 3))";
    const double expected_value = -2;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC04 () {
    const string expr = "3+2+";

    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    
    try {
        auto tree = parse_expression(tokens);
    } catch (const invalid_argument& e){
        // expected result
        return;
    }

    ostringstream error;
    error << "Invalid expression '" << expr << "' not detected by parser.\n";
    throw logic_error(error.str());
}

void TC05 () {
    const string expr = "-4+2^3";
    const string expected_tree = "(-4 + (2 ** 3))";
    const double expected_value = 4;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC06 () {
    const string expr = "10/(5-5)";

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});

    try {
        vector<Token> tokens = lexer.tokenization();
        auto tree = parse_expression(tokens);
        double result = evaluate(tree);
    } catch (const invalid_argument& e){
        // expected result
        return;
    }

    ostringstream error;
    error << "Divide by zero in '" << expr << "' not detected.\n";
    throw logic_error(error.str());
}

void TC07 () {
    const string expr = "3+4*abc";

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});

    try {
        vector<Token> tokens = lexer.tokenization();
        auto tree = parse_expression(tokens);
        double result = evaluate(tree);
    } catch (const invalid_argument& e){
        // expected result
        return;
    }

    ostringstream error;
    error << "Invalid characters in '" << expr << "' not detected.\n";
    throw logic_error(error.str());
}

void TC08 () {
    const string expr = "42";
    const string expected_tree = "42";
    const double expected_value = 42;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC09 () {
    const string expr = "(((2+3)))+(((1+2)))";
    const string expected_tree = "((2 + 3) + (1 + 2))";
    const double expected_value = 8;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC10 () {
    const string expr = "38%6";
    const string expected_tree = "(38 % 6)";
    const double expected_value = 2;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC11 () {
    const string expr = "-4**2";
    const string expected_tree = "-(4 ** 2)";
    const double expected_value = -16;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC12 () {
    const string expr = "-(-(-3)) + -(-4)";
    const string expected_tree = "(-(-(-3)) + -(-4))";
    const double expected_value = 1;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC13 () {
    const string expr = "+2 ** -3";
    const string expected_tree = "+(2 ** -3)";
    const double expected_value = 0.125;

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});
    vector<Token> tokens = lexer.tokenization();
    auto tree = parse_expression(tokens);

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

void TC14 () {
    const string expr = "2*(4+3-1";

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});

    try {
        vector<Token> tokens = lexer.tokenization();
        auto tree = parse_expression(tokens);
        double result = evaluate(tree);
    } catch (const invalid_argument& e){
        // expected result
        return;
    }

    ostringstream error;
    error << "Unmatched parenthesis in '" << expr << "' not detected.\n";
    throw logic_error(error.str());
}

void TC15 () {
    const string expr = "((2 -) 1 + 3)";

    // Test lexer and parser together
    Lexer lexer = Lexer({expr});

    try {
        vector<Token> tokens = lexer.tokenization();
        auto tree = parse_expression(tokens);
        double result = evaluate(tree);
    } catch (const invalid_argument& e){
        // expected result
        return;
    }

    ostringstream error;
    error << "Bad operator placement in '" << expr << "' not detected.\n";
    throw logic_error(error.str());
}
