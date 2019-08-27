#pragma once
#include "utility" // pair
#include "iostream"
static int count = 0;
class Area1
{
public:
	Area1();
	static float getTriangleArea1(const float, const float);
	static float getTriangleArea1(const std::pair<const float, const float>p, const float);
	static float getTriangleArea1(const float, const float, const float);
	static float getCount();
	static float getRectangleArea1(const float, const float); // прямоугольник
	static float getSquareArea1(const float); //квадрат
	static float getSquareArea1(const float, const float);
	static float getParallelogramArea1(const float, const float); // параллелограмм
	static float getParallelogramArea1(const float, const float, const float);
	static float getRombusArea1(const float, const float); // ромб
	static float getRombusArea1(const std::pair<const float, const float>p);
	~Area1();
};

