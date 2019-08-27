#pragma once
#include "Equation.h"
class QuadraticEquation
{
	//Ax2+Bx+C=0
	double a = 1;
	double b = 0;
	double c = -25;		// x2-25=0
public:
	QuadraticEquation();
	double solve();
	~QuadraticEquation();
};

