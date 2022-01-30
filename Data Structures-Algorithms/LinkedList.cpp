#include "LinkedList.h"
#include <iostream>
using namespace std;


LinkedList::LinkedList()
{
	head = NULL;
}

bool LinkedList::IsEmpty()
{
	return (head == NULL);
}

void LinkedList::InsertFirst(int value)
{
	Node* newNode = new Node();
	newNode->data = value;
	if (IsEmpty()) {
		newNode->next = NULL;
		head = newNode;
	}

	else {
		newNode->next = head;
		head = newNode;
	}
}

void LinkedList::InsertBefor(int item, int newItem)
{
	if (head->data == item)
		cout << "This item is First Are You Stupid" << endl;
	if (IsEmpty()) {
		InsertFirst(newItem);
		return;

	}
	if (!IsFound(item)) {
		cout << "This item not Found" << endl;
		return;
	}

	Node* temp = head;
	Node* newNode = new Node();
	newNode->data = newItem;
	while (temp != NULL && temp->next->data != item) {
		temp = temp->next;
	}
	newNode->next = temp->next;
	temp->next = newNode;
}

void LinkedList::Append(int item)
{
	if (IsEmpty()) {
		InsertFirst(item);
		return;
	}
	Node* temp = head;
	Node* newNode = new Node();
	while (temp->next != NULL)
	{
		temp = temp->next;
	}
	newNode->data = item;
	temp->next = newNode;
	newNode->next = NULL;

}

void LinkedList::Display()
{
	Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << "\t";
		temp = temp->next;
	}
	cout << endl;
}

int LinkedList::Count()
{
	Node* temp = head;
	int count = 0;
	while (temp != NULL) {
		count++;
		temp = temp->next;
	}
	return count;
}

bool LinkedList::IsFound(int key)
{
	Node* temp = head;
	while (temp != NULL) {
		if (temp->data == key) {
			return true;
			break;
		}
		temp = temp->next;

	}
	return false;
}

void LinkedList::Delete(int item)
{
	if (IsEmpty())
	{
		cout << "This List Is Empty" << endl;
		return;
	}
	Node* delPtr = head;
	Node* prev = NULL;
	if (head->data == item) {
		delPtr = head;
		head = head->next;
		delete delPtr;
		return;
	}
	while (delPtr->data != item) {
		prev = delPtr;
		delPtr = delPtr->next;
	}
	prev->next = delPtr->next;
	delete delPtr;

}