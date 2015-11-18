#include "Stack.h"
#include <fstream>
#include <assert.h>

//Constructor
Stack::Stack(int capacity) :MAX_CAPACITY(capacity), top(-1)
{
	items = new Potion[capacity];
}
Stack::Stack(const Stack& aStack)
{
	top = aStack.top;
	MAX_CAPACITY = aStack.MAX_CAPACITY;

	items = new Potion[MAX_CAPACITY];
	assert(items != NULL);

	int i;
	for (i = 0; i <= aStack.top; i++)
		items[i] = aStack.items[i];
}

//Destructor
Stack::~Stack()
{
	delete[] items;
}

//Push and Pop Functions for Stack ADT
bool Stack::push(const Potion& aPotion)
{
	if (top + 1 == MAX_CAPACITY)
	{
		return false;
	}

	top++;
	items[top] = aPotion;
	return true;
}
bool Stack::pop(Potion& aPotion)
{
	if (isEmpty())
		return false;
	else
	{
		aPotion = items[top];
		top--;
		return true;
	}
}

//Peek, isEmpty, and isFull functions for Stack ADT
bool Stack::peek(Potion& aPotion) const
{
	if (isEmpty())
		return false;
	else
	{
		aPotion = items[top];
		return true;
	}
}
bool Stack::isEmpty() const
{
	return top<0;
}
bool Stack::isFull() const
{
	return (top + 1 == MAX_CAPACITY);
}

//Overloaded operators for use on data objects
const Stack& Stack::operator=(const Stack& aStack)
{
	if (this == &aStack)
		return *this;
	else
	{
		delete[] items;

		MAX_CAPACITY = aStack.MAX_CAPACITY;
		items = new Potion[MAX_CAPACITY];
		top = aStack.top;

		int i;
		for (i = aStack.top; i >= 0; i--)
			items[i] = aStack.items[i];
		return *this;
	}
}
ostream& operator<<(ostream& out, Stack& aStack)
{
	int i;

	out << "Potion in the Stack: " << endl << endl;
	for (i = aStack.top; i >= 0; i--)
		out << '\t' << aStack.items[i] << endl;

	return out;
}