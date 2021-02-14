//Jacob Poteet

#pragma once
#include <iostream>
#include <unordered_set>

#ifndef HEADERFILE_H
#define HEADERFILE_H

using namespace std;

struct Node {
	int data = 0;
	Node* next;
};

class LinkedList {

public:
	LinkedList() {head = NULL;}
	~LinkedList();

	//Returns if the list is empty
	bool IsEmpty() {return head == NULL;}

	//Inserts a new node at an index
	//Returns pointer to new node
	Node* InsertNode(int index, int x);
	
	//Returns index of node with given value, if no node with the value is found, 0 is returned
	int FindNode(int x);

	//deletes node with a value of x and returns the position of the deleted node
	int DeleteNode(int x);

	//Print all nodes in the list
	void DisplayList();

	//returns the size of the linked list
	int GetSize();

	void PushBack(int x);

	void RemoveDuplicateEntries();

	Node* GetHeadNode() {return head;}

	//list l2 is added to the end of h1 without chaning h2. The new nodes in the target are not linked to L2. 
	void ConcatenateList(LinkedList* l2);

	int GetMaxElem();


//private:

	Node* head;


};


//keep command prompt active
void PauseCommandPrompt() { system("pause"); };


//debug print
void PrintString(string message);

/*-----------------------------------*/

#endif