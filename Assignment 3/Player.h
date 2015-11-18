#ifndef PLAYER_H
#define PLAYER_H
#pragma warning(disable:4996)
#include <iostream>

using namespace std;

enum gender { MALE, FEMALE, UNKNOWN };

class Player
{
public:
	Player();
	Player(char* aName, gender aGender);

	Player(const Player& aPlayer);

	~Player();

	void LevelUp();
	void setName(char* aName);
	void setGender(gender aGender);

	char *getName() const;
	gender getGender() const;
	int getLevel() const;

	const Player& operator=(const Player& aPlayer);
	friend ostream& operator<<(ostream& out, const Player& aPlayer);

private:

	char *playerName;
	int playerLevel;
	gender playerGender;

	void setLevel(int level);
};

#endif