// ConsoleApplication14.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Shape.h"
#include <iostream>
#include "Triangle.h"
#include "Parallelogram.h"
int main()
{
	Triangle obj1(3.,4.,5.);
	obj1.setABC(3, 4, 5);
	Triangle obj2(std::make_pair(3,4), 90);//const std::pair<const float, const float>myPair = std::make_pair(5.0, 6.1);
	Triangle obj3(3, std::make_pair(30, 60));

	std::cout << obj1.getArea() << std::endl;
	std::cout << obj2.getArea() << std::endl;
	std::cout << obj3.getArea() << std::endl;
	Parallelogram vP(3,4,45);
	Parallelogram vP1(vP);
	std::cout << vP1.getArea() << std::endl;
	system("pause");
    return 0;
}

