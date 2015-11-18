#define MAX_CHILDREN 3 
#pragma warning(disable:4996)
#include <iostream>
#include <cstring>

class Skill {
public:
	Skill();
	Skill(char *aName, char *aDesc, int aLevel, Skill *aParent);
	Skill(const Skill &aSkill);

	~Skill();

	void SetName(char *aName);
	void SetDesc(char *aDesc);
	void SetLevel(int level);

	void SetParent(Skill *aParent);
	void SetChild(int index, Skill *child);

	char *GetName();
	char *GetDesc();
	int GetLevel();

	Skill *GetParent();
	Skill *GetChild(int index);

	void Display(std::ostream &obj);

	int GetHeight();

	bool ChildIsOpen();

	const Skill &operator=(const Skill &aSkill);
	friend std::ostream& operator<<(std::ostream& obj, const Skill &aSkill);

private:
	char *name;
	char *desc;
	int level;
	Skill *parent;
	Skill **children;
};