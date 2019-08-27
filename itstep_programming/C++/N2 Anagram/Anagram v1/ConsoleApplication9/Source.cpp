#include <iostream>
#include "Anagram.h"
int main()
{
	char str1[255], str2[255];
	std::cout << "enter the first string" << std::endl;
	gets_s(str1);
	std::cout << "enter the second string" << std::endl;
	gets_s(str2);
	
	Anagram vA;
	int flag;
	flag=vA.isAnagram(str1,str2);

	if(flag==0) std::cout << " are not anagrams."<<std::endl;
	else std::cout << " are anagrams." << std::endl;
	system("pause");
	return 0;
}