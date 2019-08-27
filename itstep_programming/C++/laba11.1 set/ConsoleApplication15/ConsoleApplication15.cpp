// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <iostream>
#include <fstream>

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	std::set<int> mySet;
	int n;
	while (in >> n) {
		mySet.insert(n);
	}
	in.close();

	std::ofstream fout("output.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "Файл не может быть открыт или создан\n";
		return 1;
	}

	std::ifstream in1;
	in1.open("test.txt");
	if (!in1.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	
	while (in1 >> n) {
		if (mySet.count(n) != 0)
			fout << "YES\n";
		else
			fout << "NO\n";
	}
	in1.close();
	fout.close();
	system("pause");
	return 0;
}

