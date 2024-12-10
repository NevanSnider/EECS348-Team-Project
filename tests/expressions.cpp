#include "../src/lexer.hpp"
#include "../src/token.hpp"
#include "../src/parser.hpp"
#include <iostream>
#include <string>

struct Test {
    string name;
    void (*test_fn)();
};

void test_expression_1 () {
    const string expr = "(3+(4*2))-5";

    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    ExpressionTree* tree = parse_expression(tokens);

    tree->printExpression(cout);
}

int main () {
    Test tests[] = {
        {"Expression 1", test_expression_1}
    };

    for (Test& test : tests) {
        cout << "Test " << test.name << "..." << endl;

        try {
            test.test_fn();
            cout << "Test " << test.name << ": PASS" << endl;
        } catch (error_t) {
            cout << "Test " << test.name << ": FAIL" << endl;
        }
    }
}
