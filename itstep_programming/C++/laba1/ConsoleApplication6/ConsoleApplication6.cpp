// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Fraction.h"

int main()
{
	int a=2*3;
	std::cout << a << std::endl;
	setlocale(LC_ALL, "rus");
	Fraction vF1;
	std::cout << "1-�� �����:\n";
	vF1.getFraction();
	vF1.printFraction();

	std::cout << "2-�� �����:\n";
	Fraction vF2;
	vF2.getFraction();
	vF2.printFraction();

	std::cout << "��������� ��������� ������:\n";
	Fraction vF3;
	vF3.multiply(vF1,vF2);
	vF3.printFraction();

	std::cout << "��������� ������� ������:\n";
	vF3.division(vF1, vF2);
	vF3.printFraction();

	std::cout << "��������� �������� ������:\n";
	vF3.addition(vF1, vF2);
	vF3.printFraction();

	std::cout << "��������� ��������� ������:\n";
	vF3.subtraction(vF1, vF2);
	vF3.printFraction();
	system("pause");
    return 0;
}

