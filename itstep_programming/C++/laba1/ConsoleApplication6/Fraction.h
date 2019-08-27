#pragma once
#include "iostream"
class Fraction
{
	int numerator, denumerator;
public:
	
	Fraction();
	Fraction subtraction(Fraction a, Fraction b);
	Fraction addition(Fraction a, Fraction b);
	Fraction multiply(Fraction a, Fraction b);
	Fraction division(Fraction a, Fraction b);
	void getFraction();
	void printFraction();
	~Fraction();
};

