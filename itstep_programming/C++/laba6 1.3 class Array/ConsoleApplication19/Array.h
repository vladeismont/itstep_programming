#pragma once
class Array
{
	int* array_; 
	int max;
	int min;
	int f; //количество чисел
	void maxMin();
public:
	Array() {};
	Array(int n);
	~Array();
	void setArray(int n);
	void getArray();
	void changeArray(int n);
	void getMax();
	void getMin();
	void sortArray();
	Array(const Array& vA);
	//продолжение
	int operator[](int x);
	Array operator()(int n);
	operator int()const; // приведение(преобразование) типов //int a=obj;
	//operator std::string()const;
	operator char*()const;
};

