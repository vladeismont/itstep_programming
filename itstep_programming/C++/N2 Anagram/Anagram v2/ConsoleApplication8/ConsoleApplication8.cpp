// ConsoleApplication8.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Anagram.h"
int main()
{
	char str1[80], str2[80];
	std::cout << "enter the first string from {A..Z,a..z,space}" << std::endl;
	gets_s(str1);
	std::cout << "enter the second A..Z string" << std::endl;
	gets_s(str2);
	
	Anagram vA;
	int flag;
	flag = vA.check_anagram(str1, str2);
	if (flag == 1)
	std::cout << str1 << "\tand\t" << str2 << " are anagrams.";
	else if(flag==0)
	std::cout << str1 << "\tand\t" << str2 << " are not anagrams.";
	else std::cout << "incorrect string" << std::endl;

	system("pause");
    return 0;
}

