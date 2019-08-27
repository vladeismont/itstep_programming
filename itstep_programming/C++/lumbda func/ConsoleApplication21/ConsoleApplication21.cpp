// ConsoleApplication21.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <iterator>

bool del(const std::string& str) {
	return str.size() == 3; 
}
void f(){
	std::vector<std::string> data = {"abc", "c", "cba", "ac", "b"};
	size_t res = std::count_if(data.begin(), data.end(), del);
	std::cout<< res << std::endl;
}
void f1(){ std::vector<std::string> data = { "abc", "c", "cba", "ac", "b" };
	std::vector<std::string> res;
	std::back_insert_iterator<std::vector<std::string>> it(res);
	std::copy_if(data.begin(), data.end(), it, del);
	for (auto s : res) { std::cout << s << " "; } 
}

/*class Pred{ 
	int div;
public:
	Pred(const int a) : div(a) { }
	bool operator()(const int value) const{
		return value % div == 0; } 
	}; 
void f2(){
	std::vector<int> data = { 2, 4, 6, 3, 7, 10, 18, 4, 2, 2 };
	std::replace_if(data.begin(), data.end(), Pred(2), 0); 
	for (int& x : data) std::cout << ' ' << x;
	std::cout << '\n';
}*/
class Pred{ 
	char del_symb;
public:
	Pred() { }
	Pred(char s) : del_symb(s) {}
	bool operator()(const std::string str) const {
		if (std::find(str.begin(), str.end(), del_symb) != str.end()){
			return true; 
		}
		return false; 
	} 
};
void f3(){ 
	std::vector<std::string> d = { "dog", "cat", "parrot", "mouse" };
	d.erase(std::remove_if(d.begin(), d.end(), Pred('o')), d.end()); //удаление элементов содержащих символ
	for (std::string& x : d) std::cout << ' ' << x;
	std::cout << '\n';
}

#include <functional>
void printArgs(const int x, const int y, const int z) {
	std::cout<< x << ' '<< y << ' '<< z << std::endl;
}
void f4(){
	using namespace std::placeholders;
	auto func1 = std::bind(printArgs, _1, _2, _3);
	func1(10, 11, 12);// 10 11 12
	auto func2 = std::bind(printArgs, _1, _3, _2);
	func2(10, 11, 12);// 10 12 11
	auto func3 = std::bind(printArgs, _3, _2, _1);
	func3(10, 11, 12);// 12 11 10
}

void f5(){ 
	using namespace std::placeholders;
	std::vector<double> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::replace_if(vec.begin(), vec.end(), (std::bind(std::less<double>(), _1, 5)), 0); 
	for (auto value : vec) {
		std::cout << value << " "; 
	} 
}
void f6(){
	using namespace std::placeholders;
	std::vector<double> vec = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	std::replace_if(vec.begin(), vec.end(), (std::bind(std::less<double>(), 5, _1)), 0);
	for (auto value : vec) {
		std::cout << value << " ";
	}
}
int _tmain(int argc, _TCHAR* argv[])
{
	f();
	f1();
	//f2();
	std::cout << '\n';
	f3();
	f4();
	std::cout << '\n';
	f5();
	std::cout << '\n';
	f6();
	system("pause");
	return 0;
}

