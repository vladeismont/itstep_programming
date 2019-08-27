#include "stdafx.h"
#include "Circle.h"


Circle::Circle()
{
}


/*Circle::~Circle() // =default;
{
}*/

Circle::Circle(double r, double x, double y){
	radius_ = r;
	x_ = x;
	y_ = y;
}
void Circle::setCircle(double r, double x, double y){
	radius_ = r;
	x_ = x;
	y_ = y;
}

bool Circle::operator==(const Circle& obj) const{
	return radius_ == obj.radius_;
}

bool Circle::operator>(const Circle& obj) const{
	return radius_ > obj.radius_;
}

bool Circle::operator<(const Circle& obj) const{
	return radius_ < obj.radius_;
}

Circle& Circle::operator+=(const double x){
	radius_ += x;
	return *this;
}

Circle& Circle::operator-=(const double x){
	radius_ -= x;
	return *this;
}

double Circle::getRadius() const{
	return radius_;
}

void Circle::operator()(double r, double x, double y){
	radius_ = r;
	x_ = x;
	y_ = y;
}
double Circle::getArea()const{
	//long double Pi = 4 * atan(1.); /grad = rad * (180/pi);
	return (4 * atan(1)*radius_*radius_);
}

double Circle::getLength()const{
	return 2 * radius_*(4 * atan(1));
}