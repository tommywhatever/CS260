#include "Skill.h"

//Constructors
Skill::Skill()
{
	name = nullptr;
	desc = nullptr;
	level = 0;
	parent = nullptr;
	children = new Skill*[MAX_CHILDREN];
	for (int i = 0; i < MAX_CHILDREN; i++)
		children[i] = nullptr;
}
Skill::Skill(char *aName, char *aDesc, int aLevel, Skill *aParent)
{
	parent = aParent;

	int nameLen = strlen(aName);
	name = new char[nameLen + 1];
	strcpy(name, aName);

	int descLen = strlen(aDesc);
	desc = new char[descLen + 1];
	strcpy(desc, aDesc);

	level = aLevel;

	children = new Skill*[MAX_CHILDREN];
	for (int i = 0; i < MAX_CHILDREN; i++)
		children[i] = nullptr;
}
Skill::Skill(const Skill &aSkill)
{
	parent = aSkill.parent;

	int nameLen = strlen(aSkill.name);
	name = new char[nameLen + 1];
	strcpy(name, aSkill.name);

	int descLen = strlen(aSkill.desc);
	desc = new char[descLen + 1];
	strcpy(desc, aSkill.desc);

	level = aSkill.level;

	children = new Skill*[MAX_CHILDREN];
	for (int i = 0; i < MAX_CHILDREN; i++)
		children[i] = aSkill.children[i];
}

//Destructor
Skill::~Skill()
{
	delete[] name;
	delete[] desc;
	for (int i = 0; i < MAX_CHILDREN; i++) {
		delete children[i];
		children[i] = nullptr;
	}
	delete[] children;
}

//Set functions for name, desc, and level
void Skill::SetName(char *aName)
{
	int length = strlen(aName);
	name = new char[length + 1];
	strcpy(name, aName);
}
void Skill::SetDesc(char *aDesc)
{
	int length = strlen(aDesc);
	desc = new char[length + 1];
	strcpy(desc, aDesc);
}
void Skill::SetLevel(int aLevel)
{
	level = aLevel;
}

//Set functions for parent and child nodes
void Skill::SetParent(Skill *aParent)
{
	parent = aParent;
}
void Skill::SetChild(int index, Skill *child)
{
	children[index] = child;
}

//Get functions for name, desc, and level
char *Skill::GetName()
{
	return name;
}
char *Skill::GetDesc()
{
	return desc;
}
int Skill::GetLevel()
{
	return level;
}

//Get functions for parent and child nodes
Skill *Skill::GetParent()
{
	return parent;
}
Skill *Skill::GetChild(int index)
{
	return children[index];
}

//Display skill function
void Skill::Display(std::ostream &aSkill)
{
	aSkill << name;
	aSkill << " -- " << desc;
	aSkill << " [Lvl: " << level;
	aSkill << "]";
}

//GetHeight function for display functions
int Skill::GetHeight()
{
	int height = 0;
	Skill *traverse(parent);
	while (traverse != nullptr) {
		height++;
		traverse = traverse->parent;
	}
	return height;
}

//Checks if node can have another child
bool Skill::ChildIsOpen()
{
	for (int i = 0; i < MAX_CHILDREN; i++) {
		if (children[i] == nullptr)
			return true;
	}
	return false;
}

//Overloaded Operators
const Skill &Skill::operator=(const Skill &aSkill)
{
	if (this == &aSkill) {
		return *this;
	}
	else {
		delete[] name;
		delete[] desc;
		for (int i = 0; i < MAX_CHILDREN; i++) {
			delete children[i];
			children[i] = nullptr;
		}
		delete[] children;

		int length = strlen(aSkill.name);
		name = new char[length + 1];
		strcpy(name, aSkill.name);

		length = strlen(aSkill.desc);
		desc = new char[length + 1];
		strcpy(name, aSkill.desc);

		level = aSkill.level;

		children = new Skill*[MAX_CHILDREN];
		for (int i = 0; i < MAX_CHILDREN; i++)
			children[i] = nullptr;
	}
	return *this;
}
std::ostream &operator<<(std::ostream &obj, const Skill &aSkill)
{
	obj << aSkill.name;
	obj << " -- " << aSkill.desc;
	obj << " [Lvl: " << aSkill.level;
	obj << "]";
	return obj;
}

