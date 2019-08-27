#include "stdafx.h"
#include "Parallelogram.h"
#include <cmath>
Parallelogram::Parallelogram()
{
}

Parallelogram::~Parallelogram()
{
}

Parallelogram::Parallelogram(const double a, const double b, const double angle)
{
	lineA = a;
	lineB = b;
	angle_ = angle;
	area = lineA*lineB*sin(angle*(4*atan(1.))/180);
}


double Parallelogram::getArea()
{
	return area;
}

Parallelogram::Parallelogram(const Parallelogram &p)
{
	(*this).lineA = p.lineA;
	(*this).lineB = p.lineB;
	this->angle_ = p.angle_;
	this->area = p.area;
}
