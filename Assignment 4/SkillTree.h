#include <ostream>
#include <cstring>
#include "Skill.h"


class SkillTree {
public:
	SkillTree();
	SkillTree(char *aName);
	SkillTree(const SkillTree &aTree);

	~SkillTree();

	void AddSkill(char *skillName, char *desc, int level);
	bool AddSkill(char *skillName, char *desc, int level, char *parentName);

	Skill *FindSkill(char *name);
	void FindRoot(char *name, Skill *root, Skill **matchPtr);

	void Display(std::ostream &obj);
	void DisplayRoot(std::ostream &obj, Skill *root);

	char *GetName();
	Skill *GetRoot();

	const SkillTree &operator=(const SkillTree &aTree);

private:
	char *name;
	Skill *root;
};