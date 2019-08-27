#include "stdafx.h"
#include "Complex.h"


Complex::Complex()
{
}

Complex::Complex(double a, double b)
{
	a_ = a;
	b_ = b;
}


Complex::~Complex()
{
}

Complex Complex::operator+(const Complex & com)
{
	Complex vC;
	vC.a_ = a_ + com.a_;
	vC.b_ = b_ + com.b_;
	return vC;
}

Complex Complex::operator-(const Complex & com)
{
	Complex vC;
	vC.a_ = a_ - com.a_;
	vC.b_ = b_ - com.b_;
	return vC;
}

bool Complex::operator!=(const Complex & com)
{

	return (a_!=com.a_ && b_!=com.b_);
}

bool Complex::operator==(const Complex & com)
{
	return (a_ == com.a_ && b_ == com.b_);
}

Complex Complex::operator()(double a, double b)
{
	a_ = a;
	b_ = b;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Complex & com)
{
	os << com.a_ << ", " << com.b_;
	// TODO: insert return statement here
	return os;
}

std::istream & operator>>(std::istream & is, Complex & com)
{
	std::cout << "Enter complex 1-number: " << std::endl;
	is >> com.a_;
	std::cout << "Enter complex 2-number: " << std::endl;
	is >> com.b_;
	// TODO: insert return statement here
	return is;
}
