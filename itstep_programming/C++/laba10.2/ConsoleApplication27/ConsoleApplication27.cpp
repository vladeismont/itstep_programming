// ConsoleApplication27.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
class Employee
{
public:
	virtual void print() = 0;
};

class President : public Employee {
public:
	void print() { std::cout << "president: Александр Григорьевич Лукашенко" << std::endl; };
};
class Manager : public Employee {
public:
	void print() { std::cout << "manager: Александр Григорьевич Лукашенко" << std::endl; };
};
class Worker : public Employee {
public:
	void print() { std::cout << "worker: Александр Григорьевич Лукашенко" << std::endl; };
};
int main()
{
	setlocale(LC_ALL, "rus");
	President obj1;
	obj1.print();
	Manager obj2;
	obj2.print();
	Worker obj3;
	obj3.print();
	system("pause");
    return 0;
}