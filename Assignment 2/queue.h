#ifndef QUEUE_H
#define QUEUE_H
#include "Potion.h"

class Queue
{
public:
	Queue(int a_size);
	Queue(const Queue& aQueue);

	~Queue();

	
	bool enqueue(const Potion& aPotion);
	bool dequeue(Potion& aPotion);

	bool peek(Potion& aPotion)const;
	bool isEmpty(void)const;

	const Queue& operator= (const Queue& aQueue);
	friend ostream& operator<<(ostream& out, Queue& aQueue);

private:
	Potion	*items;
	int		MAX_CAPACITY;
	int		front;
	int		rear;
	int		size;
};

#endif