// ConsoleApplication25.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <map>
#include <string>
#include <fstream>
int main(){
	
	setlocale(LC_ALL, "rus");
	std::map<std::string, std::string> myMap;
	myMap["word"] = "�����";
	myMap["map"] = "�����";
	myMap["google"] = "����";
	myMap["sled"] = "�����";
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}
	std::string str;
	std::cout << "*****enter the english word*****" << std::endl;
	std::cin >> str;
	std::map<std::string, std::string>::iterator it;
	it = myMap.find(str);	//find
	if (it != myMap.end()) {
		std::cout <<"this word was found!\n"<< it->first << " " << it->second << std::endl;
	}
	if (it == myMap.end()) { std::cout << "word not found" << std::endl; }

	std::cout << "--------------------------------------" << std::endl;		//insert
	myMap.insert(std::pair<std::string, std::string>("year", "���")); 
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}


	std::cout << "--------------------------------------" << std::endl;		//erase
	std::cout << "����� ���������� ����� ������ �������?" << std::endl;
	std::cin >> str;
	it = myMap.find(str);
	if (it != myMap.end()) {
		myMap.erase(it);
		std::cout << "����� �������" << std::endl;
	}
	else {
		std::cout << "��� �������� ��� ����� �� �������" << std::endl;
	}
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}


	std::cout << "*--------------------------------------*" << std::endl;		//�������������� �������
	std::cout << "������� ����������� ����� �� ������� ��� ��������������:" << std::endl;
	std::cin >> str;
	it = myMap.find(str);
	int f = 0;
	if (it != myMap.end()) {
		f = 1;
		std::string str1, str2;
		std::cout << "������� ����������� ����� � �������:" << std::endl;
		std::cin >> str1;
		std::cout << "������� �������� ����� ����� ���������:" << std::endl;
		std::cin >> str2;
		myMap.erase(it);
		myMap.insert(std::pair<std::string, std::string>(str1, str2));
	}
	if (f == 0) {
		std::cout << "this word not found" << std::endl;
	}
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		std::cout << it->first << " " << it->second << std::endl;
	}

	///������ � ������ � ����
	std::ofstream fout("output.txt");
	if (!fout.is_open()) // ���� ���� ����� ������ 
	{
		std::cout << "���� �� ����� ���� ������ ��� ������\n"; 
		return 1; 
	}
	for (auto it = myMap.begin(); it != myMap.end(); ++it) {
		fout << it->first << " " << it->second << " ";
	}
	fout.close();

	std::ifstream in;
	in.open("output.txt");		//��������� ���� �� ����
	if (!in.is_open()) {
		std::cout << "File not found" << std::endl;
		return 1; //exit(1);
	}
	std::map<std::string, std::string> myMap1;
	while (!in.eof()) {
		std::string str1, str2;
		in >> str1 >> str2;
		myMap1[str1] = str2;
	}
	in.close();
	for (auto it = myMap1.begin(); it != myMap1.end(); ++it) {
		fout << it->first << " " << it->second << " ";
	}
	system("pause");
	return 0;
}

