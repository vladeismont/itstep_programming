#include "stdafx.h"
#include "Area1.h"
#include "cmath"
Area1::Area1()
{
}
Area1::~Area1()
{
}
float Area1::getTriangleArea1(const float a, const float b) {
	count++;
	return a*b / 2;
}
float Area1::getTriangleArea1(const std::pair<const float, const float>sides, const float angle) {
	count++;

	return sides.first*sides.second*sin(angle * (4 * atan(1)) / 180) / 2; //grad = rad * (180/pi);//long double Pi = 4 * atan(1.);
}
float Area1::getTriangleArea1(const float a, const float b, const float c) {
	count++;
	return sqrt((a + b + c) / 2 * ((a + b + c) / 2 - a)*((a + b + c) / 2 - b)*((a + b + c) / 2 - c));
}
float Area1::getCount() {
	return count;
}
float Area1::getSquareArea1(const float a) {
	count++;
	return Area1::getRectangleArea1(a, a);
	//return a*a;
}
float Area1::getSquareArea1(const float a, const float b) {
	count++;
	return Area1::getRectangleArea1(a, b);
	//return a*b;
}
float Area1::getRectangleArea1(const float a, const float b) {
	count++;
	return a*b;
}
float Area1::getParallelogramArea1(const float a, const float b) {
	count++;
	return 2*(Area1::getTriangleArea1(a, b));
	//return a*b;
}
float Area1::getParallelogramArea1(const float a, const float b, const float angle) {
	count++;
	const std::pair<const float, const float>myPair1 = std::make_pair(a, b);
	return 2*Area1::getTriangleArea1(myPair1, angle);
	//return a*b*sin(angle * (4 * atan(1)) / 180);
}
float Area1::getRombusArea1(const float a, const float b) {
	count++;
	return Area1::getSquareArea1(a, b)/2;
	//return a*b / 2;
}
float Area1::getRombusArea1(const std::pair<const float, const float>sides) {
	count++;
	return sides.first*sides.first*sin(sides.second * (4 * atan(1)) / 180);//grad = rad * (180/pi);//long double Pi = 4 * atan(1.);
}