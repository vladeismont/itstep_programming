// ConsoleApplication6.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <fstream> // ��� ������ � �������
//#include "iostream" //��� ������ � ��������
#include <string>
#include "A.h"
int _tmain(int argc, _TCHAR* argv[])
{
	std::ifstream in; //std::ofstream out("\");
//	in.open("D\\eismontvlad\7-12-2016\input.txt");
	in.open("input.txt");
	if (!in.is_open()){
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}

	int size;
	in >> size;//��������� ������ �������� �� �������
	//getline(in, size); //��������� ������ ////std::string size;
	std::cout << size << std::endl;
	int max, min;
	in >> min;
	max = min;
	while (in >> size){
		if (size < min){
			min = size;
		}
		if (size>max){
			max = size;
		}
	}
	std::cout << "min= " << min << std::endl << "max= " << max << std::endl;
	in.close();
	
	//-134217192 ���
	//134217728 ����
	A a;
	a.setValue(5);
	std::cout << a.getValue() << std::endl;
	system("pause");
	return 0;
}

