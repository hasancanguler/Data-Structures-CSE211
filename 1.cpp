/******************************************************************************
20190702104
Hasan Can Güler
26.02.2021 Lab1 - Exercise 1
*******************************************************************************/

#include <iostream>

using namespace std;

int main()
{
    int passed = 0;
    int failed = 0;
    int grade;
    cout<<"Enter Result";
    for (int index = 0; index < 10; index++) {
        cin>>grade;
        if(grade==1)
            passed+=1;
        else if(grade==2)
            failed+=1;
    }
    cout<<"\n Number of students who passed: "<<passed;
    cout<<"\n Number of students who failed: "<<failed;
    
    if(passed>8)
        cout<<"\n Raise tuition.";

    return 0;
}
