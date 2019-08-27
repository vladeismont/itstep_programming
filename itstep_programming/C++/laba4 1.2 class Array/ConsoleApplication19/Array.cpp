#include "stdafx.h"
#include "Array.h"


Array::Array(int n)
{
	f = n;
	array_ = new int[n];
	for (int i = 0; i < n; ++i) {
		array_[i] = rand();
	}
	maxMin();
	
}


Array::~Array()
{
	delete[] array_;
}

void Array::setArray(int n)
{
	f = n;
	array_ = new int[n];
	for (int i = 0; i < n; ++i) {
		array_[i] = rand();
	}
	maxMin();
}

void Array::getArray()
{
	for (int i = 0; i < f; ++i) {
		std::cout << array_[i] << std::endl;
	}
}

void Array::changeArray(int n) // пересоздание массива с другим размером и данными
{
	delete[] array_; 
	f = n;
	array_ = new int[n];
	for (int i = 0; i < n; ++i) {
		array_[i] = rand();
	}
	maxMin();
}

void Array::getMax()
{
	std::cout << max << std::endl;
}

void Array::getMin()
{
	std::cout << min << std::endl;
}

void Array::sortArray()
{
	for (int i = 0; i < f - 1; i++) {
		for (int j = 0; j < f - i - 1; j++) {
			if (array_[j] > array_[j + 1]) {
				// меняем элементы местами
				int temp = array_[j];
				array_[j] = array_[j + 1];
				array_[j + 1] = temp;
			}
		}
	}
}

void Array::maxMin()
{
	max = min = array_[0];
	for (int i = 1; i < f; ++i) {
		if (max < array_[i]) {
			max = array_[i];
		}
		if (min > array_[i]) {
			min = array_[i];
		}
	}
}

Array::Array(const Array & vA)
{
	f = vA.f;
	array_ = new int[f];
	for (int i = 0; i < f; ++i) {
		array_[i] = vA.array_[i];
	}
	max = vA.max;
	min = vA.min;
}
