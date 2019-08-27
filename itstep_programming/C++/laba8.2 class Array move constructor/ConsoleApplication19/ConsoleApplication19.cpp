// ConsoleApplication19.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include "Array.h"
int main()
{
	Array vA(5),vA1;
	vA1.setArray(5);
	vA1.getArray();
	std::cout << std::endl;
	vA1.changeArray(3);
	vA1.getArray();
	std::cout << "minimum: " << std::endl;
	vA1.getMin();
	std::cout << "maximum: " << std::endl;
	vA1.getMax();
	
	std::cout << std::endl;
	Array vA2(10);
	vA2.getArray();
	std::cout << std::endl;

	vA2.sortArray();
	vA2.getArray();
	std::cout << std::endl;

	Array vA3=vA2;
	vA3.getArray();
	
	Array vArr[5] = { 1,2,3,4,5 }; // массив массивов рандом чисел-n
	std::cout << std::endl; //продолжение
	std::cout << vArr[1][1] << std::endl; // массив[], и перегрузка вторых скобок []
	vArr[1](100);  // увеличиваем на 100 элементы массива
	vA3(1);// увеличиваем на 1 элементы массива
	std::cout << std::endl;
	vA3.getArray();
	std::cout << std::endl;
	int sum (vArr[1]); //сумма элементов массива, приведение типов 23строка в Array.h
	vArr[1].getArray();
	std::cout << "sum= " << vArr[1] << std::endl;
	/*std::string str(vArr[1]); //преобразование к char* возвращает значения элементов массива в виде СТРОКИ.
	std::cout << "string= " << str << std::endl;*/


	//std::cout << strlen(vArr[1]) << std::endl;
	char* ch = vArr[1]; //преобразование к char* возвращает значения элементов массива в виде СТРОКИ. std::string - проще!
	std::cout << ch << std::endl;
	std::cout << ch << std::endl;
	system("pause");
    return 0;
}

