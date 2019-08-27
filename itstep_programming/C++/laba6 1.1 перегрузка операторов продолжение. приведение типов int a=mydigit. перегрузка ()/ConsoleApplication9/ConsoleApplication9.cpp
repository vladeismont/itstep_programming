// ConsoleApplication9.cpp : Defines the entry point for the console application.
//
/*Создайте свой класс MyDigit для работы с целыми числами. Объявление класса должно храниться в файле MyDigit.h, а реализация методов – в файле MyDigit.cpp.
А. Объявите и реализуйте в классе следующие поля и методы: поле digit для хранения целого числа; поле counter для подсчѐта количества созданных чисел; конструктор по умолчанию (поле digit инициализируется нулѐм); явный конструктор, принимающий один параметр типа int; явный конструктор, принимающий один параметр типа double (для инициализации поля используется целая часть вещественного числа); конструктор копирования; деструктор; методы getDigit и setDigit, позволяющие установить и изменить значение поля digit; метод, позволяющий узнать, сколько чисел типа MyDigit было создано.
Б. Перегрузите следующие операторы: унарный оператор - оператор + (для сложения двух чисел типа MyDigit и для сложения числа типа MyDigit с числом типа int) бинарный оператор - (для вычитания из числа типа MyDigit другого числа типа MyDigit или числа типа int) оператор * (для умножения двух чисел типа MyDigit и для умножения числа типа MyDigit на число типа int) оператор / (для целочисленного деления двух чисел типа MyDigit и для деления числа типа MyDigit на число типа int) оператор % (для получения остатка при делении двух чисел типа MyDigit и для получения остатка от деления числа типа MyDigit на число типа int) логические операторы сравнения >, <, ==, != префиксный и постфиксный инкремент ++ префиксный и постфиксный декремент -- оператор присваивания (назначения) = составные операторы +=, -=, *=, /= *реализуйте операторы +, -, *, / через вызов операторов +=, -=, *=, /=
В. Протестируйте написанный класс. */
#include "stdafx.h"
#include "MyDigit.h"

int _tmain(int argc, _TCHAR* argv[])
{
	MyDigit vD1(5), vD2(3), vD3;
	vD3 = vD1 + vD2;
	std::cout << vD3.getDigit() << std::endl;
	vD3 = vD3*vD3;
	std::cout << vD3.getDigit() << std::endl;
	vD3 = vD3 * 5;
	std::cout << vD3.getDigit() << std::endl;
	vD3 = vD3 / 5;
	std::cout << vD3.getDigit() << std::endl;
	vD3 = vD3 / vD2;
	std::cout << vD3.getDigit() << std::endl;
	vD3 = vD3 % 2;
	std::cout << vD3.getDigit() << std::endl;
	vD3 = vD1 % vD2;
	std::cout << vD3.getDigit() << std::endl;
	if (vD3 == vD2){
		std::cout << vD3.getDigit() << " = " << vD2.getDigit() << std::endl;
	}else
		std::cout << vD3.getDigit() << " != " << vD2.getDigit() << std::endl;
	std::cout << (--vD2).getDigit() << std::endl;
	std::cout << (vD2++).getDigit() << std::endl;
	std::cout << vD2.getDigit() << std::endl;
	vD2 += vD2;
	std::cout << vD2.getDigit() << std::endl << std::endl;
	//ПРОДОЛЖЕНИЕ
	/*  Добавьте в созданный ранее класс MyDigit операторы приведения объекта
		к типу int и double.Перегрузите оператор(), чтобы иметь возможность
		менять значение уже созданного объекта типа MyDigit без вызова метода
		setDigit.
		Протестируйте работу класса.*/

	int a = vD2;
	std::cout << a << std::endl;
	vD2(5.5);
	std::cout << vD2.getDigit() << std::endl;
	system("pause");
	return 0;
}

