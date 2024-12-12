#include "../src/token.hpp"
#include "../src/parser.hpp"
#include <memory>

struct Test {
    string name;
    void (*test_fn)();
};

string tokens_repr (vector<Token> tokens);
string tree_repr (shared_ptr<ExpressionTree> tree);
