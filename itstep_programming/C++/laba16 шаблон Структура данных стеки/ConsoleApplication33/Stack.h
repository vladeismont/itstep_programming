#pragma once
#include <cassert> // для assert
#include <iostream>
#include <iomanip> // для setw

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // указатель на стек
	const int size;                   // максимальное количество элементов в стеке
	int top;                          // номер текущего элемента стека
public:
	Stack() { top = 0; };
	Stack(int = 10);                  // по умолчанию размер стека равен 10 элементам
	Stack(const Stack<T> &);          // конструктор копирования
	~Stack();                         // деструктор
	inline bool empty();
	inline void push(const T &);     // поместить элемент в вершину стека
	inline void pop();                   // удалить элемент из вершины стека и вернуть его
	inline void printStack();         // вывод стека на экран
	inline const T &Peek(int) const; // n-й элемент от вершины стека
	inline int getStackSize() const;  // получить размер стека
	inline T *getPtr() const;         // получить указатель на стек
	inline int getTop() const;        // получить номер текущего элемента в стеке
	T Stack<T>::operator=(const Stack<T>& obj);
	bool operator==(const Stack<T>& obj);
	bool operator!=(const Stack<T>& obj);
	T& operator[](const int index);
};

// реализация методов шаблона класса STack

// конструктор Стека
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под стек
	top = 0; // инициализируем текущий элемент нулем;
}

// конструктор копирования
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // инициализация константы
{
	stackPtr = new T[size]; // выделить память под новый стек
	top = otherStack.getTop();

	for (int i = 0; i < top; ++i)
		stackPtr[i] = otherStack.getPtr()[i];
}

// функция деструктора Стека
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // удаляем стек
}

template<typename T>
inline bool Stack<T>::empty()
{
	if (top > 0)
		return false;
	else
		return true;
}

// функция добавления элемента в стек
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// проверяем размер стека
	assert(top < size); // номер текущего элемента должен быть меньше размера стека

	stackPtr[top++] = value; // помещаем элемент в стек
}

// функция удаления элемента из стека
template <typename T>
inline void Stack<T>::pop()
{
	// проверяем размер стека
	assert(top > 0); // номер текущего элемента должен быть больше 0

	stackPtr[--top]; // удаляем элемент из стека
}


// функция возвращает n-й элемент от вершины стека
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // вернуть n-й элемент стека
}

// вывод стека на экран
template <typename T>
inline void Stack<T>::printStack()
{
	for (int i = top - 1; i >= 0; --i)
		std::cout << stackPtr[i] << std::endl;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// вернуть указатель на стек (для конструктора копирования)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// вернуть размер стека
template <typename T>
inline int Stack<T>::getTop() const
{
	return top;
}

template<typename T>
inline T  Stack<T>::operator=(const Stack<T>& obj)
{
	const int size = obj.getStackSize();
	delete[] stackPtr;
	stackPtr = new T[size]; // выделить память под новый стек
	top = obj.getTop();

	for (int i = 0; i < top; ++i)
		stackPtr[i] = obj.getPtr()[i];
	return T();
	// TODO: insert return statement here
}

template<typename T>
inline bool Stack<T>::operator==(const Stack<T>& obj)
{
	int f = 0;
	for (int i = 0; i < top; ++i) {
		if (stackPtr[i] != obj.stackPtr[i]) {
			f = 1; break;
		}
	}
	if (f == 1)
		return false;
	else
		return true;
}

template<typename T>
inline bool Stack<T>::operator!=(const Stack<T>& obj)
{
	int f = 0;
	for (int i = 0; i < top; ++i) {
		if (stackPtr[i] == obj.stackPtr[i]) {
			++f;
		}
	}
	if (f != obj.getTop())
		return true;
	else
		return false;
}

template<typename T>
inline T & Stack<T>::operator[](const int index)
{
	if (index > top || index < 0) { std::cout << "Error " << std::endl; exit(1); }
	else { return stackPtr[index]; }
	// TODO: insert return statement here
}
