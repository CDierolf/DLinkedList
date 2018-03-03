#include <iostream>
#include <string>

using namespace std;
// PLAYERNODE CLASS
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
// END PLAYERNODE CLASS
//////////////////////////////
// PLAYERLIST CLASS
class PlayerList {
protected:
	PlayerNode* pHead;			// Pointer to the head of the list
	PlayerNode* pTail;			// Pointer to the tail of the list

public:
	// PlayerList Constructor
	PlayerList() : pHead(NULL), pTail(NULL) { }

	// PlayerList Deconstructor
	~PlayerList() {
		PlayerNode* currNode = pHead; // Begin at the head
		while (currNode != NULL)
		{
			PlayerNode *previous = currNode; // Save the current node to previous
			currNode = currNode->pNext;		 // Advance currNode forward from previous
			delete previous;				 // Delete previous
		}
	}
	// IsEmpty() --- Return true if the list is empty
	bool IsEmpty() {
		return pHead == NULL;
	}
	// DisplayForward() -- Display the list from head to tail
	void DisplayForward()
	{
		PlayerNode* currNode = pHead;									// Start at the head
		while (currNode != NULL)
		{
			currNode->DisplayPlayer();									// Display the player
			currNode = currNode->pNext;									// Advance currNode
		}
	}
	// DisplayReverse() -- Display the list from tail to head
	void DisplayReverse()
	{
		PlayerNode *currNode = pTail;									// Start at the tail
		while (currNode != NULL)
		{
			currNode->DisplayPlayer();									// Display the player
			currNode = currNode->pPrev;									// Move currNode bakcwards
		}
		cout << endl;
	}
	// DisplayFirst() -- Display the first player in the list
	void DisplayFirst()
	{
		pHead->DisplayPlayer();
	}
	// DisplayLast() -- Display the last palyer in the list
	void DisplayLast()
	{
		pTail->DisplayPlayer();
	}
	void InsertBeginning(string pn, string pa)
	{
		PlayerNode *pNewPlayer = new PlayerNode(pn, pa);				// Create a new player

		if (IsEmpty())
		{
			pTail = pNewPlayer;											// If the list is empty start new list
		}
		else
		{
			pHead->pPrev = pNewPlayer;									// Place new player at beg of list
			pNewPlayer->pNext = pHead;									// Advance the head
		}
		pHead = pNewPlayer;												// Newest PlayerNode is the head
	}
	void InsertEnd(string pn, string pa)
	{
		PlayerNode *pNewPlayer = new PlayerNode(pn, pa);

		if (IsEmpty())
		{
			pHead = pNewPlayer;
		}
		else
		{
			pTail->pNext = pNewPlayer;									// Place new player at end of list
			pNewPlayer->pPrev = pTail;									// Advance the tail
		}
		pTail = pNewPlayer;												// Newest PlayerNode is the tail
	}
	void DeleteLast()
	{
		PlayerNode *temp = pTail;
		if (IsEmpty())
		{
			cout << "The list is empty. Nothing to delete";
			return;
		}

		else if (pHead->pNext == NULL)									// Only one player exists
		{
			pHead = NULL;												// Make the only node point nowhere
		}
		else
		{
			pTail->pPrev->pNext = NULL;									// Decouple the old tail
			pTail = pTail->pPrev;										// Make next to last node the new tail
			delete temp;												// Delete the old tail
		}
	}
	void DeleteFirst()
	{
		PlayerNode *temp = pHead;
		if (IsEmpty())
		{
			cout << "The list is empty. Nothing to delete";
			return;
		}
		else if (pHead->pNext == NULL)									// Only one player exists
		{
			pHead = NULL;												// Make the only node point nowhere
		}
		else
		{
			pHead->pPrev = NULL;										// Decouple the old head
			pHead = pHead->pNext;										// Make the next node the new head
			delete temp;												// Delete the old head
		}


		
	}
};
// END PLAYERLIST CLASS
///////////////////////////////////////////////////////
// BEGIN MAIN
// Function Prototypes
void SelectionHandler(int);
bool ValidateSelection(int, int, int);
void DisplayMenu();

PlayerList pl;
int main()
{

	// Construct a list for demonstration
	cout << "Creating player list: \n";
	cout << "----------------------\n";
	cout << "Inserting players:....\n";
	pl.InsertBeginning("Christopher Dierolf", "pis7ftw");
	pl.InsertBeginning("Preston Uberpants", "moderngeek");
	pl.InsertBeginning("Bill Haynes", "hooah!!!!");
	cout << ".....players inserted.\n";
	cout << "----------------------\n\n";
	
	DisplayMenu();


	return 0;
}
// END MAIN
/////////////////////////////////////////////////////////
// MAIN FUNCTIONS
void SelectionHandler(int s)
{
	if (s == 1)
	{
		pl.DisplayForward();
	}
	else if (s == 2)
	{
		pl.DisplayReverse();
	}
	else if (s == 3 || s == 4)
	{
		string playerName, playerAlias;
		cout << "Player Name: ";
		cin.ignore();
		getline(cin, playerName);
		cout << "Player Alias: ";
		getline(cin, playerAlias);
		if (s == 3)
		{
			pl.InsertBeginning(playerName, playerAlias);
			cout << "Player: " << playerName << "\\" << playerAlias << " added at the beginning of the list...\n\n";
		}
		else if (s == 4)
		{
			pl.InsertEnd(playerName, playerAlias);
			cout << "Player: " << playerName << "\\" << playerAlias << " added at the end of the list...\n\n";
		}
	}
	else if (s == 5)
	{
		cout << "\nRemoving the first player: \n\n";
		pl.DisplayFirst();
		pl.DeleteFirst();
		cout << ".....removed.\n";
	}
	else if (s == 6)
	{
		cout << "\nRemoving the last player: \n\n";
		pl.DisplayLast();
		pl.DeleteLast();
		cout << ".....removed.\n";
	}
	return;
}
bool ValidateSelection(int selection, int upper, int lower)
{
	if (selection > upper || selection < lower)
	{
		return true;
	}
	else
	{
		return false;
	}
}
void DisplayMenu() {
	int selection;
	do {
		cout << "\n----------------------------------------------------------------------\n";
		cout << "Choose a selection from the following menu to modify the player list: \n";
		cout << "\t 1. Display the list...\n";
		cout << "\t 2. Display the list in reverse...\n";
		cout << "\t 3. Insert a new player at the beginning of the list...\n";
		cout << "\t 4. Insert a new player at the end of the list...\n";
		cout << "\t 5. Remove the last player in the list...\n";
		cout << "\t 6. Remove the first player in the list...\n";
		cout << "\t 0. Exit...\n";
		cout << "\nSelection: ";
		cin >> selection;
		if (ValidateSelection(selection, 6, 0))
		{
			cout << "Invalid selection. Enter a valid option (0-6): ";
			cin >> selection;
		}
		SelectionHandler(selection);
	} while (selection != 0);

}