// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Automobile.h"
#include "Taxi.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL,"rus");
	Automobile vA("citroen","xsara",2003,37);
	vA.setAuto("citroen", "xsara", 2003, 37);

	std::cout << vA.getMark() << std::endl;
	std::cout << vA.getModel() << std::endl;
	std::cout << vA.getYearOfIssue() << std::endl;
	std::cout << vA.getMediumSpeed() << std::endl;
	vA.setMediumSpeed(33);
	std::cout << vA.getMediumSpeed() << std::endl;
	std::cout << vA.computeDistance(30) << std::endl;
	Taxi vT1("citroen", "xsara", 2003, 37);
	std::cout << vT1.computeDistance(30) << std::endl; //30 минут
	vT1.setRate(0.8); //0.8 рублей за км
	std::cout << vT1.taxRate(15) <<" рублей."<< std::endl; //15 minutes
	Taxi vT2("citroen", "xsara", 2003, 37);
	Taxi vT3("citroen", "xsara", 2003, 37);
	Taxi vT4("citroen", "xsara", 2003, 37);
	Taxi vT5("citroen", "xsara", 2003, 37);
	std::cout <<"количество машин такси: "<< Taxi::getCountTaxi() << std::endl;
	std::cout << vT1.taxRate(15) << " рублей." << std::endl; //15 minutes
	std::cout << vT1.taxRate(15) << " рублей." << std::endl; //15 minutes
	std::cout << vT1.taxRate(15) << " рублей." << std::endl; //15 minutes
	std::cout << vT1.getSum() << " всего рублей." << std::endl;
	vT1.getInfo();
	vT1.move();

	system("pause");
	return 0;
}

