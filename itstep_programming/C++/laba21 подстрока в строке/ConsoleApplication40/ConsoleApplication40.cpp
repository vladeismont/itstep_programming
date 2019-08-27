// ConsoleApplication40.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"

int main()
{
	mystd::Typewriter<std::string, std::string, std::string> obj1("Remington 5","1937","USA");
	obj1.print();
	mystd::Printer<std::string, std::string, std::string> obj2("BJC-440 ", "1988", "USA");
	obj2.print();
	obj2.printCopy();
	obj2.printWithStep(2);
	obj2.printReverse();
	obj2.print—oncordance("google");
	system("pause");
    return 0;
}