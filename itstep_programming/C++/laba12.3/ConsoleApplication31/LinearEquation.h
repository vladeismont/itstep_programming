#pragma once
#include "Equation.h"
class LinearEquation
{
	double a = 1.3;
	double b = 2.6;	//1.3x+2.6=0
public:
	LinearEquation();
	double solve();
	~LinearEquation();
};

