// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Worker.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Worker vWorker[5] = { Worker("Зайцев Александр Викторович","программист",1992, 1250),
		Worker("Ивашев Дминтрий Иванович","программист",1997, 1325),
		Worker("Бойко Егор Артемович","программист",2009, 1175),
		Worker("Бусько Александр Сергеевич","программист",2014, 1300),
		Worker("Зайцева Анна Алексеевна","ведущий программист",1990, 1550)};
	std::cout << "список работников со стажем работы 15 лет: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (vWorker[i].staj() >= 15) {
			vWorker[i].show();
		}
	}
	std::cout <<std::endl<< "список работников чья зарплата выше 1300$: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (vWorker[i].getZarplata() >= 1300) {
			vWorker[i].show();
		}
	}
	std::cout << std::endl << "список работников чья должность - ведущий программист : " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if (vWorker[i].getDoljnost() == "ведущий программист") {
			vWorker[i].show();
		}
	}
	system("pause");
    return 0;
}

