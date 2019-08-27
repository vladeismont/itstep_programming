// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>
#include <string>
#include <stdio.h>
int main()
{
	/*std::ifstream in;
	in.open("input.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	std::string str1;
	std::ofstream fout("output.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		return 1; // выполнить выход из программы
	}
	while (!in.eof()) {
		getline(in, str1, ' ');
		if (str1.length() == 3) {
			fout << str1<<' ';
		}
	}
	in.close();
	fout.close();
	*/

	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	std::string str[1000],str1;
	std::ofstream fout("output.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		return 1; // выполнить выход из программы
	}
	int f = 0;
	while (!in.eof()) {
		getline(in, str1, ' ');
		if (str1.length() == 3) {
			str[f] = str1;
			++f;
		}
	}
	in.close();
	for (int i = 0; i < f; ++i) {
		if (i == 0) 
			fout << str[i];
		else 
			fout << ' ' << str[i];
	}
	fout.close();
	system("pause");
    return 0;
}

