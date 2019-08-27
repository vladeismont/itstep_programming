// ConsoleApplication20.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Book.h"

int main()
{
	setlocale(LC_ALL, "rus");
	Book vArr[5] = { Book("А.С. Пушкин","Евгений Онегин","Эксмо", 2016, 640),
		Book("А.С. Пушкин","Пиковая дама","Эксмо", 2016, 96),
		Book("А.С. Пушкин", "Барышня-крестьянка", "Белый город", 1990, 28),
		Book("А.С. Пушкин", "Собрание сочинений", "Москва", 1960, 659),
		Book("Джоан Роулинг", "Гарри Поттер и проклятое дитя", "Азбука-Аттикус", 2016, 464)};
	/*vArr[0] = Book ("А.С. Пушкин","Евгений Онегин","эксмо", 2016, 640);
	vArr[1] = Book("А.С. Пушкин","Пиковая дама","Эксмо", 2016, 96);
	vArr[2] = Book("А.С. Пушкин", "Барышня-крестьянка", "Белый город", 1990, 28);
	vArr[3] = Book("А.С. Пушкин", "Собрание сочинений", "Москва", 1960, 659);
	vArr[4] = Book("Джоан Роулинг", "Гарри Поттер и проклятое дитя", "Азбука-Аттикус", 2016, 464);*/
	std::cout << std::endl << "______книги Джоан Роулинг______: " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if ("Джоан Роулинг" == vArr[i].getAvtor()) {
			vArr[i].getBook();
		}
	}
	std::cout<<std::endl;
	std::cout << std::endl << "______книги издательства Эксмо:______ " << std::endl;
	for (int i = 0; i < 5; ++i) {
		if ("Эксмо" == vArr[i].getIzdatelstvo()) {
			vArr[i].getBook();
		}
	}
	std::cout<< std::endl <<"______книги выпущенные после 2000 года:______ "<< std::endl;
	for (int i = 0; i < 5; ++i) {
		if (2000 <= vArr[i].getYear()) {
			vArr[i].getBook();
		}
	}
	system("pause");
    return 0;
}

