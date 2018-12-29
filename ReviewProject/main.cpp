#include <iostream>
#include <string>
#include <vector> 
#include "BaseClass.h"
using namespace std;

int main()
{
	//cout << " hello world "; 

	//declaration
	vector<string> Strings;

	Strings.push_back("hello world");
	Strings.push_back("civilization");
	Strings.push_back("lets go eat lunch");

	for (int i = 0; i < Strings.size(); i++)
	{
		int size = Strings[i].size();
		cout << Strings[i]<< " has a size of  " << size<< endl;
	}

	Base *b = new Derived1();
	delete b;


	Base aClass = Derived1();
	aClass.~Base();

	return 0; 
}