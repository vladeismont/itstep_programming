#pragma once
#include "Shape.h"
class Parallelogram:public Shape
{
	double lineA, lineB, angle_, area=0;
public:
	Parallelogram();
	Parallelogram(const double, const double, const double);
	double getArea();
	Parallelogram(const Parallelogram &); //copy constructor
	~Parallelogram();
};

