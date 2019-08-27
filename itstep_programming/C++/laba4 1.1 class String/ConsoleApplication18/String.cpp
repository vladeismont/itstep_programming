#include "stdafx.h"
#include "String.h"


String::String()
{
	length_ = 80;
	pStr_ = new char[length_+1];
	strcpy(pStr_, "");
}

String::String(int len)
{
	pStr_ = new char[len+1];
	pStr_[len] = '\0';
	length_ = len;
}

String::String(const char *vChar)
{
	pStr_ = new char[strlen(vChar)+1];
	strcpy(pStr_, vChar);
	length_ = strlen(vChar);
}

String::String(const String &obj)
{
	pStr_=new char[obj.length_+1];
	strcpy(pStr_, obj.pStr_);
	length_ = obj.length_;
}

void String::getString() const
{
	std::cout << strlen(pStr_) << " " << length_<<" = "<<pStr_ << std::endl;
}

void String::setString()
{
	std::cout << "Enter the string:" << std::endl;
	char string_[500];
	gets_s(string_);
	strcpy(pStr_, string_);
	//fgets(pStr_, 80, stdin); ////
	length_ = strlen(pStr_);
}


String::~String()
{
	delete[] pStr_;
}
