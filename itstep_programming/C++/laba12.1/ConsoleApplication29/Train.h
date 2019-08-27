#pragma once
#include "Vehicle.h"
class Train:public Vehicle
{
	int time;
	int taxrate = 3.0;
public:
	Train();
	double speed = 45.2;
	int getTime(int s) { time= ceil(s * 60 / speed); return ceil(s*60 / speed); }
	int getTax() { return taxrate*time; };
	~Train();
};

