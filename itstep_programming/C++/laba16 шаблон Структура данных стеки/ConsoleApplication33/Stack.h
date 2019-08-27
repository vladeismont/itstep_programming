#pragma once
#include <cassert> // ��� assert
#include <iostream>
#include <iomanip> // ��� setw

template <typename T>
class Stack
{
private:
	T *stackPtr;                      // ��������� �� ����
	const int size;                   // ������������ ���������� ��������� � �����
	int top;                          // ����� �������� �������� �����
public:
	Stack() { top = 0; };
	Stack(int = 10);                  // �� ��������� ������ ����� ����� 10 ���������
	Stack(const Stack<T> &);          // ����������� �����������
	~Stack();                         // ����������
	inline bool empty();
	inline void push(const T &);     // ��������� ������� � ������� �����
	inline void pop();                   // ������� ������� �� ������� ����� � ������� ���
	inline void printStack();         // ����� ����� �� �����
	inline const T &Peek(int) const; // n-� ������� �� ������� �����
	inline int getStackSize() const;  // �������� ������ �����
	inline T *getPtr() const;         // �������� ��������� �� ����
	inline int getTop() const;        // �������� ����� �������� �������� � �����
	T Stack<T>::operator=(const Stack<T>& obj);
	bool operator==(const Stack<T>& obj);
	bool operator!=(const Stack<T>& obj);
	T& operator[](const int index);
};

// ���������� ������� ������� ������ STack

// ����������� �����
template <typename T>
Stack<T>::Stack(int maxSize) :
	size(maxSize) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����
	top = 0; // �������������� ������� ������� �����;
}

// ����������� �����������
template <typename T>
Stack<T>::Stack(const Stack<T> & otherStack) :
	size(otherStack.getStackSize()) // ������������� ���������
{
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
	top = otherStack.getTop();

	for (int i = 0; i < top; ++i)
		stackPtr[i] = otherStack.getPtr()[i];
}

// ������� ����������� �����
template <typename T>
Stack<T>::~Stack()
{
	delete[] stackPtr; // ������� ����
}

template<typename T>
inline bool Stack<T>::empty()
{
	if (top > 0)
		return false;
	else
		return true;
}

// ������� ���������� �������� � ����
template <typename T>
inline void Stack<T>::push(const T &value)
{
	// ��������� ������ �����
	assert(top < size); // ����� �������� �������� ������ ���� ������ ������� �����

	stackPtr[top++] = value; // �������� ������� � ����
}

// ������� �������� �������� �� �����
template <typename T>
inline void Stack<T>::pop()
{
	// ��������� ������ �����
	assert(top > 0); // ����� �������� �������� ������ ���� ������ 0

	stackPtr[--top]; // ������� ������� �� �����
}


// ������� ���������� n-� ������� �� ������� �����
template <class T>
inline const T &Stack<T>::Peek(int nom) const
{
	//
	assert(nom <= top);

	return stackPtr[top - nom]; // ������� n-� ������� �����
}

// ����� ����� �� �����
template <typename T>
inline void Stack<T>::printStack()
{
	for (int i = top - 1; i >= 0; --i)
		std::cout << stackPtr[i] << std::endl;
}

// ������� ������ �����
template <typename T>
inline int Stack<T>::getStackSize() const
{
	return size;
}

// ������� ��������� �� ���� (��� ������������ �����������)
template <typename T>
inline T *Stack<T>::getPtr() const
{
	return stackPtr;
}

// ������� ������ �����
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
	stackPtr = new T[size]; // �������� ������ ��� ����� ����
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
