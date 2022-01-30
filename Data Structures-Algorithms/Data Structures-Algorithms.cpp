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
		Node* newNode = NULL;
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
	void Display() {
		Node* temp = head;
		while (temp != NULL) {
			cout << temp->data << "\t";
			temp->next;
		}
	}
	int Count() {
		Node* temp = head;
		int count = 0;
		while (temp != NULL) {
			count++;
			temp->next;
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

	cout << "please enter your item" << endl;
	cin >> item;
	list.InsertFirst(item);
	list.Display();

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

}

