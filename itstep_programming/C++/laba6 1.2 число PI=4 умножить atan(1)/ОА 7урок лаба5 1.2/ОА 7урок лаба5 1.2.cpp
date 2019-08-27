// ОА 7урок лаба5 1.2.cpp : Defines the entry point for the console application.
//
/*Создайте класс Circle(окружность).Предусмотрите поля radius для
хранения радиуса окружности, x и y для хранения координат центра.Создайте
необходимые конструкторы и аксессоры.Объявите деструктор по умолчанию.
Реализуйте через перегруженные операторы :
проверку на равенство радиусов двух окружностей(оператор == );
сравнение размеров двух окружностей(оператор >);
пропорциональное изменение размеров окружности путем изменения
ее радиуса(операторы += и -= );
изменение радиуса и координат центра окружности(оператор()).
Создайте методы :
getArea, который возвращает площадь соответствующего круга;
getLength, который возвращает длину окружности.
Протестируйте работу класса.*/
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
	std::cout << "радиус равен: " << vC1.getRadius() << std::endl;
	std::cout << "площадь окружности: " << vC1.getArea() << std::endl;
	std::cout << "длина окружности: " << vC1.getLength() << std::endl;
	system("pause");
	return 0;
}

