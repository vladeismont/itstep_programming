#pragma once
#include "Vehicle.h"
class Bike:public Vehicle
{
	int time;
	int taxrate = 1;
public:
	Bike();
	double speed = 4.4;
	int getTime(int s) { time = ceil(s * 60 / speed); return ceil(s * 60 / speed); }
	int getTax() { return taxrate*time; };
	~Bike();
};

