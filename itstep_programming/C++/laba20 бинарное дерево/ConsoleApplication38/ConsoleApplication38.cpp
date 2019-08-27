// ConsoleApplication38.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Header.h"
#include<string>
#include<list>
#include <algorithm>    // std::transform

int main()
{
	const int N = 10;
	int mass[N] = { 0,1,2,3,4,5,6,7,8,9 };
	//functor http://cs.stmarys.ca/~porter/csc/ref/stl/function_objects.html
	int first[] = { 1, 2, 3, 4, 5 };
	int second[] = { 10, 20, 30, 40, 50 };
	int results[5];
	std::transform(first, first + 5, second, results, std::plus<int>());
	for (int i = 0; i<5; i++)
		std::cout << results[i] << ' ';
	std::cout << '\n';	//end
	std::cout << std::plus <int>()(10, 2) << std::endl; //functor

	struct DeleteA{
		bool operator()(std::string &s1)const{
			return s1[0] == 'a';}
	};
	std::list<std::string> data = { "ab", "c", "cab", "ac", "bb" };
data.remove_if(DeleteA());
	std::list<std::string>::iterator it;
	for (it = data.begin(); it != data.end(); ++it){
		std::cout << *it << std::endl;
	}

	int x = 100;
	const int* px = &x;
	int* ppx = const_cast<int*>(px);
	*ppx = 99;
	std::cout << x << std::endl;	// if const int x = 100;	->	cout: x=100;
	std::cout << *ppx << std::endl;

	BinaryTree<double> obj;
	obj.insert(30.5);	//deletecurr ~ #1 #2 #3 work
	obj.insert(20);
	obj.insert(25);
	obj.insert(10);
	obj.insert(11);
	//obj.insert(2);
	obj.print();
	bool b = obj.find(30);
	std::cout << std::endl << b << std::endl;
	BinaryTree<double> vobj=obj;
	vobj.print();
	std::cout << std::endl << vobj.getMin() << std::endl;
	std::cout << vobj.getMax() << std::endl;
	std::cout << vobj.getSize() << std::endl;
	obj.deleteValue(10);
	obj.print();

	std::cout << std::endl;
	BinaryTree<int> obj1;
	obj1.insert(10);	//deletecurr ~ #1 #2 #3 work
	obj1.insert(17);
	obj1.insert(25);
	obj1.insert(15);
	obj1.insert(12);
	obj1.print();
	std::cout << endl;
	obj1.insert(12);
	obj1.deleteValue(17); //
	obj1.print();
	system("pause");
    return 0;
}

