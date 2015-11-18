#include "Queue.h"
#include <assert.h>

//Constructors
Queue::Queue(int a_size) : size(0), front(0), rear(0), MAX_CAPACITY(a_size), items(NULL)
{
	//Create an array of potions with the size passed to the constructor
	items = new Potion[a_size];
}
Queue::Queue(const Queue& aQueue)
{
	size = aQueue.size;
	front = aQueue.front;
	rear = aQueue.rear;
	MAX_CAPACITY = aQueue.MAX_CAPACITY;

	items = new Potion[MAX_CAPACITY];
	assert(items != NULL); 

	int itemsCopied, i;

	for (i = aQueue.front, itemsCopied = 0; itemsCopied < aQueue.size; i = (i + 1) % aQueue.MAX_CAPACITY, itemsCopied++)
	{
		items[i] = aQueue.items[i];
	}

}

//Destructors
Queue::~Queue()
{
	delete[] items;
}

//Enqueue and Dequeue functions for queue ADT
bool Queue::enqueue(const Potion& aPotion)
{
	if (size == MAX_CAPACITY)
		return false; 

	items[rear] = aPotion;
	rear = (rear + 1) % MAX_CAPACITY; 
	size++;
	return true;
}
bool Queue::dequeue(Potion& aPotion)
{
	if (isEmpty())
		return false;
	else
	{
		aPotion = items[front];
		front = (front + 1) % MAX_CAPACITY;
		size--;
		return true;
	}
}

//Peek and isEmpty function for queue ADT
bool Queue::peek(Potion& aPotion) const
{
	if (isEmpty())
		return false;

	else
	{
		aPotion = items[front];
		return true;
	}
}
bool Queue::isEmpty() const
{
	if (size == 0)
		return true;

	return false;
}

//Overloaded operators for use on data objects.
const Queue& Queue::operator= (const Queue& aQueue)
{
	if (this == &aQueue)
		return *this;

	else
	{
		delete[] items;

		size = aQueue.size;
		front = aQueue.front;
		rear = aQueue.rear;
		MAX_CAPACITY = aQueue.MAX_CAPACITY;

		items = new Potion[MAX_CAPACITY];
		assert(items != NULL);

		int itemsCopied;
		int i;
		for (i = aQueue.front, itemsCopied = 0;	itemsCopied < aQueue.size;	i = (i + 1) % aQueue.MAX_CAPACITY, itemsCopied++)
		{

			items[i] = aQueue.items[i];
		}

		return *this;
	}
}
ostream& operator<<(ostream& out, Queue& aQueue)
{
	int	i, nPrinted;

	out << "Data in the queue: " << endl << endl;
	for (i = aQueue.front, nPrinted = 0; nPrinted < aQueue.size; i = (i + 1) % aQueue.MAX_CAPACITY, nPrinted++)

		out << aQueue.items[i] << endl;

	return out;
}