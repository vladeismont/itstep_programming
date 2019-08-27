#pragma once
#include "Automobile.h"
//static int count=0;
class Taxi:public Automobile
{
	double rate = 3.1;
	double allTheMoney = 0;
	static int count;
public:
	Taxi(const std::string s1, const std::string s2, const int i1, const double d1)
		:Automobile(s1, s2, i1, d1) { count++; };
	~Taxi();
	void setRate(const double);
	double getSum()const;
	double taxRate(const double);
	static int getCountTaxi(); //{	return count;};
	void getInfo()const;
	void move();
};

