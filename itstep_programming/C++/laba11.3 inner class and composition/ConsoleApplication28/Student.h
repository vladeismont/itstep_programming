#pragma once
class Student
{
	std::string FIO;
	struct date {
		int day, month, year;
	}date;
	std::string kyrs;
	int group;
	int OAIP1 = 8;
	int cplusplus1 = 9;
	int csharp1 = 8;
public:
	class RecordBook {
		int OAIP;
		int cplusplus;
		int csharp;
	public:
		RecordBook(int a, int b, int c) :OAIP(a), cplusplus(b), csharp(c) {};
		double getmediumbal();
		int getmaxbal();
		int getminbal();
	};
	double getmediumval();
	int getmaxval();
	int getminval();
	Student();
	void setFio(std::string s);
	void setDate(int a, int b, int c);
	void setKyrs(int a);
	void setGroup(int a);
	~Student();
};

class RecordBook1 {
private:
	Student* st;
public:
	RecordBook1(Student* obj) :st(obj) {}
	double getmediumval() { return st->getmediumval(); }
	int getmaxval() { return st->getmaxval(); }
	int getminval() { return st->getminval(); }
};