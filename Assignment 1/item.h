/* Item Class for Lab1 */
#ifndef _ITEM_H
#define _ITEM_H
#include <iostream>
using namespace std;

class item
{
public:
	item();
	item(char* name, double weight);
	item(const item& item);
	~item();

	void getName(char* name) const;
	char *getName() const;
	double getWeight() const;

	void setName(char* name);
	void setWeight(double weight);

	const item& operator=(const item& item);
	friend ostream& operator <<(ostream& out, const item& item);


private:
	char* name;
	double weight;
};

bool operator< (const item& item1, const item& item2);
bool operator== (const item& item1, const item& item2);

#endif