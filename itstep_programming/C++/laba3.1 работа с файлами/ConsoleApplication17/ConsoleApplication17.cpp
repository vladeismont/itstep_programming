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
	if (!fout.is_open()) // ���� ���� ����� ������ 
	{
		std::cout << "���� �� ����� ���� ������ ��� ������\n"; // ���������� ��������������� ���������
		return 1; // ��������� ����� �� ���������
	}
	fout << sum;
	fout.close();
	
    return 0;
}

