#pragma once
#include <iostream>
#include "Transport.h"
class Automobile:public Transport
{
protected:
	std::string mark_, model_;
	int yearOfIssue_;
	double mediumSpeed_;
public:
	Automobile(const std::string, const std::string, const int, const double);
	~Automobile();

	void setAuto(const std::string, const std::string, const int, const double);
	std::string getMark()const;
	std::string getModel()const;
	int getYearOfIssue()const;
	double getMediumSpeed()const;
	void setMediumSpeed(const double);
	double computeDistance(const int);
	void getInfo()const;
	void move();
};

inline double Automobile::computeDistance(const int minutes){
	return mediumSpeed_*minutes / 60.0;
}
