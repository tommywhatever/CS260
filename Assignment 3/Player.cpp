#include "Player.h"
#include <stdlib.h>
#include <string.h>
#include <iostream>

//Constructors
Player::Player() : 
	playerName(NULL), 
	playerLevel(0), 
	playerGender(UNKNOWN)
{
}
Player::Player(char* aName, gender aGender) : 
	playerName(NULL), 
	playerLevel(0), 
	playerGender(UNKNOWN)
{
	setName(aName);
	setGender(aGender);
}
//Copy constructor: make current object a copy of "Player"
Player::Player(const Player& aPlayer) : 
	playerName(NULL), 
	playerLevel(0), 
	playerGender(UNKNOWN)
{
	setName(aPlayer.playerName);
	setGender(aPlayer.playerGender);
	setLevel(aPlayer.playerLevel);
}

//Destructor
Player::~Player()
{
	if (playerName)
		delete[] playerName;
}

void Player::LevelUp()
{
	this->playerLevel++;
}
void Player::setName(char* aName)
{
	if (this->playerName)
		delete[] this->playerName;

	this->playerName = new char[strlen(aName) + 1];
	strcpy(this->playerName, aName);
}
void Player::setGender(gender aGender)
{
	this->playerGender = aGender;
}

char *Player::getName() const
{
	return playerName;
}
gender Player::getGender() const
{
	return playerGender;
}
int Player::getLevel() const
{
	return playerLevel;
}

void Player::setLevel(int level)
{
	this->playerLevel = level;
}

//Overloaded operators
const Player& Player::operator=(const Player& aPlayer)
{
	if (this == &aPlayer)
		return *this;
	else
	{
		setName(aPlayer.playerName);
		setGender(aPlayer.playerGender);
		setLevel(aPlayer.playerLevel);
		return *this;
	}
}

ostream& operator<<(ostream& out, const Player& aPlayer)
{
	out << aPlayer.getName() << " [" << aPlayer.getLevel() << "]";

	return out;
}