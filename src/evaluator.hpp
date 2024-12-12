#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>

#include "parser.hpp"
#include "token.hpp"

using namespace std;

vector<char> doubletoCharVector(double value);
void operation(shared_ptr<ExpressionTree> node);
void evaluator(shared_ptr<ExpressionTree> node);
double evaluate(shared_ptr<ExpressionTree> node);

#endif