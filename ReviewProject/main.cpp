#include <iostream>
#include <string>
#include <vector> 
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



	return 0; 
}