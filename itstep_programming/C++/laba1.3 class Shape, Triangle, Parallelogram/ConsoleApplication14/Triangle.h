#pragma once
#include "Shape.h"
#include <utility>
class Triangle:public Shape
{
	double a, b, c, alpha, beta, gamma;
	double area=0;
public:
	Triangle();
	void setABC(const double, const double, const double);
	double getArea();// { return 0; };
	Triangle(const double, const double, const double); //3 line
	Triangle(const std::pair<const double, const double>, double);//2 line and angle
	Triangle(const double, const std::pair<const double, const double>);//line and 2 angle
	Triangle(const Triangle&); //что должно происходить внутри???
	~Triangle();
};

