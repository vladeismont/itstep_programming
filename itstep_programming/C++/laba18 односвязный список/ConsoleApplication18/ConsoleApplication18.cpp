#include "stdafx.h"
#include <iostream>
#include "MyList.h"

void test(){
	MyList<int> ml;
	ml.push_front(11);
	ml.push_back(13);
	ml.push_front(10);
	ml.push_back(4);
	ml.push_back(14);
	ml.pretty_print();

	ml.insert(9, 7);
	ml.insert(0, 14);
	ml.insert(7, 4);
	ml.insert(1, 19); // должно быть выведено сообщение об ошибке
	ml.pretty_print();
	
	ml.pop_front();
	ml.pretty_print();

	ml.erase(13);
	ml.erase(14);
	ml.pretty_print();
	ml.pop_front();
	ml.erase(19); // должно быть выведено сообщение об ошибке
	ml.pretty_print();
	ml.pop_back();
	ml.pretty_print();
	ml.pop_back();
	ml.pretty_print();
	ml.pop_back();
	ml.pretty_print();
	ml.pop_back();
	ml.pretty_print();
	ml.pop_back();
	ml.pretty_print();
}

int main(){
	test();
	system("pause");
	return 0;
}
