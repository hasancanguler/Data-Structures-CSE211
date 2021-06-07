#ifndef MYGRAPH_H
#define MYGRAPH_H
#include <iostream>
#include "intSLList.h"
#include <fstream>
#include <string>
#include <stack>
#include <list>
using namespace std;
class MyGraph {
private:
	bool error;
	IntSLList** listoflist;
	int arraysize;
	int* CheckList;
	void TurnDefault(void) {
		for (int i = 0; i < arraysize + 1; i++) {
			CheckList[i] = -1;
		}
	}
public:
	MyGraph(string filename) {

		ifstream file;
		file.open(filename.c_str());
		file >> arraysize;
		if (file.is_open() == false) {
			cout << "Couldn't open the file" << endl;
			error = true;
			return;
		}
		error = false;
		CheckList = new int[arraysize + 1];
		TurnDefault();
		listoflist = new IntSLList * [arraysize];
		for (int i = 0; i < arraysize; i++) {
			listoflist[i] = new IntSLList;
		}


		int from, to;
		int i = 0;
		while (file.eof() == false) {
			file >> from;
			file >> to;


			listoflist[from - 1]->addToTail(to);
		}
	}
	~MyGraph() {
		if (error == true) return;
		for (int i = 0; i < arraysize; i++) {
			delete listoflist[i];

		}
		delete[] listoflist;
		delete[] CheckList;
	}
	void print() {
		for (int i = 0; i < arraysize; i++) {
			cout << "Adjacencies of " << i + 1 << "= ";
			listoflist[i]->printAll();
		}
	}

	void convert_adj_matrix()
	{
		for (int index = 0; index < arraysize; index++)
		{
			for (int index2 = 0; index2 < arraysize; index2++)
			{
				bool test = listoflist[index]->isInList(index2 + 1);
				if (test)
					cout << " 1 ";
				else
					cout << " 0 ";
			}
			cout << "\n";
		}
	}

	void add_edges(int from, int to)
	{
		bool isIn = listoflist[from - 1]->isInList(to);
		if (!isIn)
		{
			listoflist[from - 1]->addToTail(to);
		}
	}

	list<int> visited;
	void DFS(int starting_index)	{		visited.push_back(starting_index - 1);		cout << starting_index << "\n";		if (!listoflist[starting_index - 1]->isEmpty())
		{
			for (int index = 1; index < listoflist[starting_index - 1]->GetSize(); index++)
			{
				//visited kontrolü eklenecek
				int parent = listoflist[starting_index - 1]->GetAt(index);				if (parent != 0)					DFS(parent);				else					return;
			}			
		}			}
};

#endif
