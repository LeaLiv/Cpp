#pragma once
class Calculator
{
private:
	double firstNum;
	double secondNum;
public:
	double add();
	double subtract();
	double multiply();
	double divide();
	Calculator(double val1, double val2);

};

