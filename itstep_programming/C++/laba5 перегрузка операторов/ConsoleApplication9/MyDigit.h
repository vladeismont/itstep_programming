#pragma once

class MyDigit
{
	int digit_;
	static int counter;
public:
	MyDigit();
	MyDigit(int n);
	MyDigit(double n);
	MyDigit(const MyDigit& obj);

	void setDigit(int n);
	int getDigit() const;

	void showDigitNumbers();
	MyDigit operator-(); //�������
	MyDigit operator+(const MyDigit& newMyDigit); //��������
	MyDigit operator-(const MyDigit& newMyDigit);
	MyDigit operator*(const MyDigit& newMyDigit);
	MyDigit operator*(const int);
	MyDigit operator/(const MyDigit& newMyDigit);
	MyDigit operator/(const int);
	MyDigit operator%(const MyDigit& newMyDigit);
	MyDigit operator%(const int);
	bool operator<(const MyDigit& newMyDigit);
	bool operator>(const MyDigit& newMyDigit);
	bool operator==(const MyDigit& newMyDigit);
	bool operator!=(const MyDigit& newMyDigit);
	MyDigit operator++(); //���������� �����
	MyDigit operator--();
	MyDigit operator++(int n); //����������� �����
	MyDigit operator--(int n);
	MyDigit operator+=(const MyDigit& newMyDigit);
	MyDigit operator-=(const MyDigit& newMyDigit);
	MyDigit operator*=(const MyDigit& newMyDigit);
	MyDigit operator/=(const MyDigit& newMyDigit);
	~MyDigit();
};

