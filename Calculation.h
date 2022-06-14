#ifndef __CALCULATION_HPP
#define __CALCULATION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>

int precedence(const char operation);

double doOperation(double a, double b, char operation);

std::string calculation(const std::string str);

#endif