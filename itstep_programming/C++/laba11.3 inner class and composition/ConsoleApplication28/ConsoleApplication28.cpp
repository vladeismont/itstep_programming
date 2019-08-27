// ConsoleApplication28.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "Student.h"

void main( ){
	
	Student obj;
	Student::RecordBook robj(8, 9, 8);
	obj.setFio("Зайцев Алексей Геннадьевич");
	obj.setDate(15,4,1985);
	obj.setKyrs(2);
	obj.setGroup(11816);
	std::cout <<"medium bal: "<< robj.getmediumbal() << std::endl;
	std::cout << "maxbal: " << robj.getmaxbal() << std::endl;
	std::cout << "minbal: " << robj.getminbal() << std::endl;
	RecordBook1 r1(&obj);
	std::cout << r1.getmediumval() << std::endl;
	std::cout << r1.getmaxval() << std::endl;
	std::cout << r1.getminval() << std::endl;
	system("pause");
}


