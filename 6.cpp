// LinkedList.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

using namespace std;



struct ListNode {
	string item;
	ListNode* next;
};

class LinkedList
{
private:
	int size;
	ListNode* head;
public:
	LinkedList() {
		size = 0;
	}

	int Size()
	{
		return size;
	}

	ListNode* Find(int index)
	{
		//if (index < 1)
		//    return NULL;

		ListNode* cur = head;
		for (int skip = 1; skip < index; ++skip)
			cur = cur->next;
		return cur;
	}

	void Add(string text)
	{
		ListNode* newNode = new ListNode;
		size += 1;

		newNode->item = text;

		if (size == 1)
		{
			head = newNode;
		}
		else
		{
			ListNode* last = Find(size - 1);
			last->next = newNode;
		}
	}

	void Delete(int index)
	{
		ListNode* prev = Find(index-1);
		ListNode* deleteNode = prev->next;
				
		prev->next = deleteNode->next; 
		delete deleteNode;
		deleteNode = NULL;
		size--;
	}

	void Print()
	{
		ListNode* cur = head;
		for (int index = 1; index <= size; index++)
		{
			cout << index << " : " << cur->item;
			cout << ", pointer : " << cur->next;
			cout << "\n";
			cur = cur->next;
		}
	}
};

int main()
{
	LinkedList listTest;
	listTest.Add("eleman1");
	listTest.Add("eleman2");
	listTest.Add("eleman3");
	listTest.Add("eleman4");

	listTest.Delete(2);

	std::cout << "LinkedList\n";
	listTest.Print();



}
