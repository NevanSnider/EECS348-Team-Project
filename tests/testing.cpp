#include "testing.hpp"
#include "cases.hpp"
#include <memory>
#include <sstream>

string tokens_repr(vector<Token> tokens) {
    ostringstream oss;

    for (Token token : tokens) {
        switch (token.getType()) {
            case 'l':
            case 'r':
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
        {"TCO1", TC01}
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
