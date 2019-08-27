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

//продолжение

Date::Date(int m, int d, int y, int h, int min, int s)
	:month(m), day(d), year(y), hour(h), minute(min), second(s)
{
}

void Date::increaseSecond(int s)
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	if (s >= 86400) { //seconds per day
		int f;
		f = s / 86400;
		s = s % 86400;
		while (f > 0) {
			f--;
			day++;
			if (day > days[month - 1] && day == (days[1] + 1)) {
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
	

	if (s >= 3600) {//seconds per hour
		int fh; fh = s / 3600;
		s = s / 3600;
		while (fh > 0) {
			fh--;
			hour++;
			if (hour == 24) {
				day++; hour = 0;
				if (day > days[month - 1] && day == (days[1] + 1)) {
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
		
	}
	

	if (s >= 60) {//seconds per minute
		int fm = s / 60;
		s = s % 60;
		while (fm > 0) {
			fm--;
			minute++;
			if (minute == 60) {
				hour++; minute = 0;
				if (hour == 24) {
					day++; hour = 0;
					if (day > days[month - 1] && day == (days[1] + 1)) {
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
		}
	}


	while (s > 0) {
		second++;
		s--;
		if (minute == 60) {
			hour++; minute = 0;
			if (hour == 24) {
				day++; hour = 0;
				if (day > days[month - 1] && day == (days[1] + 1)) {
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
	}
}

void Date::showNewDate()
{
	std::cout << "month:" << month << "\nday:" << day << "\nyear:" << year << "\nhour:" << hour << "\nminute:" << minute << "\nsecond:" << second << std::endl;
}

Date Date::operator()(int m, int d, int y, int h, int min, int s)
{
	month = m; day = d; year = y; hour = h; minute = min; second = s;
	return Date();
}

Date Date::operator++()
{
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	second++;
	if (second == 60) {
		minute++; second = 0;
		if (minute == 60) {
			hour++; minute = 0;
			if (hour == 24) {
				day++; hour = 0;
				if (day > days[month - 1] && day == (days[1] + 1)) {
					if (day == 29 && month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400)) {
						day = 29;
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
	}

	return Date();
}

Date Date::operator++(int n)
{
	Date temp=*this;
	int days[12] = { 31,28,31,30,31,30,31,31,30,31,30,31 };
	second++;
	if (second == 60) {
		minute++; second = 0;
		if (minute == 60) {
			hour++; minute = 0;
			if (hour == 24) {
				day++; hour = 0;
				if (day > days[month - 1] && day == (days[1] + 1)) {
					if (day == 29 && month == 2 && ((year % 4 == 0 && year % 100 != 0) || year % 400)) {
						day = 29;
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
	}
	return temp;
}

bool Date::operator!=(const Date & vD)
{

	return (month!=vD.month || day!=vD.day || year!=vD.year || hour!=vD.hour || minute!=vD.minute || second!=vD.second);
}

bool Date::operator==(const Date & vD)
{
	return (month == vD.month && day == vD.day && year == vD.year && hour == vD.hour && minute == vD.minute && second == vD.second);;
}

bool Date::operator>(const Date & vD)
{
	if (year > vD.year)return true;
	if (month > vD.month)return true;
	if (day > vD.day)return true;
	if (hour > vD.hour)return true;
	if (minute > vD.minute)return true;
	if (second > vD.second)return true;
	else return false;
}

bool Date::operator<(const Date & vD)
{
	if (year < vD.year)return true;
	if (month < vD.month)return true;
	if (day < vD.day)return true;
	if (hour < vD.hour)return true;
	if (minute < vD.minute)return true;
	if (second < vD.second)return true;
	else return false;
}

Date Date::operator=(const Date & vD)
{
	*this = vD;
	return *this;
}

std::ostream & operator<<(std::ostream & os, const Date & dt)
{
	os << "month: " << dt.month << std::endl;
	os << "day: " << dt.day << std::endl;
	os << "year: " << dt.year << std::endl;
	os << "hour: " << dt.hour << std::endl;
	os << "minute: " << dt.minute << std::endl;
	os << "second: " << dt.second << std::endl;
	// TODO: insert return statement here
	return os;
}

std::istream & operator>>(std::istream & is, Date & dt)
{
	std::cout << "Enter month: " << std::endl;
	is >> dt.month;
	std::cout << "Enter day: " << std::endl;
	is >> dt.day;
	std::cout << "Enter year: " << std::endl;
	is >> dt.year;
	std::cout << "Enter hour: " << std::endl;
	is >> dt.hour;
	std::cout << "Enter minute: " << std::endl;
	is >> dt.minute;
	std::cout << "Enter second: " << std::endl;
	is >> dt.second;
	// TODO: insert return statement here
	return is;
}
