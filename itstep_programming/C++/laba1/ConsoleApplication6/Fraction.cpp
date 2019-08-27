#include "stdafx.h"
#include "Fraction.h"


Fraction::Fraction()
{
}
void Fraction::getFraction(){
	std::cout << "введите числитель\n";
	std::cin >> numerator;
	std::cout << "введите знаменатель\n";
	std::cin >> denumerator;
}
void Fraction::printFraction(){
	std::cout <<"дробь:"<< numerator << "/" << denumerator << std::endl;
}
Fraction Fraction::multiply(Fraction a, Fraction b) {
	this->numerator = a.numerator*b.numerator;
	this->denumerator = a.denumerator*b.denumerator;
	return *this;
}
Fraction Fraction::division(Fraction a, Fraction b) {
	this->numerator = a.numerator*b.denumerator;
	this->denumerator = a.denumerator*b.numerator;
	return *this;
}
Fraction Fraction::addition(Fraction a, Fraction b) {
	if (a.denumerator == b.denumerator) {
		this->denumerator = a.denumerator;
		this->numerator = a.numerator + b.numerator;
	}
	else {
		this->numerator = a.numerator*b.denumerator+a.denumerator*b.numerator;
		this->denumerator = a.denumerator*b.denumerator;
	}
	return *this;
}
Fraction Fraction::subtraction(Fraction a, Fraction b) {
	if (a.denumerator == b.denumerator) {
		this->denumerator = a.denumerator;
		this->numerator = a.numerator - b.numerator;
	}
	else {
		this->numerator = a.numerator*b.denumerator - a.denumerator*b.numerator;
		this->denumerator = a.denumerator*b.denumerator;
	}
	return *this;
}
Fraction::~Fraction()
{
}
