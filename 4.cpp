#include <iostream>

using namespace std;

int const gameSize = 7;

int FindMinValueOfArray(int pancakes[])
{
    int minValue =0;
    int minIndex =0;
    
    minValue = pancakes[0];
    for(int index=0;index<gameSize;index++)
    {
        if(minValue>pancakes[index])
        {
            minValue=pancakes[index];
            minIndex = index;
        }
    }
    return minIndex;
}

void CompareSameNumber(int pancakes[])
{
    for(int index=0;index<gameSize;index++)
    {
        for(int jindex=index;gameSize<index;jindex++)
        {
            //if(pancakes)
        }
    }
}

int main()
{
    
    string names[gameSize] = {"Mert", "Onur", "Ali", "Hasan","Can","Güler","Ahmet"};
    int pancakes[gameSize];
    
    cout<<"Enter the pancake count that eaten by ..., please : \n";
    //Input Values
    for(int index=0;index<gameSize;index++)
    {
        cout<<names[index]<<" :";
        cin>>pancakes[index];
    }
    
    //a - to identify the person who ate the most and the person who ate the least    
    int minIndex = FindMinValueOfArray(pancakes);
    cout<<"\n The person who ate the least : " << names[minIndex];
    
    //b - to compare any two people based on the number of pancakes they ate 
    
    return 0;
}
