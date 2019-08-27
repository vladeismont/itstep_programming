#pragma once
class Book
{
	std::string avtor_, nazvanie_, izdatelstvo_;
	int year_, stranic_;
public:
	Book();
	~Book();
	explicit Book(std::string avtor, std::string nazvanie, std::string izdatelstvo, int year, int stranic);
	std::string getAvtor();
	std::string getIzdatelstvo();
	int getYear()const;
	void getBook()const;
};

