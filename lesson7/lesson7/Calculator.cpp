#include "Calculator.h"

double Calculator::add()
{
    return firstNum+secondNum;
}

double Calculator::subtract()
{
    return firstNum-secondNum;
}

double Calculator::multiply()
{
    return firstNum*secondNum;
}

double Calculator::divide()
{
    if (secondNum == 0)
        throw "error: can not divide by zero";
    return firstNum/secondNum;
}

Calculator::Calculator(double val1, double val2)
{
    firstNum = val1;
    secondNum = val2;
}
