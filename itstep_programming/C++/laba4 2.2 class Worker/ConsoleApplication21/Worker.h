#pragma once
class Worker
{
	struct Tdata {
		std::string FIO_;
		std::string doljnost_;
		int year_;
		int zarplata_;
	}data;
public:
	Worker();
	Worker(std::string FIO, std::string doljnost, int year, int zarplata);
	int staj()const;
	void show()const;
	int getZarplata()const;
	std::string getDoljnost()const;
	~Worker();
};

