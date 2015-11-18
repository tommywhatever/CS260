#include "SkillTree.h"

//Constructors
SkillTree::SkillTree()
{
	name = nullptr;
	root = new Skill;
}
SkillTree::SkillTree(char *aName)
{
	int length = strlen(aName);
	name = new char[length + 1];
	strcpy(name, aName);
	root = new Skill;
}
SkillTree::SkillTree(const SkillTree &aTree)
{
	int length = strlen(aTree.name);
	name = new char[length + 1];
	strcpy(name, aTree.name);
	root = aTree.root;
}

//Destructor
SkillTree::~SkillTree()
{
	delete[] name;
	delete root;
}

//Add skill functions
void SkillTree::AddSkill(char *skillName, char *desc, int level)
{
	if (root->GetName() == nullptr) {
		root->SetName(skillName);
		root->SetDesc(desc);
		root->SetLevel(level);
	}
	else {
		Skill *newRoot = new Skill(skillName, desc, level, nullptr);
		root->SetParent(newRoot);
		newRoot->SetChild(0, root);
		root = newRoot;
	}
}
bool SkillTree::AddSkill(char *skillName, char *desc, int level, char *parentName)
{
	Skill *parent = FindSkill(parentName);
	if (parent != nullptr) {
		if (parent->ChildIsOpen()) {
			Skill *newSkill = new Skill(skillName, desc, level, parent);
			for (int i = 0; i < MAX_CHILDREN; i++) {
				if (parent->GetChild(i) == nullptr) {
					parent->SetChild(i, newSkill);
					return true;
				}
			}
		}
	}
	return false;
}

//Find skill function, returns nullptr if not found
Skill *SkillTree::FindSkill(char *name)
{
	Skill *match = nullptr;
	Skill **matchPtr = &match;
	FindRoot(name, root, matchPtr);
	return match;
}

void SkillTree::FindRoot(char *name, Skill *node, Skill **matchPtr)
{
	if (strcmp(node->GetName(), name) == 0) {
		*matchPtr = node;
	}
	else {
		for (int i = 0; i < MAX_CHILDREN; i++) {
			if (node->GetChild(i) != nullptr) {
				FindRoot(name, node->GetChild(i), matchPtr);
				if (*matchPtr != nullptr)
					return;
			}
		}
	}
}

//Display functions
void SkillTree::Display(std::ostream &obj)
{
	obj << "Skill Tree: " << name << std::endl;
	Skill *traverse(root);
	if (traverse->GetName() == nullptr)
		obj << "  Empty" << std::endl;
	else
		DisplayRoot(obj, root);
}
void SkillTree::DisplayRoot(std::ostream &obj, Skill *root)
{
	for (int i = 0; i <= root->GetHeight(); i++)
		obj << "  ";
	obj << "- ";
	obj << *root;
	obj << std::endl;
	for (int i = 0; i < MAX_CHILDREN; i++) {
		if (root->GetChild(i) != nullptr) {
			DisplayRoot(obj, root->GetChild(i));
		}
	}
}

//Get name and root functions
char *SkillTree::GetName()
{
	return name;
}
Skill *SkillTree::GetRoot()
{
	return root;
}

//Overloaded operator
const SkillTree &SkillTree::operator=(const SkillTree &aTree)
{
	if (this == &aTree) {
		return *this;
	}
	else {
		delete[] name;
		delete root;

		int length = strlen(aTree.name);
		name = new char[length + 1];
		strcpy(name, aTree.name);

		root = new Skill;
		root = aTree.root;
	}
	return *this;
}