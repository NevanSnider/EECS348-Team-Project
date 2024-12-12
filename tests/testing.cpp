#include "testing.hpp"
#include "cases.hpp"
#include <memory>
#include <sstream>

string tokens_repr(vector<Token> tokens, bool types_only) {
    ostringstream oss;

    for (Token token : tokens) {
        if (types_only) {
            oss << token.getType();
            continue;
        }

        switch (token.getType()) {
            case 'l':
            case 'r':
            case 'u':
            case 'o':
                oss << token.getOp();
                break;
            case 'v':
                oss << token.getValue();
                break;
        }
    }

    return oss.str();
}

string tree_repr(shared_ptr<ExpressionTree> tree) {
    ostringstream oss;

    tree->printExpression(oss);

    string str = oss.str();
    str.pop_back();
    return str;
}

int main () {
    Test tests[] = {
        {"TCO1", TC01},
        {"TCO2", TC02},
        {"TCO3", TC03}
    };

    int pass_count = 0;

    for (Test& test : tests) {
        std::cout << "Test " << test.name << "...";

        try {
            test.test_fn();
            std::cout << " PASS" << std::endl;
            pass_count++;
        } catch (const std::logic_error& e) {
            std::cout << " FAIL" << std::endl;
            std::cout << e.what() << std::endl;
        }
    }

    std::cout << "Passed " << pass_count << " / " << (sizeof(tests)/sizeof(Test)) << " tests." << std::endl;
}
