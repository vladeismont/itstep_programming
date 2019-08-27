// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "CrosswordSolver.h"

int _tmain(int argc, _TCHAR* argv[])
{
	setlocale(LC_ALL, "rus");
	CrosswordSolver obj;
	obj.getAllWithLen(5);
	obj.getAllWithInit('ё');
	obj.findByMask("а?а");
	obj.findByMask("*ооружен*");
	obj.getAnagrams("донор");
	system("pause");
	return 0;
}

