#pragma once
#include "Pet.h"
class Cat:public Pet
{
	std::string str;
public:
	Cat(std::string s);
	void sound() { std::cout << "meww" << std::endl; }
	void show() { std::cout << str << std::endl; }
	void type() { std::cout << "cat" << std::endl; }
	~Cat();
};

