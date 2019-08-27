#pragma once
// MYStack.h -- class definition for the MYStack ADT
#ifndef MYStack_H_
#define MYStack_H_

typedef int Item;

class MYStack
{
private:
	enum { MAX = 11 };    // constant specific to class
	Item items[MAX];    // holds MYStack items
	int top;            // index for top MYStack item
public:
	MYStack();
	void push(const Item & item);   // add item to MYStack
	bool pull(Item & item);          // pull top into item
	~MYStack();
};
#endif
