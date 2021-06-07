#include<iostream>
#include "MyGraphEx.h"
#include <string>


using namespace std;

int main(void){
    string filename;
    int element;
    cout << "Enter filename " << endl;
    getline(cin,filename);
	MyGraph Gr(filename);

    Gr.add_edges(1, 2);
    /*Gr.add_edges(1, 3);
    Gr.add_edges(6, 3);
    Gr.add_edges(6, 4);
    Gr.add_edges(6, 5);
    Gr.add_edges(7, 7);*/

    Gr.DFS(1);

	Gr.print();  
    cout << "\n";
    Gr.convert_adj_matrix();
    
}
