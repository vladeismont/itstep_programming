#include "stdafx.h"
#include "Student.h"


double Student::getmediumval()
{
	return (OAIP1 + cplusplus1 + csharp1) / 3.;
}

int Student::getmaxval()
{
	if (OAIP1 >= cplusplus1 && OAIP1 >= csharp1) return OAIP1;
	if (cplusplus1 >= OAIP1 && cplusplus1 >= csharp1) return cplusplus1;
	if (csharp1 >= cplusplus1 && csharp1 >= OAIP1) return csharp1;
}

int Student::getminval()
{
	if (OAIP1 <= cplusplus1 && OAIP1 <= csharp1) return OAIP1;
	if (cplusplus1 <= OAIP1 && cplusplus1 <= csharp1) return cplusplus1;
	if (csharp1 <= cplusplus1 && csharp1 <= OAIP1) return csharp1;
}

Student::Student()
{
}

void Student::setFio(std::string s)
{
	FIO = s;
}

void Student::setDate(int a, int b, int c)
{
	date.day = a;
	date.month = b;
	date.year = c;
}

void Student::setKyrs(int a)
{
	kyrs = a;
}

void Student::setGroup(int a)
{
	group = a;
}


Student::~Student()
{
}


double Student::RecordBook::getmediumbal()
{
	return (OAIP+cplusplus+csharp)/3.;
}

int Student::RecordBook::getmaxbal()
{
	if (OAIP >= cplusplus && OAIP >= csharp) return OAIP;
	if (cplusplus >= OAIP && cplusplus >= csharp) return cplusplus;
	if (csharp >= cplusplus && csharp >= OAIP) return csharp;
}

int Student::RecordBook::getminbal()
{
	if (OAIP <= cplusplus && OAIP <= csharp) return OAIP;
	if (cplusplus <= OAIP && cplusplus <= csharp) return cplusplus;
	if (csharp <= cplusplus && csharp <= OAIP) return csharp;
}

