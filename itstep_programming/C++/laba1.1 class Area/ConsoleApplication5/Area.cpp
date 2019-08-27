#include "stdafx.h"
#include "Area.h"
#include "cmath"
Area::Area()
{
}
Area::~Area()
{
}
float Area::getTriangleArea(const float a, const float b){
	count++;
	return a*b / 2;
}
float Area::getTriangleArea(const std::pair<const float, const float>sides, const float angle){
	count++;
	
	return sides.first*sides.second*sin(angle * (4 * atan(1))/180)/2; //grad = rad * (180/pi);//long double Pi = 4 * atan(1.);
}
float Area::getTriangleArea(const float a, const float b, const float c){
	count++;
	return sqrt((a + b + c) / 2 * ((a + b + c) / 2 - a)*((a + b + c) / 2 - b)*((a + b + c) / 2 - c));
}
float Area::getCount(){
	return count;
}
float Area::getSquareArea(const float a){
	count++;
	return a*a;
}
float Area::getSquareArea(const float a, const float b){
	count++;
	if (a == b)
		return a*b;
	else
	{
		std::cout << "стороны не равны" << std::endl; system("pause"); exit(0);
	};
}
float Area::getRectangleArea(const float a, const float b){
	count++;
	return a*b;
}
float Area::getParallelogramArea(const float a, const float b){
	count++;
	return a*b;
}
float Area::getParallelogramArea(const float a, const float b,const float angle){
	count++;
	return a*b*sin(angle * (4 * atan(1)) / 180);
}
float Area::getRombusArea(const float a, const float b) {
	count++;
	return a*b / 2;
}
float Area::getRombusArea(const std::pair<const float, const float>sides) {
	count++;
	return sides.first*sides.first*sin(sides.second * (4 * atan(1)) / 180);//grad = rad * (180/pi);//long double Pi = 4 * atan(1.);
}