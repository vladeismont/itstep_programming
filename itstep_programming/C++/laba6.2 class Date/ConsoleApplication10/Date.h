#pragma once
#include "iostream"
#include "string"
class Date
{
private:
	int month, day, year;
	int hour, minute, second;
public:
	Date();
	~Date();
	Date(int,int,int);
	void setDay(int);
	void setMonth(int);
	void setYear(int);
	void setDate(int, int, int);
	void showDate();
	void initDMY(int, int, int);
	void initMDY(int, int, int);
	void increaseYear(const int);
	void increaseMonth(int);
	void increaseDay(int);

	//продолжение
	Date(int m, int d, int y, int h, int min, int s);
	void increaseSecond(int s);
	void showNewDate();
	friend std::ostream& operator<<(std::ostream& os, const Date& dt);
	friend std::istream& operator>>(std::istream& is, Date& dt);
	Date operator()(int m, int d, int y, int h, int min, int s);
	Date operator++();
	Date operator++(int n);
	bool operator!=(const Date& vD);
	bool operator==(const Date& vD);
	bool operator>(const Date& vD);
	bool operator<(const Date& vD);
	Date operator=(const Date& vD);
};

