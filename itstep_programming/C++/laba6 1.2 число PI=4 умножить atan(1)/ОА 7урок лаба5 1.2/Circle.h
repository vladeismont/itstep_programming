#pragma once
class Circle
{
	double radius_, x_, y_;
public:
	Circle();
	Circle(double r,double x, double y);
	void setCircle(double r, double x, double y);
	~Circle() = default;
	bool operator==(const Circle& obj) const;
	bool operator>(const Circle& obj) const;
	bool operator<(const Circle& obj) const;
	Circle& operator+=(const double x);
	Circle& operator-=(const double x);
	double getRadius() const;
	void Circle::operator()(double r, double x, double y);
	double getArea()const;
	double getLength()const;
};

