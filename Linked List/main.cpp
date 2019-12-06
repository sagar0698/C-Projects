#include <iostream>
#include <string>
#include "IntegerLinkedList.h"

using namespace std;

int main() {
	IntegerLinkedList mylist;
	cout << "Enter number of integers : ";
	int n, value;
	cin >> n;
	cout << "Enter " << n << " integers" << endl;
	for (int i = 0; i < n; i++) {
		cin >> value;
		mylist.addFront(value);
	}

	mylist.print();

	cout << "Enter position of integer to find : ";
	cin >> n;
	cout << "Integer at position entered is: " << mylist.getInteger(n) << endl;
	cout << "The largest value in the list is: " << mylist.MaxList() << endl;  //part 3

	system("pause"); // comment/uncomment if needed
