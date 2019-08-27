// �� 7���� ����5 1.2.cpp : Defines the entry point for the console application.
//
/*�������� ����� Circle(����������).������������� ���� radius ���
�������� ������� ����������, x � y ��� �������� ��������� ������.��������
����������� ������������ � ���������.�������� ���������� �� ���������.
���������� ����� ������������� ��������� :
�������� �� ��������� �������� ���� �����������(�������� == );
��������� �������� ���� �����������(�������� >);
���������������� ��������� �������� ���������� ����� ���������
�� �������(��������� += � -= );
��������� ������� � ��������� ������ ����������(��������()).
�������� ������ :
getArea, ������� ���������� ������� ���������������� �����;
getLength, ������� ���������� ����� ����������.
������������� ������ ������.*/
#include "stdafx.h"
#include "Circle.h"

int _tmain(int argc, _TCHAR* argv[])
{
	Circle vC1(0.7,1.1, 0.6); // radius, x, y
	Circle vC2;
	vC2.setCircle(0.7, 1.3, 1.0);
	if (vC1 == vC2){
		std::cout << "ravni." << std::endl;
	}
	else std::cout << "ne ravni." << std::endl;
	if (vC1 > vC2){
		std::cout << "vC1 bolshe vC2." << std::endl;
	}
	else if(vC1<vC2) std::cout << "vC1 menshe vC2." << std::endl;

	vC1 += 0.1;
	vC1 -= 0.2;
	vC1(0.5, 0.7, 0.7);
	std::cout << "������ �����: " << vC1.getRadius() << std::endl;
	std::cout << "������� ����������: " << vC1.getArea() << std::endl;
	std::cout << "����� ����������: " << vC1.getLength() << std::endl;
	system("pause");
	return 0;
}

