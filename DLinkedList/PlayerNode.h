#ifndef PLAYERNODE_H
#define PLAYERNODE_H
#include <string>
#include <iostream>

using namespace std;


class PlayerNode {
public:
	string playerName;
	string playerAlias;
	PlayerNode *pNext;
	PlayerNode *pPrev;

	// PlayerNode Constructor
	PlayerNode(string pn, string pa) : playerName(pn), playerAlias(pa), pNext(NULL), pPrev(NULL) { }

	void DisplayPlayer() {
		cout << "Player Name: " << playerName << endl;
		cout << "Player Alias: " << playerAlias << endl;
		cout << endl;
	}

};

#endif