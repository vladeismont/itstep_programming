#pragma once
#include "Pet.h"
class Hamster:public Pet
{
	std::string str;
public:
	Hamster(std::string s);
	void sound() { std::cout << "hfc" << std::endl; }
	void show() { std::cout << str << std::endl; }
	void type() { std::cout << "hamster" << std::endl; }
	~Hamster();
};

