// ConsoleApplication15.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <set>
#include <iostream>
#include <fstream>
#include <map>

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




	std::ifstream in2;
	in2.open("input.txt");
	
	std::map<int, int> myMap;
	std::map<int, int>::iterator it;
	while (in2 >> n) {
		it = myMap.find(n);	//find
		int f = 1;
		if (it != myMap.end()) {
			f = it->second + 1;
			myMap.erase(it);

		}
		myMap[n] = f;
		//++myMap[n];	//строки 58-65 тоже самое
	}
	in2.close();

	std::ofstream fout1("output1.txt");

	std::ifstream in3;
	in3.open("test.txt");
	if (!in3.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}

	while (in3 >> n) {
		if (myMap.count(n) != 0){
			it = myMap.find(n);
			if (it != myMap.end()){
				fout1 << it->second << std::endl;
			}
		}
		else{
			fout1 << 0 << std::endl;
		}
	}
	in3.close();
	fout1.close();
	system("pause");
	return 0;
}

