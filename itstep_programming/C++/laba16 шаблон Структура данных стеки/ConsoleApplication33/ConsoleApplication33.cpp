// ConsoleApplication33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
int main()
{
	setlocale(LC_ALL, "rus");
	Stack<char> stackSymbol(5);		//������ ����� ����� 10 ���������
	int ct = 0;
	char ch;
	if (stackSymbol.empty()) {
		std::cout << "���� ����" << std::endl;
	}
	while (ct++ < 5)
	{
		std::cin >> ch;
		stackSymbol.push(ch); // �������� �������� � ����
	}

	std::cout << std::endl;
	std::cout << "������ �����: " << stackSymbol.getTop() << std::endl;
	stackSymbol.printStack(); // ������ �����

	std::cout << "\n\n������ ������� �� �����\n";
	stackSymbol.pop();

	stackSymbol.printStack(); // ������ �����
	std::cout << "������ �����: " << stackSymbol.getTop() << std::endl;
	Stack<char> newStack(stackSymbol);

	std::cout << "\n\n�������� ����������� �����������!\n";
	newStack.printStack();
	
	std::cout << "������ � ������� �������: " << newStack.Peek(2) << std::endl;
	
	stackSymbol = newStack;
	stackSymbol.pop();
	stackSymbol.printStack();
	if (stackSymbol == stackSymbol) {
		std::cout << "==" << std::endl;
	}
	if (stackSymbol != newStack) {
		std::cout << "!=" << std::endl;
	}
	std::cout << stackSymbol[0] << std::endl;
	system("pause");
    return 0;
}

