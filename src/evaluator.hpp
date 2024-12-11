#ifndef EVALUATOR_HPP
#define EVALUATOR_HPP

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
#include <cmath>

using namespace std;

vector<char> doubletoCharVector(double value);
void operation(shared_ptr<ExpressionTree>& node);
void evaluator(shared_ptr<ExpressionTree>& node);
void evaluate(shared_ptr<ExpressionTree>& node);

#endif