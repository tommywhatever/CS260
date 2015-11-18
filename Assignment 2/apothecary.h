#ifndef APOTHECARY_H
#define APOTHECARY_H
#include <iostream>
#include <stdlib.h>
#include "main.h"
#include "Queue.h"
#include "Stack.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

using namespace std;

class Apothecary
{
public:
	Apothecary(int order_size, int shelf_size);
	Apothecary(const Apothecary& anApothecary);

	~Apothecary();

	bool OrderPotion(PotionType potion);
	int MakePotions();
	bool BuyPotion(Potion& potion);

	const Apothecary& operator= (const Apothecary& anApothecary);

private:
	Queue *order;
	Stack *shelf;

};

#endif