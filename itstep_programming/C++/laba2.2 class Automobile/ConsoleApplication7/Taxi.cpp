#include "stdafx.h"
#include "Taxi.h"


int Taxi::count=0;

Taxi::~Taxi()
{
}

void Taxi::setRate(const double sr){
	rate = sr;
}

double Taxi::getSum()const{
	return allTheMoney;
}

double Taxi::taxRate(const double minutes)
{
	allTheMoney += rate*mediumSpeed_*minutes / 60.0;
	return rate*mediumSpeed_*minutes / 60.0;
}

void Taxi::getInfo() const
{
	std::cout << "mark: " << this->mark_ << std::endl << "model: " << this->model_ << std::endl <<
		"year of issue: " << this->yearOfIssue_ << std::endl << "medium speed: " 
		<< this->mediumSpeed_ << std::endl << "tax rate: " << rate << std::endl;
}


int Taxi::getCountTaxi() {
	return count;
}

void Taxi::move(){
	std::cout << "Taxi - движение на колесах" << std::endl;
}