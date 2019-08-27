// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "iostream"
int function(int* arr, int N) {//N must be >=3
	int max=0, P;
	for (int i = 0; i < N - 2; ++i) {
		for (int j = i + 1; j < N - 1; ++j) {
			for (int k = j + 1; k < N; ++k) {
				P = arr[i] * arr[j] * arr[k];
				if (P > max) {
					max = P;
				}
			}
		}
	}
	return max;
}
int main()
{
	setlocale(LC_ALL, "rus");
	const int N = 5;
	int arr[] = { -10,-10,1,3,2 };
	int max=0;
	max=function(arr, N);
	std::cout <<"максимум:"<< max /*<<"="<<ai<<"*" << aj << "*" << ak*/ << std::endl;
	system("pause");
    return 0;
}

