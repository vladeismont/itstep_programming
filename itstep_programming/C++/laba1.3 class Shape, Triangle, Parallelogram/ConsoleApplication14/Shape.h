#pragma once
class Shape
{
public:
	Shape();
	virtual double getArea()=0; //абстрактный класс, нельзя создать объект
	virtual~Shape();
};

