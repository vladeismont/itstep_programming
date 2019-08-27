// ConsoleApplication34.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
void myPrint() {
	//std::cout << std::endl;
}

template <typename T> void myPrint(const T& t) {
	std::cout << t << std::endl;
}
template <typename First, typename... Rest> 
void myPrint(const First& first, const Rest&... rest) {
	std::cout << first << " ";
	std::cout << "sizeof=" << sizeof...(rest) << "; ";// << std::endl;
	myPrint(rest...); // recursive call using pack expansion syntax  
}
int main()
{
	myPrint();
	myPrint(1);
	myPrint(10, 34, 45.12, 99.1189);
	myPrint(10, 34, 45.12, "text", "new string");
	myPrint("Student", 17, 2017, "18-11S", 9.1);
	system("pause");
    return 0;
}

