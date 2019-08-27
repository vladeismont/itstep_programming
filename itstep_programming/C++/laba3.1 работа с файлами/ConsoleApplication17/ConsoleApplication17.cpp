// ConsoleApplication17.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream in;
	in.open("input.txt");
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	int k, n, sum=0, a;
	in >> k >> n;
	while (in >> a) {
		if (a%k == 0) {
			sum += a;
		}
	}
	in.close();
	std::ofstream fout("output.txt");
	if (!fout.is_open()) // если файл небыл открыт 
	{
		std::cout << "Файл не может быть открыт или создан\n"; // напечатать соответствующее сообщение
		return 1; // выполнить выход из программы
	}
	fout << sum;
	fout.close();
	
    return 0;
}

