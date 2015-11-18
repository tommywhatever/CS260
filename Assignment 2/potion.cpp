#include <stdlib.h>
#include "main.h"
#include "Potion.h"
#pragma GCC diagnostic ignored "-Wwrite-strings"

//Constructor for Potion Class
Potion::Potion() : type(UNKNOWN)
{
}
Potion::Potion(PotionType type)
{
	SetType(type);
}
Potion::Potion(const Potion& aPotion)
{
	type = aPotion.type;
}

//GetType and SetType functions for Potion Class
PotionType Potion::GetType() const
{
	return type;
}
void Potion::SetType(PotionType type)
{
	this->type = type;
}

//Overloaded operators for use on data objects
const Potion& Potion::operator=(const Potion& aPotion)
{
	if (this == &aPotion)
		return *this;

	else
	{
		type = aPotion.type;
		return *this;
	}
}
ostream& operator<<(ostream& out, const Potion& aPotion)
{
	out << "Potion of " << PotionTypeString(aPotion.type) << endl;
	return out;
}