#include "stdafx.h"
#include "Triangle.h"
#include <cmath>
Triangle::Triangle()
{
}
Triangle::~Triangle()
{
}
void Triangle::setABC(const double x, const double y, const double z) {
	a = x;
	b = y;
	c = z;
}
double Triangle::getArea()
{
	return area;
}
Triangle::Triangle(const double aa, const double bb, const double cc) {
	(*this).a = aa;
	this->b = bb;
	c = cc;
	area = sqrt((a + b + c) / 2 * ((a + b + c) / 2 - a)*((a + b + c) / 2 - b)*((a + b + c) / 2 - c));
}
Triangle::Triangle(const std::pair<const double, const double>p, const double angle) {
	a = p.first;
	b = p.second;
	alpha = angle;
	area = p.first*p.second*sin(angle * (4 * atan(1)) / 180) / 2;;
}

Triangle::Triangle(const double aa, const std::pair<const double, const double>angles) {
	a = aa;
	alpha = angles.first;
	beta = angles.second;//grad = rad * (180/pi);//long double Pi = 4 * atan(1.); rad=angles*(4 * atan(1.))/180
	gamma = 180 - angles.first - angles.second;
	area=a*a*sin(angles.first*(4 * atan(1.)) / 180)*sin(angles.second*(4 * atan(1.)) / 180)/2/sin(gamma*(4 * atan(1.)) / 180);
}