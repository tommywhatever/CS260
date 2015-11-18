#include "HashTable.h"
#include "Player.h"
#include <iostream>

using namespace std;

class PlayerDB
{
public:
	PlayerDB();
	PlayerDB(ostream& out);

	bool AddPlayer(const Player &aPlayer);
	bool RemovePlayer(const char* const name);
	Player* FetchPlayer(const char* const name);

	void PrintDiagnostics();

private:
	HashTable myDB;
	ostream* myOut;
};