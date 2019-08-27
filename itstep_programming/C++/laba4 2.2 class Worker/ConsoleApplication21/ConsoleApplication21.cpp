// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Worker.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Worker vWorker[5] = { Worker("������ ��������� ����������","�����������",1992, 1250),
		Worker("������ �������� ��������","�����������",1997, 1325),
		Worker("����� ���� ���������","�����������",2009, 1175),
		Worker("������ ��������� ���������","�����������",2014, 1300),
		Worker("������� ���� ����������","������� �����������",1990, 1550)};
	std::cout << "������ ���������� �� ������ ������ 15 ���: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (vWorker[i].staj() >= 15) {
			vWorker[i].show();
		}
	}
	std::cout <<std::endl<< "������ ���������� ��� �������� ���� 1300$: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (vWorker[i].getZarplata() >= 1300) {
			vWorker[i].show();
		}
	}
	std::cout << std::endl << "������ ���������� ��� ��������� - ������� ����������� : " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (vWorker[i].getDoljnost() == "������� �����������") {
			vWorker[i].show();
		}
	}
	system("pause");
    return 0;
}

