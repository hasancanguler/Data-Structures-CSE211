/******************************************************************************
20190702104
Hasan Can Güler
26.02.2021 Lab1 - Exercise 2
*******************************************************************************/

#include <iostream>
#include <string>

using namespace std;

//I used Single Responsibility Principle
string reverse(string text)
{
    string reverseText="";
    for (int index = text.length(); index >0 ; index--) {
        reverseText+=text.substr(index-1, 1);
    }
    return reverseText;
}

bool isPalindrome(string text)
{
    string reverseText = reverse(text);
    if(text==reverseText)
        return true;
    else
        return false;
}

int main()
{
    string text;
    cout<<"Write a string, please : ";
    cin>>text;
    bool result = isPalindrome(text);
    if(result)
        cout<<"Given string is palindrome";
    else
        cout<<"Given string is not palindrome";
        
    return 0;
}


