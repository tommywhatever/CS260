#ifndef _INVENTORY_H
#define _INVENTORY_H
#include "item.h"
class inventory
{
public:
	inventory();
	inventory(double weight);
	~inventory();

	bool AddItem(const item& item);
	bool RemoveItem(char *name);
	void PrintInventory() const;

	bool chkWeight(const item& item);
	double getWeight() const;
	int getCount() const;

private:
	struct node
	{
		item item;
		int count;
		node *next;
	};

	node *head;
	
	const int MAX_WEIGHT;
	int size;
	double weight;
};
#endif