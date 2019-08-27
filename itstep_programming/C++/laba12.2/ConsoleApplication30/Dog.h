#pragma once
#include "Pet.h"
class Dog:public Pet
{
	std::string str;
public:
	Dog(std::string s);
	void sound(){ std::cout << "Gaaw" << std::endl; }
	void show() { std::cout << str << std::endl; }
	void type() { std::cout << "dog" << std::endl; }
	~Dog();
};

