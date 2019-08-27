// ConsoleApplication29.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Vehicle.h"
#include "Train.h"
#include "Car.h"
#include "Bike.h"
int main()
{
	Train obj;
	obj.getTime(20);	//20km
	std::cout << obj.getTime(20) << " minutes" << std::endl;
	std::cout << obj.getTax() <<" rubley"<< std::endl;
	Car obj1;
	Bike obj2;
	system("pause");
    return 0;
}

