#include "stdafx.h"
#include "Automobile.h"




Automobile::Automobile(const std::string mark, const std::string model, const int yearOfIssue, const double mediumSpeed)
{
	mark_ = mark;
	model_ = model;
	yearOfIssue_ = yearOfIssue;
	mediumSpeed_ = mediumSpeed;
}

Automobile::~Automobile()
{
}

void Automobile::setAuto(const std::string mark, const std::string model, const int yearOfIssue, const double mediumSpeed){
	mark_ = mark;
	model_ = model;
	yearOfIssue_ = yearOfIssue;
	mediumSpeed_ = mediumSpeed;
}


std::string Automobile::getMark()const {
	return mark_;
}

std::string Automobile::getModel()const{
	return model_;
}

int Automobile::getYearOfIssue()const{
	return yearOfIssue_;
}
double Automobile::getMediumSpeed()const{
	return mediumSpeed_;
}

void Automobile::setMediumSpeed(const double mediumSpeed){
	mediumSpeed_ = mediumSpeed;
}

void Automobile::getInfo() const
{
	std::cout << "mark: " << this->mark_ << std::endl << "model: " << this->model_ << std::endl << "year of issue: " << this->yearOfIssue_ << std::endl << "medium speed: " << this->mediumSpeed_ << std::endl;
}

void Automobile::move(){
	std::cout << "Automobile - движение на колесах" << std::endl;
}