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

}

