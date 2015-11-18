#include "inventory.h"
#include <stdlib.h>
#include <string.h>

using namespace std;

//CONSTRUCTORS

inventory::inventory() : MAX_WEIGHT(50), head(NULL), size(0), weight(0)
{}

inventory::inventory(double weight) : MAX_WEIGHT(weight), head(NULL), size(0), weight(0)
{}


//DESTRUCTOR

inventory::~inventory()
{
	node*curr = head;
	while (head)
	{
		curr = head->next;
		delete head;
		head = curr;
	}
}

/*
*	Function:AddItem
*	Input: const item& item
*	Description: Checks if item exists in inventory,adds the item if not, 
*	increases quantity if it does exist.
*/
bool inventory::AddItem(const item& item)
{
	node*prev = NULL;
	node *curr = head;

	if (!chkWeight(item))
		return false;

	while (curr != NULL && (curr->item < item))
	{
		prev = curr;
		curr = curr->next;
	}

	if (curr && curr->item == item)
	{
		curr->count++;
		size++;
		return false;
	}

	else
	{
		node * newItem = new node;
		newItem->item = item;
		newItem->next = NULL;
		newItem->count = 1;

		newItem->next = curr;
		if (prev == NULL)
			head = newItem;
		else
			prev->next = newItem;
		size++;
		return true;
	}
}

/*
*	Function:RemoveItem
*	Input: char* name
*	Description: Searches for name of the item and decreases quantity
*	if there is more than one, and removes from the inventory if there is
*	only one item.
*/

bool inventory::RemoveItem(char *name)
{
	node *prev = NULL;
	node *curr = head;

	while (curr)
	{
		if (strcmp(curr->item.getName(), name) == 0)
		{
			if (curr->count >= 1)
			{
				weight -= curr->item.getWeight();
				curr->count--;
				size--;
				
				if (curr->count == 0)
				{
					if (!prev)
						head = curr->next;
					else
						prev->next = curr->next;
					delete curr;
				}
				
				cout << "You dropped a " << name << "." << endl << endl;
				
				return true;

			}
			
			prev = curr;
			curr = curr->next;
			}
		cout << "You don't have a " << name << " in your inventory." << endl;
		return false;
		}
}

/*
*	Function:PrintInventory
*	Input: none
*	Description: Displays current inventory list.
*/

void inventory::PrintInventory() const
{
	node *curr = head;
	
	int total_count = getCount();
	double total_weight = getWeight();
	
	cout << "Current inventory:" << endl;
	if (!total_count)
	{
		cout << "\t(no items)" << endl << endl;
	}
	else
	{
		while (curr != NULL)
		{
			cout << "\t[" << curr->count << "] " << curr->item.getName()<< endl;
			curr = curr->next;
		}
		cout << "Total items: " << total_count << endl;
		cout << "Total weight: " << total_weight << endl << endl;
	}
}

/*
*	Function:chkWeight
*	Input: const item& item
*	Description: Adds the weight of &item and checks to see if the total weight exceeds
*	MAX_WEIGHT; displays message accordingly
*/

bool inventory::chkWeight(const item& item)
{

	double item_weight = item.getWeight();
	if ((item_weight + weight) > MAX_WEIGHT)
	{
		cout << "You're not strong enough to pick up the " << item.getName() << " with everything else you're carrying." << endl;
		return false;
	}
	else
	{
		cout << "You picked up a " << item.getName() << "." << endl << endl;
		weight += item_weight;
		return true;
	}
}


double inventory::getWeight() const
{
	return weight;
}

int inventory::getCount() const
{
	return size;
}