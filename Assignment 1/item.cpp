#include "item.h"
#include <iostream>
#include <iomanip>
#include <string.h>
#pragma warning(disable:4996) //Allows call to strcpy
using namespace std;

//CONSTRUCTORS

item::item() :name(NULL), weight(0)
{
}

item::item(char* name, double weight) :
name(NULL),
weight(weight)
{
	setName(name);
}

item::item(const item& item) :
name(NULL)
{
	setName(item.name);
	setWeight(item.weight);
}

//DESTRUCTOR

item::~item()
{
	if (name)
		delete[] name; 
}

/*
*	Function:getName
*	Input: char* name
*	Description: Access to item name, one with variable declaration and one 
*	where it isn't necessary.
*/

void item::getName(char* name) const
{
	strcpy(name, this->name);
}

char *item::getName() const
{
	return this->name;
}

double item::getWeight() const
{
return this->weight;
}

const item& item::operator=(const item& item)
{
	if (this == &item)
		return *this;
	else
	{
		setName(item.name);
		setWeight(item.weight);
		return *this;
	}
	
}

void item::setName(char* name)
{
	if (this->name)
		delete[] this->name;

	this->name = new char[strlen(name) + 1];
	strcpy(this->name,name);

}

void item::setWeight(double weight)
{
	this->weight = weight;
}


ostream& operator<<(ostream& out, const item& item)
{
	out << item.name << setw(10) << item.weight;
	return out;
}

bool operator<(const item& item1, const item& item2)
{
	char name1[100];
	char name2[100];

	item1.getName(name1);
	item2.getName(name2);

	if (strcmp(name1, name2) < 0)
		return true;
	else
		return false;

}

bool operator==(const item& item1, const item& item2)
{
	char name1[100];
	char name2[100];

	item1.getName(name1);
	item2.getName(name2);

	if (strcmp(name1, name2) == 0)
		return true;
	else
		return false;
}

