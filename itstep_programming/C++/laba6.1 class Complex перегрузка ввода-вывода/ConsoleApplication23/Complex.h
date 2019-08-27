#pragma once
class Complex
{
	double a_, b_;
public:
	Complex();
	Complex(double a, double b);
	~Complex();
	friend std::ostream& operator<<(std::ostream& os, const Complex& com);
	friend std::istream& operator>>(std::istream& is, Complex& com);
	Complex operator+(const Complex& com);
	Complex operator-(const Complex& com);
	bool operator!=(const Complex& com);
	bool operator==(const Complex& com);
	Complex operator()(double a, double b);
};