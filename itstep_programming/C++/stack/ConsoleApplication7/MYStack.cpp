#include "stdafx.h"
#include "MYStack.h"
MYStack::MYStack()
{
	top = 0;
}



void MYStack::push(const Item & item)
{
		items[top++] = item;
}

bool MYStack::pull(Item & item)
{
	if (top > 0)
	{
		item = items[--top];
		return true;
	}
	else
		return false;
}
MYStack::~MYStack(){
}
