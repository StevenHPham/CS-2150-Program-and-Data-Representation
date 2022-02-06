#ifndef  POSTFIXCALCULATOR_H
#define  POSTFIXCALCULATOR_H

#include <iostream>
#include "stack.h"
#include <string>
using namespace std;

bool isOperator(const string& signage);
void rpn(const string& signage, stack& rpnStack);

#endif
