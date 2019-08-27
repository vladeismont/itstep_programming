#pragma once
class String
{
private:
	int length_;
	char* pStr_;
public:
	String();
	String(int len);
	String(const char* vChar);
	String(const String& vString);
	void getString()const;
	void setString();
	~String();
};

