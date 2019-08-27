// ConsoleApplication18.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include "String.h"
int main()
{
	String vS1;
	String vS2(6) ;
	String vS3("Home");
    String vS4(vS3);

	vS1.getString();
	vS2.getString();
	vS3.getString();
	vS4.getString();

	vS4.setString();
	vS4.getString();
	
	system("pause");
    return 0;
}

