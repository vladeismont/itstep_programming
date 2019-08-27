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
	vD.setDate(1, 12, 2016);
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
	vD.showDate();
	system("pause");
    return 0;
}