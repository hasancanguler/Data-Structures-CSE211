#include <iostream>
#include "MyQueue.h"

using namespace std;

void printQueue(MyQueue &q) {
	char item;
	bool result;
	int size = q.getSize();
	for (int index = 0; index < size ; index++)
	{
		result = q.dequeue(item);
		cout << item;
		result = q.enqueue(item);
	}
}

void reverseQueue(MyQueue& q) {
	char item;
	bool result;
	int size = q.getSize();

	if (size != 1)
	{
		result = q.dequeue(item);
		reverseQueue(q);
		result = q.enqueue(item);
	}
}

int main() {

	string str = "hello world!";

	MyQueue q;

	char a;

	bool tmp = q.dequeue(a);

	cout << "Attempting to remove an element from an empty queue returns bool: " << tmp << endl;

	cout << "Attempting to remove an element from an empty queue returns el: " << a << endl;

	for (int var = 0; var < str.length(); var++) {
		q.enqueue(str[var]);
	}

	tmp = q.getFront(a);
	cout << "front:\t\t\t" << a;

	cout << "size:\t\t\t" << q.getSize();

	cout << "\nPrinting Queue:\t\t\t";
	printQueue(q);
	cout << "\nPrinting Queue Again:\t\t";
	printQueue(q);

	reverseQueue(q);
	cout << "\nPrinting Reverse Queue:\t\t";
	printQueue(q);


	return 0;
}
