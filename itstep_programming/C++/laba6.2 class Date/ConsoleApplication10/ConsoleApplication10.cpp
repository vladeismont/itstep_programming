// ConsoleApplication10.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
#include "Date.h"
int main()
{
	Date vD;
	/*vD.setDay(1);
	vD.setMonth(12);
	vD.setYear(2016);*/

	/*vD.setDate(1, 12, 2016);
	Date vDnew = vD;
	vDnew.showDate();
	vDnew.initDMY(1,1,2017);
	vDnew.initMDY(1, 2, 2017);
	vDnew.showDate();
	int d, m, y;
	setlocale(LC_ALL, "rus");
	std::cout << "¬ведите через пробел день, мес€ц и год:" << std::endl;
	std::cin >> d >> m >> y;
	vD.setDay(d);
	vD.setMonth(m);
	vD.setYear(y);
	vD.showDate();

	vDnew.increaseYear(14);
	vDnew.showDate();
	vDnew.increaseMonth(12);
	vDnew.showDate();
	vD.increaseDay(30);
	vD.showDate();*/

	//продолжение
	Date vDate(1, 1, 2016, 7, 15, 30);
	vDate.increaseSecond(86400*30);//86400 seconds per day приращение времени +delta t
	//vDate.showNewDate();
	std::cout << vDate << std::endl;
	vDate(6,20,1975,7,15,15);
	std::cout << vDate << std::endl;
	++vDate;
	std::cout << vDate++ << std::endl;

	std::cin >> vDate;
	std::cout << std::endl << vDate;
	if (vDate == vDate) { //!=
		std::cout << "vDate==vDate." << std::endl;
	}
	else std::cout << "vDate!=vDate." << std::endl;
	system("pause");
    return 0;
}