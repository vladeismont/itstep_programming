#include "stdafx.h"
#include "Book.h"


Book::Book()
{
	
}


Book::~Book()
{
}

Book::Book(std::string avtor, std::string nazvanie, std::string izdatelstvo, int year, int stranic)
{
	avtor_ = avtor;
	nazvanie_ = nazvanie;
	izdatelstvo_ = izdatelstvo;
	year_ = year;
	stranic_ = stranic;
}

std::string Book::getAvtor()
{
	return avtor_;
}

std::string Book::getIzdatelstvo()
{
	return izdatelstvo_;
}

int Book::getYear() const
{
	return year_;
}

void Book::getBook() const
{
	std::cout << "�����: " << avtor_ << "\n��������: " << nazvanie_ << "\n������������: "
		<< izdatelstvo_ << "\n���: " << year_ << "\n���������� �������: " << stranic_ << std::endl;
}
