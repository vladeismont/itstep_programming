#include "stdafx.h"
#include "Date.h"

Date::Date()
{
	month = 0, day = 1, year = 0;
}
Date::~Date()
{
}
Date::Date(int Month, int Day, int Year) :month(Month), day(Day), year(Year)
{
	/*month = Month;
	day = Day;
	year = Year;*/
}
void Date::setDay(int d)
{
	if (d < 1 && d > 31)
		std::cout << "The day is invalid" << std::endl;
	else
		day = d;

}
void Date::setMonth(int m)
{
	if (m < 1 && m > 12)
		std::cout << "The month is invalid" << std::endl;
	else
		month = m;

}
void Date::setYear(int y)
{
	if (y < 1950 && y > 2020)
		std::cout << "The year is invalid" << std::endl;
	else
		year = y;
}
void Date::setDate(int x, int y, int z) {
	day = x;
	month = y;
	year = z;
}
void Date::showDate()
{
	std::string monthName[] = { "January", "February", "March",
		"April", "May", "June", "July",
		"August", "September", "October",
		"November", "December" };
	std::cout << day << "  " << monthName[month - 1] << "  " << year << std::endl;
}
void Date::initDMY(const int Day, const int Month, const int Year) {
	day = Day;
	month = Month;
	year = Year;
}
void Date::initMDY(const int Month, const int Day, const int Year) {
	day = Day;
	month = Month;
	year = Year;
}
void Date::increaseYear(const int a) {
	year += a;
}
void Date::increaseMonth(int a) {
	while (a > 0) {
		a--;
		if (month == 12) {
			year++; month = 1;
		}
		else {
			month++;
		}
	}
}
void Date::increaseDay(int d) {
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	while (d > 0) {
		d--;
		day++;
		if (day > days[month - 1] && day==(days[1]+1)) {
			if (day == 29 && month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400)) {
				day = 29;
				continue;
			}
		}

		if (day > days[month - 1]) {
			day = 1; month++;
			if (month == 12) {
				day = 1; month = 1; year++;
			}
		}
	}
}