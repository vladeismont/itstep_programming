#include "stdafx.h"
#include "MyDigit.h"

int MyDigit::counter = 0;

MyDigit::MyDigit() : digit_(0)
{
	++counter;
}

MyDigit::MyDigit(int n) : digit_(n)
{
}

MyDigit::MyDigit(double n) : digit_(n)
{
}

MyDigit::MyDigit(const MyDigit& obj)
{
	digit_ = obj.digit_;
}

MyDigit::~MyDigit()
{
}

void MyDigit::setDigit(int n){
	++counter;
	digit_ = n;
}

int MyDigit::getDigit() const{
	return digit_;
}

void MyDigit::showDigitNumbers()
{
	std::cout << counter << std::endl;
}

MyDigit MyDigit::operator-(){
	MyDigit temp;
	temp.digit_ = -digit_;
	return temp;
}

/*MyDigit MyDigit::operator+(const MyDigit& newMyDigit){
	MyDigit temp;
	temp.digit_ = digit_ + newMyDigit.digit_;
	return temp;
}*/

/*MyDigit MyDigit::operator-(const MyDigit& newMyDigit){
MyDigit temp;
temp.digit_ = digit_ - newMyDigit.digit_;
return temp;
}*/

/*MyDigit MyDigit::operator*(const MyDigit& newMyDigit){
	MyDigit temp;
	temp.digit_ = digit_ * newMyDigit.digit_;
	return temp;
}*/

MyDigit MyDigit::operator*(const int n){
	digit_ = n*digit_;
	return *this;
}

/*MyDigit MyDigit::operator/(const MyDigit& newMyDigit){
	MyDigit temp;
	temp.digit_ = digit_ / newMyDigit.digit_;
	return temp;
}*/

MyDigit MyDigit::operator/(const int n){
	digit_ = digit_/n;
	return *this;
}

MyDigit MyDigit::operator%(const MyDigit& newMyDigit){
	MyDigit temp;
	temp.digit_ = digit_ % newMyDigit.digit_;
	return temp;
}

MyDigit MyDigit::operator%(const int n){
	digit_ = digit_ % n;
	return *this;
}

bool MyDigit::operator<(const MyDigit& newMyDigit){
	return digit_ < newMyDigit.digit_;
}

bool MyDigit::operator>(const MyDigit& newMyDigit){
	return digit_ > newMyDigit.digit_;
}

bool MyDigit::operator==(const MyDigit& newMyDigit){
	return (digit_ == newMyDigit.digit_);
}

bool MyDigit::operator!=(const MyDigit& newMyDigit){
	return (digit_ != newMyDigit.digit_);
}

MyDigit MyDigit::operator++(){ //префиксная форма
	++digit_;
	return *this;
}

MyDigit MyDigit::operator--(){
	--digit_;
	return *this;
}

MyDigit MyDigit::operator++(int n){ //постфиксная форма
	MyDigit temp = *this;
	++digit_;
	return temp;
}

MyDigit MyDigit::operator--(int n){
	MyDigit temp = *this;
	--digit_;
	return temp;
}

MyDigit MyDigit::operator+=(const MyDigit& newMyDigit){
	digit_ = digit_ + newMyDigit.digit_;
	return *this;
}

MyDigit MyDigit::operator+(const MyDigit& newMyDigit){
	MyDigit temp = *this;
	temp += newMyDigit;
	return temp;
}

MyDigit MyDigit::operator-=(const MyDigit& newMyDigit){
	digit_ = digit_ - newMyDigit.digit_;
	return *this;
}
MyDigit MyDigit::operator-(const MyDigit& newMyDigit) {
	MyDigit temp = *this;
	temp -= newMyDigit;
	return temp;
}

MyDigit MyDigit::operator*=(const MyDigit& newMyDigit){
	digit_ = digit_ * newMyDigit.digit_;
	return *this;
}

MyDigit MyDigit::operator*(const MyDigit& newMyDigit) {
	MyDigit temp = *this;
	temp *= newMyDigit;
	return temp;
}

MyDigit MyDigit::operator/=(const MyDigit& newMyDigit){
	digit_ = digit_ / newMyDigit.digit_;
	return *this;
}

MyDigit MyDigit::operator/(const MyDigit& newMyDigit) {
	MyDigit temp = *this;
	temp /= newMyDigit;
	return temp;
}