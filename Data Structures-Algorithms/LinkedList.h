#pragma once
#include "Node.h"
class LinkedList
{
public:
	Node* head;

	LinkedList();

	bool IsEmpty();

	void InsertFirst(int value);

	void InsertBefor(int item, int newItem);

	void Append(int item);

	void Display();

	int Count();

	bool IsFound(int key);

	void Delete(int item);
};

