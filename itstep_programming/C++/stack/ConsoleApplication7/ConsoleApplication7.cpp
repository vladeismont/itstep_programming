// ConsoleApplication7.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "MYStack.h"
#include "iostream"
using namespace std;

int main()
{
	setlocale(LC_ALL, "rus");
	int po;
	const int N = 11;
	int arr[N] = { 12,24,54,6,32,54,25,3,6,63,4 };
	MYStack Stack;
	for (int i = 0; i < N; i++) {
		cout << "в стек заносится i-ый элемент: "<< arr[i] << endl;
		Stack.push(arr[i]);
	}
	cout << "*******************************\n";
	for (int i = 0; i < N; i++) {
		
		Stack.pull(po);
		cout<<"достаем значение из стека: "<<po<<endl;
	}
	cout << endl;
	system("pause");
	return 0;
}