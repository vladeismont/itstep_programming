// ConsoleApplication26.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <fstream>
#include <iostream>
#include <map>
#include <string>
int main()
{
	setlocale(LC_ALL, "rus");
	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	std::map<std::string, int> myMap;
	std::map<std::string, int>::iterator it;
	std::string str;
	while (in>>str) {
		//in >> str;
		it = myMap.find(str);	//find
		int f = 1;
		if (it != myMap.end()) {
			f = it->second + 1;
			myMap.erase(it);
			
		}
		myMap[str] = f;
	}
	in.close();
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << " " << it->second <<" times" << std::endl;
	}
	//std::cout <<"самое частое слово: "<<str <<" "<< max <<" times" << std::endl;

	int flag=0;
	std::string flagStr;
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		if (flag < it->second) {
			flag = it->second;
			flagStr = it->first;
		}
	} //	*_*
	std::cout << "чаще употребляемое слово: " << flagStr << " - " << flag << " times" << std::endl;

	///чтение и запись в файл
	std::ofstream fout("output.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "Файл не может быть открыт или создан\n";
		return 1;
	}
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		fout << it->first << " " << it->second << " ";
	}
	fout.close();

	system("pause");
    return 0;
}

