#include "Apothecary.h"
#include "main.h"
#include <assert.h>

//Constructor for Apothecary
Apothecary::Apothecary(int order_size, int shelf_size)
{
	order = new Queue(order_size);
	shelf = new Stack(shelf_size);
}
Apothecary::Apothecary(const Apothecary& anApothecary)
{
	order = anApothecary.order;
	shelf = anApothecary.shelf;
}

//Destructor for Apothecary
Apothecary::~Apothecary()
{
	delete order;
	delete shelf;
}

//Order, Make, and Buy Functions for Aporthecary
bool Apothecary::OrderPotion(PotionType potion)
{
	Potion aPotion(potion);
	return order->enqueue(aPotion);
}
int Apothecary::MakePotions()
{
	int i;
	Potion potion;
	for (i = 0; !order->isEmpty(); i++)
	{
		if (shelf->isFull() == true) //Check if shelf is full.
		{
			cout << "The shelf of potions is full.  You can't make any more until somebody buys some.";
			break;
		}
		else
		{
			order->dequeue(potion);	//Dequeue item
			shelf->push(potion);	//Add to shelf
			cout << "Made a " << PotionTypeString(potion.GetType()) << " potion." << endl;
		}
	}

	return i;
}
bool Apothecary::BuyPotion(Potion& potion)
{
	return shelf->pop(potion);
}

//Overloaded operator for use on data objects
const Apothecary& Apothecary::operator= (const Apothecary& anApothecary)
{
	if (this == &anApothecary)
		return *this;

	else
	{
		order = anApothecary.order;
		shelf = anApothecary.shelf;
		return *this;
	}
}
