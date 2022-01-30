#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
	Node(int value) {
		data = value;
		next = NULL;
	}
	Node() {
		next = NULL;
	}
};

class LinkedList {
public:

	Node* head;

	LinkedList() {
		head = NULL;
	}

	bool IsEmpty() {
		return (head == NULL);
	}
	void InsertFirst(int value) {
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

	void InsertBefor(int item, int newItem) {
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

	void Append(int item) {
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

	void Display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp = temp->next;
		}
		cout << endl;
	}
	int Count() {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			count++;
			temp = temp->next;
		}
		return count;
	}
	bool IsFound(int key) {
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
	void Delete(int item) {
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
};


int main()
{
	LinkedList list;
	if (list.IsEmpty())
		cout << "is Empty" << endl;
	else
		cout << list.Count() << endl;
	int item;
	cout << "please enter your item" << endl;
	cin >> item;
	list.InsertFirst(item);
	list.Display();
	cout << list.Count() << endl;

	cout << "please enter your item" << endl;
	cin >> item;
	list.InsertFirst(item);
	list.Display();
	cout << list.Count() << endl;

	cout << "please enter your item" << endl;
	cin >> item;
	list.InsertFirst(item);
	list.Display();
	cout << list.Count() << endl;

	int searchItem;
	cout << "pleas enter your search value" << endl;
	cin >> searchItem;
	if (list.IsFound(searchItem))
		cout << "Item Is Found" << endl;
	else
		cout << "Item Is Not Found" << endl;

	int newItem;
	cout << "Please Enter old and new items" << endl;
	cin >> item;
	cin >> newItem;
	list.InsertBefor(item, newItem);
	list.Display();

	cout << "Please Enter Append Item" << endl;
	cin >> item;
	list.Append(item);
	list.Display();
	cout << "Please Enter Delete Item" << endl;
	cin >> item;
	list.Delete(item);
	list.Display();
}

