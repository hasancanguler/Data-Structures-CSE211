#include<iostream>
#include "LList.h"

using namespace std;

class MyStack {
	const int maxSize = 100;
public:
	MyStack() {
		size = 0;		
	}
	bool Push(char);
	bool Pop();
	char Top() ;
	bool IsEmpty();
private:
	int size;	
	LList items;
};

bool MyStack::Push(char item)
{
	if (size >= maxSize - 1)
		return false;
	else
	{
		size++;
		items.addToHead(item);
		return true;
	}
}

bool MyStack::Pop()
{
	if (size ==0)
		return false;
	else
	{
		size--;
		items.deleteFromHead();
		return true;
	}
}

char MyStack::Top()
{
	return items.getFirst();	
}

bool MyStack::IsEmpty()
{
	if (size == 0)
		return true;
	else
		return false;
}

