#pragma once
#include "utility" // pair
#include "iostream"
static int count = 0;
class Area
{
public:
	Area();
	static float getTriangleArea(const float, const float);
	static float getTriangleArea(const std::pair<const float, const float>p, const float);
	static float getTriangleArea(const float, const float,const float);
	static float getCount();
	static float getRectangleArea(const float, const float); // �������������
	static float getSquareArea(const float); //�������
	static float getSquareArea(const float, const float);
	static float getParallelogramArea(const float, const float); // ��������������
	static float getParallelogramArea(const float, const float, const float);
	static float getRombusArea(const float, const float); // ����
	static float getRombusArea(const std::pair<const float, const float>p);
	~Area();
};

