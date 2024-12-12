#include "../src/lexer.hpp"
#include <sstream>
#include <stdexcept>
#include "testing.hpp"
#include "cases.hpp"

void TC01 () {
    const std::string expr = "(3+(4*2))-5";
    const std::string expected = "((3 + (4 * 2)) - 5)\n";

    Lexer* lexer = new Lexer({expr});
    std::vector<Token> tokens = lexer->tokenization();
    std::shared_ptr<ExpressionTree> tree = parse_expression(tokens);

    std::ostringstream oss;
    tree->printExpression(oss);
    std::string repr = oss.str();

    if (expected != repr) {
        std::ostringstream error;
        error << "Expected: " << expected << std::endl;
        error << "Actual:   " << repr << std::endl;
        delete lexer;
        throw std::logic_error(error.str());
    }

    std::cout << "Actual: " << repr;
    delete lexer;
}

void TC02 () {
    const std::string expr = "-3+(4*-2)";
    const std::string expected = "((-3) + (4 * (-2)))\n";

    Lexer* lexer = new Lexer({expr});
    std::vector<Token> tokens = lexer->tokenization();
    std::shared_ptr<ExpressionTree> tree = parse_expression(tokens);

    std::ostringstream oss;
    tree->printExpression(oss);
    std::string repr = oss.str();

    if (expected != repr) {
        std::ostringstream error;
        error << "Expected: " << expected << std::endl;
        error << "Actual:   " << repr << std::endl;
        delete lexer;
        throw std::logic_error(error.str());
    }

    std::cout << "Actual: " << repr;
    delete lexer;
}

void TC03 () {
    const std::string expr = "-4+6(9+1)";
    const std::string expected = "((-4) + (6 * (9 + 1)))\n";

    Lexer* lexer = new Lexer({expr});
    std::vector<Token> tokens = lexer->tokenization();
    std::shared_ptr<ExpressionTree> tree = parse_expression(tokens);

    std::ostringstream oss;
    tree->printExpression(oss);
    std::string repr = oss.str();

    if (expected != repr) {
        std::ostringstream error;
        error << "Expected: " << expected << std::endl;
        error << "Actual:   " << repr << std::endl;
        delete lexer;
        throw std::logic_error(error.str());
    }

    std::cout << "Actual: " << repr;
    delete lexer;
}


