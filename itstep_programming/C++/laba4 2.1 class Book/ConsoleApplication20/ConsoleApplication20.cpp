// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Book.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Book vArr[5] = { Book("�.�. ������","������� ������","�����", 2016, 640),
		Book("�.�. ������","������� ����","�����", 2016, 96),
		Book("�.�. ������", "�������-����������", "����� �����", 1990, 28),
		Book("�.�. ������", "�������� ���������", "������", 1960, 659),
		Book("����� �������", "����� ������ � ��������� ����", "������-�������", 2016, 464)};
	/*vArr[0] = Book ("�.�. ������","������� ������","�����", 2016, 640);
	vArr[1] = Book("�.�. ������","������� ����","�����", 2016, 96);
	vArr[2] = Book("�.�. ������", "�������-����������", "����� �����", 1990, 28);
	vArr[3] = Book("�.�. ������", "�������� ���������", "������", 1960, 659);
	vArr[4] = Book("����� �������", "����� ������ � ��������� ����", "������-�������", 2016, 464);*/
	std::cout << std::endl << "______����� ����� �������______: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if ("����� �������" == vArr[i].getAvtor()) {
			vArr[i].getBook();
		}
	}
	std::cout<<std::endl;
	std::cout << std::endl << "______����� ������������ �����:______ " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if ("�����" == vArr[i].getIzdatelstvo()) {
			vArr[i].getBook();
		}
	}
	std::cout<< std::endl <<"______����� ���������� ����� 2000 ����:______ "<< std::endl;
	for (int i = 0; i < 5; ++i) {
		if (2000 <= vArr[i].getYear()) {
			vArr[i].getBook();
		}
	}
	system("pause");
    return 0;
}

