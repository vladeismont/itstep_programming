#pragma once
#include "Pet.h"
#include "Bird.h"
class Parrot :virtual Pet, virtual Bird
{
	std::string str;
public:
	Parrot(std::string s);
	void sound() { std::cout << "vorooona" << std::endl; }
	void show() { std::cout << str << std::endl; }
	void type() { std::cout << "bird parrot" << std::endl; }
	~Parrot();
};

