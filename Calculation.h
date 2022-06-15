#ifndef __CALCULATION_HPP
#define __CALCULATION_HPP

#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <cmath>
/// Този клас служи за пресмятането на формулите
///
/// В него има три функции, една за намирането на приоритета на операциите,
/// една за извършването на аритметчните операции и една за връщането на крайния резултат

/// Връща приоритета на дадена операция
int precedence(const char operation);

/// Пресмята аритметична операция - '+', '-', '*', '/' или '^'
double doOperation(double a, double b, char operation);

/// Приема пълният аритметичен израз и връща крайния резултат
std::string calculation(const std::string str);

#endif