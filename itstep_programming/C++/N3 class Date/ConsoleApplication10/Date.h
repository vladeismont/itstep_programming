#pragma once
#include "iostream"
#include "string"
class Date
{
private:
	int month, day, year;
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
};

