// ConsoleApplication19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Array.h"
int main()
{
	Array vA(5),vA1;
	vA1.setArray(5);
	vA1.getArray();
	std::cout << std::endl;
	vA1.changeArray(3);
	vA1.getArray();
	std::cout << "minimum: " << std::endl;
	vA1.getMin();
	std::cout << "maximum: " << std::endl;
	vA1.getMax();
	
	std::cout << std::endl;
	Array vA2(10);
	vA2.getArray();
	std::cout << std::endl;

	vA2.sortArray();
	vA2.getArray();
	std::cout << std::endl;

	Array vA3=vA2;
	vA3.getArray();
	
	Array vArr[5] = { 1,2,3,4,5 }; // ������ �������� ������ �����-n
	std::cout << std::endl; //�����������
	std::cout << vArr[1][1] << std::endl; // ������[], � ���������� ������ ������ []
	vArr[1](100);  // ����������� �� 100 �������� �������
	vA3(1);// ����������� �� 1 �������� �������
	std::cout << std::endl;
	vA3.getArray();
	std::cout << std::endl;
	int sum (vArr[1]); //����� ��������� �������, ���������� ����� 23������ � Array.h
	vArr[1].getArray();
	std::cout << "sum= " << vArr[1] << std::endl;
	/*std::string str(vArr[1]); //�������������� � char* ���������� �������� ��������� ������� � ���� ������.
	std::cout << "string= " << str << std::endl;*/


	//std::cout << strlen(vArr[1]) << std::endl;
	char* ch = vArr[1]; //�������������� � char* ���������� �������� ��������� ������� � ���� ������. std::string - �����!
	std::cout << ch << std::endl;
	std::cout << ch << std::endl;
	system("pause");
    return 0;
}

