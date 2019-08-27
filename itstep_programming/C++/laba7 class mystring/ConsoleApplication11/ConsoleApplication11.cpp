// ConsoleApplication11.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"


#include "MyString.h"

void f(MyString str){
	std::cout << "Copy constructor: PASS" << std::endl;
}

int main(int argc, char* argv[])
{
	MyString s1;
	MyString s2("a");
	MyString s3(5);
	MyString s4(198);
	MyString s5("abacaba", 7);
	MyString s6("abacaba", 12);
	MyString s7("abacaba", -1);
	MyString s8 = s2;	//copy constructor

	s8 = s7;	//operator=
	s8 = s8;
	
	f(s8);

	MyString s9 = s2 + s6;
	MyString s10 = "asdf" + s6;
	MyString s11 = s2 + MyString("laksjdhfl;kajs;cvlkjz;xlkcbjv;zlxjc;blkjzxlckvj;zlkxjc;vlkzjxlckvj;zlkxj;cvlkjz;xkclas;dlkjlkjlfkdgjls;dkvfjb;lksjdv;lbkj;sdlvkbj;lskdjv;blksjd;lvbkj;sldkvjb;lksdjvb;lkjs;dlvbkj");
	
	MyString s12("abldepjhikabldepjhikabldepjhikabldepjhikabldepjhikabldepjhikabldepjhikabldepjhikabldepjhikabldepjasdfs");
	s12++;
	s12++;
	MyString s13("ab");
	s13--;
	s13--;
	s13--;

	std::cout << "s1.getLength(): " << s1.getLength() << std::endl;
	std::cout << "s5.getLength(): " << s5.getLength() << std::endl;
	std::cout << "s6.getLength(): " << s6.getLength() << std::endl;
	std::cout << "s9.getLength(): " << s6.getLength() << std::endl;
	std::cout << "s10.getLength(): " << s6.getLength() << std::endl;
	std::cout << "s11.getLength(): " << s6.getLength() << std::endl;
	std::cout << "s12.getLength(): " << s12.getLength() << std::endl;
	std::cout << "s13.getLength(): " << s13.getLength() << std::endl;

	std::cout << "s1.getString(): " << s1.getString() << std::endl;
	std::cout << "s2.getString(): " << s2.getString() << std::endl;
	std::cout << "s8.getString(): " << s8.getString() << std::endl;
	
	std::cout << "s3 == s4: " << (s3 == s4) << std::endl;
	std::cout << "s5 == s6: " << (s5 == s6) << std::endl;
	std::cout << "s3 != s5: " << (s3 != s5) << std::endl;
	std::cout << "s2 != s8: " << (s2 != s8) << std::endl;


	
	std::cout << "char=  " << s12[1111] << std::endl;
	s13 = s12(1, 5);
	std::cout << "string:" << s13.getString() << std::endl;
	char* ch = s11;
	std::cout << "string:" << ch << std::endl;
	std::cin >> s13;

	MyString s15("ab nabf^");
	MyString s16("aqqqabq q^");
	std::cout << "string:" << s15 << std::endl;
	std::cout << "string:" << s16 << std::endl;

	std::cout << "string:" << s15*s16 << std::endl;
	
	system("pause");
	return 0;
}
