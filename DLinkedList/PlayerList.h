#ifndef PLAYERLIST_H
#define PLAYERLIST_H
#include <iostream>
#include <string>
#include "PlayerNode.h"
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
			cout << "The list is empty. Nothing to delete.\n";			// List is empty
		}
		if (pHead->pNext == NULL)										// Only one player exists
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
			cout << "The list is empty. Nothing to delete.\n";			// List is empty
		}
		if (pHead->pNext == NULL)										// Only one player exists
		{
			pHead = NULL;												// Make the only node point nowhere
		}
		else
		{
			pHead->pPrev->pNext = NULL;									// Decouple the old head
			pHead = pHead->pNext;										// Make the next node the new head
			delete temp;												// Delete the old head
		}
	}
};

#endif