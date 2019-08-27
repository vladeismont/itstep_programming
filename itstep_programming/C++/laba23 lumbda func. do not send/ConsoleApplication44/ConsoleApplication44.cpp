// ConsoleApplication44.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
template<typename T>
void show(double x, T& fp) {
	std::cout << x << " -> " << fp(x) << std::endl;
}
double func(double x) { std::cout << x << std::endl; return 1.8 * x + 32; }
void func1(std::vector<int> myvector) {
	for_each(myvector.begin(), myvector.end(), [myvector](int _n)
	{
		std::cout << _n << " ";
	});
}
int main()
{
	show(10.1, func);
	show(10.1, [](const double x) {return 1.8 * x + 32; });

	std::vector<int> myvector(6);
	for (int i = 0; i <= 5; i++) myvector[i]=i;
	myvector.push_back(-5);
	for (std::vector<int>::iterator it = myvector.begin(); it != myvector.end(); ++it)
		std::cout << ' ' << *it;
	std::cout << '\n';

	[&myvector](int n) {	//unable to read memory (capacity) -size???
		std::sort(myvector.rbegin(), myvector.rend());	//unable to display value ([])
		std::reverse(myvector.begin(), myvector.end()); // unable to read meamory (Dimensions)
		return myvector; };	//похоже нельзя вектор передовать в лямбда ф-ию
	std::cout << '\n';
	for_each(myvector.begin(), myvector.end(), [myvector](int _n)
	{
		std::cout << _n << " ";
	});
	func1(myvector);
	system("pause");
    return 0;
}

