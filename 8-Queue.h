#include "LList.h"

class MyQueue {
public:
	bool enqueue(char el);
	bool dequeue(char &el);
	bool getFront(char &el);
	bool isEmpty();
	int getSize();
private:
	int size = 0;
	LList items;
};

bool MyQueue::enqueue(char el) {
	bool result = items.addToTail(el);
	if (result == true)
		size++;
	return result;
}

bool MyQueue::dequeue(char &el) {
	el = items.getFirst();
	bool result = items.deleteFromHead();
	if (result == true)
		size--;
	return result;
}

bool MyQueue::getFront(char& el) {
	el = items.getFirst();	
	return true;
}

bool MyQueue::isEmpty() {
	if (size == 0)
		return true;
	else
		return false;
}

int MyQueue::getSize(){
	return size;
}

