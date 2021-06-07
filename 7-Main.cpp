#include <iostream>
#include <string>
#include "MyStack.h"

using namespace std;


void reverse_str(string& str)
{
	MyStack stackBuss;
	string newStr;
	int strLength = str.length();

	for (int index = 0; index < strLength; index++) {
		stackBuss.Push(str[index - 1, index]);		
	}
	str = "";
	for (int index = 0; index < strLength; index++) {
		char a = stackBuss.Top();
		str += a;
		stackBuss.Pop();
	}
}

bool is_reverse(string str1, string str2)
{
	reverse_str(str1);
	if (str1 == str2)
		return true;
	else
		return false;
}

int main() {

	string str = "hello world!";

	cout << "original str: " << str << endl;
	
	reverse_str(str);

	cout << "reverse str: " << str << endl;

	string str1 = "asdfghjkl";
	string str2 = "lkjhgfdsa";

	
	cout << "\n\nis_reverse:\n\tstr1: " << str1 << "\n\tstr2: " << str2
			<< "\nis " << ((is_reverse(str1, str2)) ? "True" : "False") << endl;
	

	return 0;
}


