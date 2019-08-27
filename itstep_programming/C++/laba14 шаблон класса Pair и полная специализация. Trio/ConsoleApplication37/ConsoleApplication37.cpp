// ConsoleApplication37.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"

int main()
{
	Pair<double> obj(10, 20.2);
	std::cout << obj.first() << std::endl;
	std::cout << obj.second() << std::endl;
	obj.makePair(1, 2);
	std::cout << obj.first() << std::endl;
	std::cout << obj.second() << std::endl;
	Pair<bool> obj2(false, true);
	std::cout << obj2.first() << std::endl;
	std::cout << obj2.second() << std::endl;
	Trio<int> obj3(1, 2, 3);
	std::cout << obj3.first() << std::endl;
	std::cout << obj3.second() << std::endl;
	std::cout << obj3.third() << std::endl;
	obj3.makeTrio(3, 6, 9);
	std::cout << obj3.first() << std::endl;
	std::cout << obj3.second() << std::endl;
	std::cout << obj3.third() << std::endl;
	system("pause");
    return 0;
}

