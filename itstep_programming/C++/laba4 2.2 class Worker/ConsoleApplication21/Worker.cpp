#include "stdafx.h"
#include "Worker.h"


Worker::Worker()
{
}

Worker::Worker(std::string FIO, std::string doljnost, int year, int zarplata)
{
	data.FIO_ = FIO;
	data.doljnost_ = doljnost;
	data.year_ = year;
	data.zarplata_ = zarplata;
}

int Worker::staj()const
{
	return 2016-data.year_;
}

void Worker::show() const
{
	std::cout << data.FIO_ << std::endl;
}

int Worker::getZarplata() const
{
	return data.zarplata_;
}

std::string Worker::getDoljnost() const
{
	return data.doljnost_;
}


Worker::~Worker()
{
}
