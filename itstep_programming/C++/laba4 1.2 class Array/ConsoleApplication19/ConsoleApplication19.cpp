// ConsoleApplication19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Array.h"
int main()
{
	Array vA(5),vA1;
	vA1.setArray(5);
	vA1.getArray();
	std::cout << std::endl;
	vA1.changeArray(3);
	vA1.getArray();
	std::cout << "minimum: " << std::endl;
	vA1.getMin();
	std::cout << "maximum: " << std::endl;
	vA1.getMax();
	
	std::cout << std::endl;
	Array vA2(10);
	vA2.getArray();
	std::cout << std::endl;

	vA2.sortArray();
	vA2.getArray();
	std::cout << std::endl;

	Array vA3=vA2;
	vA3.getArray();
	system("pause");
    return 0;
}

