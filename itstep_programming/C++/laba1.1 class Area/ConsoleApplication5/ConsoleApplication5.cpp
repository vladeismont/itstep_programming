// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Area.h"
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	float f;
//	Area vA;
	f = Area::getTriangleArea(5,6); //стороне и высоте*
	std::cout <<"площадь треугольника по стороне и прилежащей к ней высоте: "<< f << std::endl;
	f = Area::getTriangleArea(5, 6, 5);  //по 3 сторонам
	std::cout << "площадь треугольника по 3 сторонам: " << f << std::endl;
	const std::pair<const float, const float>myPair = std::make_pair(5.0, 6.1);
	f = Area::getTriangleArea(myPair/*std::make_pair(5.0,6.1);*/, 30); // по 2 сторонам и углу
	std::cout << "площадь треугольника по 2 сторонам и углу между ними: " << f << std::endl;

	f = Area::getRectangleArea(3, 7);
	std::cout <<"площадь пр€моугольника по 2 сторонам: "<< f << std::endl;

	f = Area::getSquareArea(5); 
	std::cout <<"площадь квадрата по 1ой стороне: "<<f << std::endl;
	f = Area::getSquareArea(5, 5);
	std::cout << "площадь квадрата по 2ум сторонам: "<< f << std::endl;

	f = Area::getParallelogramArea(5,3);
	std::cout << "площадь параллелограмма: " << f << std::endl;
	f = Area::getParallelogramArea(5, 3, 30); // по 2 сторонам и углу
	std::cout << "площадь параллелограмма по 2ум сторонам и углу между ними: " << f << std::endl;

	f = Area::getRombusArea(4,6);
	std::cout << "площадь ромба по двум диагонал€м:" << f << std::endl;
	f = Area::getRombusArea(std::make_pair(4,60)); // по стороне и углу pow(a)*sin60
	std::cout << "площадь ромба: " << f << std::endl;

	int count = Area::getCount();
	std::cout << "количество вызовов функции дл€ подсчитывани€ площади: " << count << std::endl;
	system("pause");//std::pair< , > std::map< , >
	return 0;
}