// ConsoleApplication33.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include <iostream>
int main()
{
	setlocale(LC_ALL, "rus");
	Stack<char> stackSymbol(5);		//размер стека равен 10 элементам
	int ct = 0;
	char ch;
	if (stackSymbol.empty()) {
		std::cout << "стек пуст" << std::endl;
	}
	while (ct++ < 5)
	{
		std::cin >> ch;
		stackSymbol.push(ch); // помещаем элементы в стек
	}

	std::cout << std::endl;
	std::cout << "размер стека: " << stackSymbol.getTop() << std::endl;
	stackSymbol.printStack(); // печать стека

	std::cout << "\n\nУдалим элемент из стека\n";
	stackSymbol.pop();

	stackSymbol.printStack(); // печать стека
	std::cout << "размер стека: " << stackSymbol.getTop() << std::endl;
	Stack<char> newStack(stackSymbol);

	std::cout << "\n\nСработал конструктор копирования!\n";
	newStack.printStack();
	
	std::cout << "Второй в очереди элемент: " << newStack.Peek(2) << std::endl;
	
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

