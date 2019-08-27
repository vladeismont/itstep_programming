// ConsoleApplication32.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
template<typename T>
T getMin(const T first, const T second) {
	return(first<second?first:second);
}

template<typename T>
T getMax(const T* array, int size) {
	T max = array[0]; // максимальное значение в массиве
	for (int ix = 0; ix < size; ix++)
		if (max < array[ix])
			max = array[ix];
	return max;
}

template<typename T>
T solve(const T first, const T second) {
	return (-second) / first;
}
template<typename T>
void solve(const T first, const T second, const T third) {
	T D, x, x1, x2;
	D = second*second - 4 * first*third;
	std::cout << "Дискриминант равен " << D << std::endl;
	if (D < 0)
		std::cout << "Уравнение не имеет решений" << std::endl;
	if (D == 0)
	{
		std::cout << "Уравнение имеет одно решение" << std::endl;
		x = -second / (2 * first);
		std::cout << "x=" << x;
	}
	if (D > 0)
	{
		std::cout << "Уравнение имеет два решения" << std::endl;
		x1 = (-second + sqrt(D)) / (2 * first);
		x2 = (-second - sqrt(D)) / (2 * first);
		std::cout << "x1=" << x1 << ", " << "x2=" << x2 << std::endl;
	}
}
int main()
{
	std::cout << getMin<double>(1.12, 12.33) << std::endl;	//1
	int iArray[5] = { 3,5,7,2,9 };
	//int n = getMax(iArray,5);
	setlocale(LC_ALL, "rus");
	std::cout << "Максимальный элемент массива типа int: " << getMax(iArray, 5) << std::endl;	//2ab
	double dArray[5] = { 3.3,5.5,7.7,2.2,9.9 };
	std::cout << "Максимальный элемент массива типа double: " << getMax(dArray, 5) << std::endl;	//2ab

	//(a*x + b = 0)
	std::cout << "x= " << solve(5, -25) << std::endl;	//3a
	//(a*x2 + b*x + c = 0)
	solve(2, 4, 7);		//3b!

	system("pause");
    return 0;
}

