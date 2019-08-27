#include "stdafx.h"
#include "MyString.h"

MyString::MyString() :
length(maxLen), string(new char[length+1])
{
	strcpy(string, "");
}

MyString::MyString(const char* str){
	
	if(strlen(str)>100){
		length = maxLen;
		string = new char[maxLen + 1];
		strncpy(string, str, maxLen);
	}
	else {
		length = strlen(str);
		string = new char[length + 1];
		strcpy(string, str);
	}
}

MyString::MyString(const int len)
{
	if (len > maxLen || len < 0){ 
		length = maxLen;
		string = new char[length + 1]; 
		string[maxLen]='\0';
		std::cout << "incorrect length" << std::endl;
	}
	else{
		length = len;
		string = new char[length + 1];
		string[0] = '\0';
	}
}

MyString::MyString(const char* str, const int len){
	if ( strlen(str) != len ){
		//std::cout << strlen(str) << std::endl;
		std::cout << "incorrect length" << std::endl;

	}
	length = strlen(str);
	string = new char[length + 1];
	strcpy(string, str);
}

MyString::MyString(const MyString &obj)
{
	length = obj.length;
	string = new char[length + 1];
	strcpy(string, obj.string);
}

MyString& MyString::operator=(const MyString& obj){
	if (this == &obj){ return *this; }
	delete[] string;
	length = obj.length;
	string = new char[length+1];
	strcpy(string, obj.string);
	return *this;
}

const int MyString::getLength() const {
	return length;
}

const char* MyString::getString() const {
	return string;
}

MyString MyString::operator+(const MyString& obj){
	MyString vStr;
	delete[] vStr.string;
	if (length + obj.length > maxLen) {
		std::cout << "maxlength > 100" << std::endl;
		vStr.string = new char[maxLen+1];
		strcpy(vStr.string, string);
		strncat(vStr.string, obj.string, maxLen - length);
		vStr.length = maxLen;
	}
	else {
		vStr.length = length + obj.length;
		vStr.string = new char[vStr.length +obj.length + 1];
		strcpy(vStr.string, string);
		strcat(vStr.string, obj.string);
	}
	return vStr;
}

MyString MyString::operator++(int n)
{
	if (length == 100) {
		std::cout << "no more length." << std::endl;
		return MyString();
	}
	MyString temp;
	delete[] temp.string;
	temp.length = length + 1;
	temp.string = new char[temp.length + 1];
	strcpy(temp.string, string);
	delete[] string;
	string = new char[temp.length + 1];
	strcpy(string, temp.string);
	return MyString();
}

MyString MyString::operator--(int n)
{
	length--;
	if (length < 0) {
		length = 0;
		std::cout << "no length." << std::endl;
		return MyString();
	}
	else {
		MyString temp;
		delete[] temp.string;
		temp.length = length;
		temp.string = new char[temp.length + 1];
		delete[] string;
		string = new char[length + 1];
		strncpy(string, temp.string, length);
		return MyString();
	}
}

char & MyString::operator[](const int index)
{
	if (index > 100 || index < 0) {
		std::cout << "error index " << std::endl;
		return string[0];
	}
	else {
		return string[index];
	}
	// TODO: insert return statement here
}

MyString MyString::operator()(const int x, const int y)
{
	if (x > length || x + y > maxLen) {
		std::cout << "error 1st char or length. " << std::endl;
		MyString temp;
		return temp;
	}
	else {
		MyString temp;
		delete[] temp.string;
		temp.length = y;
		temp.string = new char[temp.length + 1];
		for (int i = 0; i < y; ++i) {
			temp.string[i] = string[x + i-1];
		}
		temp.string[y] = '\0';
		return temp;
	}
}

MyString::operator char*() const
{
	char* str = string;
	return str;
}

MyString MyString::operator*(MyString obj)
{
	//std::cout << (*this).string << std::endl;
	//std::cout << obj.string << std::endl;
	MyString temp;
	delete[] temp.string;
	temp.length = length;
	temp.string = new char[temp.length + 1];
	int f = 0;
	for (int i = 0; i < length; ++i) {
		for (int j = 0; j < obj.length; ++j) {
			if (string[i] == obj.string[j]) {
				temp.string[f] = string[i]; f++;
				obj.string[j] = '\0';
				for (int k=j+1; k<obj.length; ++k) {
					if (string[i] == obj.string[k])
						obj.string[k] = '\0';
				}
			}
		}
	}
	temp.string[f] = '\0';
	return temp;
}

MyString::MyString(MyString && other)
{
	// pilfer other’s resource
	length = other.length;
	string = other.string;
	// reset other
	other.length = 0;
	other.string = nullptr;
}

MyString & MyString::operator=(MyString && other)
{
	if (this != &other)
	{
		// release the current object’s resources
		delete[] string;
		length = 0;
		// pilfer other’s resource
		length = other.length;
		string = other.string;
		// reset other
		other.length = 0;
		other.string = nullptr;
	}
	return *this;
	// TODO: insert return statement here
}

MyString operator+(const char * str, const MyString & obj)
{
	
	MyString vStr;
	
	delete[] vStr.string;
	
	if (strlen(str) + obj.length > vStr.maxLen) {
		std::cout << "maxlength > 100" << std::endl;
		vStr.string = new char[vStr.maxLen + 1];
		strcpy(vStr.string, str);
		strncat(vStr.string, obj.string, vStr.maxLen - strlen(str));
		vStr.length = vStr.maxLen;
	}
	else {
		vStr.length = strlen(str) + obj.length;
		vStr.string = new char[vStr.length + 1];
		strcpy(vStr.string, str);
		strcat(vStr.string, obj.string);
	}
	return vStr;
}

bool operator==(const MyString & a, const MyString & b)
{
	if (strcmp(a.string, b.string)) {
		return false;
	}
	else
		return true;
}

bool operator!=(const MyString & a, const MyString & b)
{
	if (strcmp(a.string, b.string)) {
		return true;
	}else
		return false;
}

std::ostream & operator<<(std::ostream &os, const MyString &obj)
{
	os << obj.string;
	// TODO: insert return statement here
	return os;
	// TODO: insert return statement here
}

std::istream & operator >> (std::istream &is, MyString &obj)
{
	std::cout << "Enter the string: " << std::endl;
	is >> obj.string;
	// TODO: insert return statement here
	return is;
}
