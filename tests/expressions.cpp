#include "../src/lexer.hpp"
#include "../src/token.hpp"
#include "../src/parser.hpp"
#include <cassert>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>

struct Test {
    string name;
    void (*test_fn)();
};

void test_expression_1 () {
    const string expr = "(3+(4*2))-5";

    Lexer* lexer = new Lexer({expr});
    cout << "Tokenizing..." << endl;
    vector<Token> tokens = lexer->tokenization();
    cout << "Parsing..." << endl;
    std::shared_ptr<ExpressionTree> tree = parse_expression(tokens);

    ostringstream oss;
    tree->printExpression(oss);
    cout << oss.str();
    assert(oss.str() == "((3 + (4 * 2)) - 5)");
}

int main () {
    Test tests[] = {
        {"TCO1", test_expression_1}
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
