#pragma once

#include <iostream>

class MyString
{
	static const int maxLen = 100;
	int length;
	char* string;
public:
	MyString();
	explicit MyString(const char*);
	explicit MyString(const int);
	MyString(const char*, const int);
	MyString(const MyString&);
	MyString& operator=(const MyString&);
	~MyString(){ delete[] string; };

	const int getLength() const;
	const char* getString() const;

	MyString operator+(const MyString&);
	// TODO: operator+ для char* и MyString
	friend MyString operator+(const char* str,const MyString& obj);
	// TODO: operator++ и operator--
	MyString operator++(int n);
	MyString operator--(int n);
	friend bool operator==(const MyString&, const MyString&);
	// TODO: operator!=
	friend bool operator!=(const MyString& a, const MyString& b);
	char& operator[](const int index);
	// TODO: operator()
	MyString operator()(const int x, const int y);
	// TODO: преобразование к char*
	operator char*() const;

	friend std::ostream& operator<<(std::ostream&, const MyString&);
	// TODO: operator>>
	friend std::istream& operator>>(std::istream&, MyString&);
	// TODO: operator*
	MyString operator*(MyString obj);
	
	MyString(MyString&& other);//move constructor
	MyString& MyString::operator=(MyString&& other); //move assignment operator
};
