// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CrosswordSolver.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	CrosswordSolver obj;
	obj.getAllWithLen(5);
	obj.getAllWithInit('�');
	obj.findByMask("�?�");
	obj.findByMask("*�������*");
	obj.getAnagrams("�����");
	system("pause");
	return 0;
}

