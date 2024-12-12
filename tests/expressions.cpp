#include "../src/lexer.hpp"
#include "../src/token.hpp"
#include "../src/parser.hpp"
#include <iostream>
#include <iterator>
#include <memory>
#include <sstream>
#include <stdexcept>
#include <string>

struct Test {
    string name;
    void (*test_fn)();
};

void test_expression_1 () {
    const string expr = "(3+(4*2))-5";
    const string expected = "((3 + (4 * 2)) - 5)\n";

    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    std::shared_ptr<ExpressionTree> tree = parse_expression(tokens);

    ostringstream oss;
    tree->printExpression(oss);
    string repr = oss.str();

    if (expected != repr) {
        ostringstream oss;
        oss << "Expected: " << expected << endl;
        oss << "Actual:   " << repr << endl;
        throw logic_error(oss.str());
    }
}

int main () {
    Test tests[] = {
        {"TCO1", test_expression_1}
    };

    int pass_count = 0;

    for (Test& test : tests) {
        cout << "Test " << test.name << "...";

        try {
            test.test_fn();
            cout << " PASS" << endl;
            pass_count++;
        } catch (const logic_error& e) {
            cout << " FAIL" << endl;
            cout << e.what() << endl;
        }
    }

    cout << "Passed " << pass_count << " / " << size(tests) << " tests." << endl;
}
