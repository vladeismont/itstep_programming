// ConsoleApplication39.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"

int main()
{
	Queue<int> obj;
	Queue<int> obj1 = obj;
	obj1.push(12);
	obj1.push(13);
	obj1.push(14);
	std::cout << obj1.front() << std::endl;
	std::cout << obj1.back() << std::endl;
	std::cout << obj1.pop() << " deleted" << std::endl;
	std::cout << obj1.front() << std::endl;
	system("pause");
    return 0;
}

