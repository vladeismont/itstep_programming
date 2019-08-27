// ConsoleApplication5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Area.h"
int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	float f;
//	Area vA;
	f = Area::getTriangleArea(5,6); //������� � ������*
	std::cout <<"������� ������������ �� ������� � ���������� � ��� ������: "<< f << std::endl;
	f = Area::getTriangleArea(5, 6, 5);  //�� 3 ��������
	std::cout << "������� ������������ �� 3 ��������: " << f << std::endl;
	const std::pair<const float, const float>myPair = std::make_pair(5.0, 6.1);
	f = Area::getTriangleArea(myPair/*std::make_pair(5.0,6.1);*/, 30); // �� 2 �������� � ����
	std::cout << "������� ������������ �� 2 �������� � ���� ����� ����: " << f << std::endl;

	f = Area::getRectangleArea(3, 7);
	std::cout <<"������� �������������� �� 2 ��������: "<< f << std::endl;

	f = Area::getSquareArea(5); 
	std::cout <<"������� �������� �� 1�� �������: "<<f << std::endl;
	f = Area::getSquareArea(5, 5);
	std::cout << "������� �������� �� 2�� ��������: "<< f << std::endl;

	f = Area::getParallelogramArea(5,3);
	std::cout << "������� ���������������: " << f << std::endl;
	f = Area::getParallelogramArea(5, 3, 30); // �� 2 �������� � ����
	std::cout << "������� ��������������� �� 2�� �������� � ���� ����� ����: " << f << std::endl;

	f = Area::getRombusArea(4,6);
	std::cout << "������� ����� �� ���� ����������:" << f << std::endl;
	f = Area::getRombusArea(std::make_pair(4,60)); // �� ������� � ���� pow(a)*sin60
	std::cout << "������� �����: " << f << std::endl;

	int count = Area::getCount();
	std::cout << "���������� ������� ������� ��� ������������� �������: " << count << std::endl;
	system("pause");//std::pair< , > std::map< , >
	return 0;
}