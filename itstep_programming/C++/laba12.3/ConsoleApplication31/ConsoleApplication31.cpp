// ConsoleApplication31.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "LinearEquation.h"
#include "QuadraticEquation.h"
int main()
{
	LinearEquation obj;
	std::cout << obj.solve() << std::endl;
	QuadraticEquation obj1;
	std::cout << obj1.solve() << std::endl;
	system("pause");
    return 0;
}

