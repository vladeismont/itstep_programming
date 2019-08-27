// ConsoleApplication30.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Pet.h"
#include "Dog.h"
#include "Cat.h"
#include "Hamster.h"
#include "Parrot.h"
int main()
{
	Dog obj("Reks");
	Cat obj1("Tom");
	Hamster obj2("Moor");
	Parrot obj3("Gosha");
	obj.show();
	obj.sound();
	obj1.show();
	obj1.sound();
	obj2.show();
	obj2.sound();
	obj3.show();
	obj3.sound();
	obj.type();
	obj1.type();
	obj2.type();
	obj3.type();
	system("pause");
    return 0;
}

