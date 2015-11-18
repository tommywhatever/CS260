#ifndef STACK_H
#define STACK_H
#include "Potion.h"

class Stack
{
public:
	Stack(int capacity);	
	Stack(const Stack& aStack);

	~Stack();

	bool push(const Potion& aPotion);
	bool pop(Potion& aPotion);

	bool peek(Potion& aPotion) const;
	bool isEmpty(void) const;
	bool isFull(void) const;

	const Stack& operator=(const Stack& aStack);
	friend ostream& operator<<(ostream& out, Stack& aStack);

private:
	Potion*	items;
	int		MAX_CAPACITY;
	int		top;
	
};

#endif