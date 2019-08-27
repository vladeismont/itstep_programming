// ConsoleApplication23.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Complex.h"

int main()
{
	Complex vC1(4.4, 5.5);
	std::cout << vC1 << std::endl;
	Complex vC2,vC3;
	std::cin >> vC2;
	std::cout << vC2 << std::endl;
	vC3 = vC1 + vC2;
	std::cout << vC3 << std::endl;
	if (vC3 != vC2) {
		std::cout << "vC3 != vC2" << std::endl;
	}
	if (vC3 == vC3) {
		std::cout << "vC3 == vC3" << std::endl;
	}
	vC3(1, 2);
	std::cout << vC3 << std::endl;
	system("pause");
    return 0;
}

