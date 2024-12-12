#include "../src/lexer.hpp"
#include <sstream>
#include <stdexcept>
#include "testing.hpp"
#include "cases.hpp"

void TC01 () {
    const string expr = "(3+(4*2))-5";
    const string expected = "((3 + (4 * 2)) - 5)";

    Lexer* lexer = new Lexer({expr});
    vector<Token> tokens = lexer->tokenization();
    string tokenized = tokens_repr(tokens);

    std::shared_ptr<ExpressionTree> tree = parse_expression(tokens);
    string parsed = tree_repr(tree);

    if (expected != parsed) {
        ostringstream oss;
        oss << "Expected: " << expected << endl;
        oss << "Actual:   " << parsed << endl;
        throw logic_error(oss.str());
    }
}
