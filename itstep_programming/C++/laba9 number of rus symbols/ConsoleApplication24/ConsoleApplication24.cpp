// ConsoleApplication24.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
std::string f1(std::string a, std::string b) {
	return a.append(".").append(b);
}
std::string f2(std::string a) {
	for (size_t i = 0; i < a.length(); ++i) {
		if (a[i] == 'a') {
			a[i] = 'o';
		}
	}
	return a;
}
bool f3(std::string a, std::string b) {

	for (size_t i = 0; i < a.length()-b.length()+1; ++i) {
		if (b == a.substr(i,b.length())) {
			return true;
		}
	}

	return false;
}
std::string f4(std::string a) {
	std::string tmp=a;
	for (size_t i = 0; i < a.length(); ++i) {
		tmp[i] = a[a.length() - i - 1];
		//tmp[i + 1] = '\0';
	}
	return tmp;
}
int f5(std::string a) {
	int n = 0;
	for (size_t i = 0; i < a.length(); ++i) {
		char ch = toupper(a[i]);
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
		if (ch == '�') n++;
	}
	return n;
}
int main()
{
	std::string str1 = "file";
	std::string str2 = "write";
	std::string str = f1(str1, str2); //append
	std::cout << str << std::endl;

	str = f2("abaaaaaaaaaaaaaa"); //replace a=o
	std::cout << str << std::endl;
	setlocale(LC_ALL, "rus");

	if (f3(str1, str2)) {
		std::cout << "������ ������ ������ � ������" << std::endl;
	}
	else {
		std::cout << "������ ������ �� ������ � ������" << std::endl;
	}
	if (f3("1obo", "obo")) {
		std::cout << "������ ������ ������ � ������" << std::endl;
	}
	else {
		std::cout << "������ ������ �� ������ � ������" << std::endl;
	}
	
	std::cout << f4("FILE") << std::endl;		//�������������� ������
	std::cout << f5("����������") << std::endl;	//���������� ������� ������� ����
	system("pause");
    return 0;
}

