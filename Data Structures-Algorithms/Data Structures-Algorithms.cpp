#include <iostream>
#include "LinkedList.h"
using namespace std;


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

