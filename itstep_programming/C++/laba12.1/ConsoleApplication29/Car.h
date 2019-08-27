#pragma once
#include "Vehicle.h"
class Car:public Vehicle
{
	int time;
	int taxrate=2.3;
public:
	Car();
	int getTime(int s) { time = ceil(s * 60 / speed); return ceil(s * 60 / speed); }
	int getTax() { return taxrate*time; };
	double speed = 37.4;
	~Car();
};

