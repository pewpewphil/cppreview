#include <iostream>
#include <string>
#include <vector> 
#include <Windows.h>
//#pragma comment(lib, "winmm.lib")

#include "Headers/BaseClass.h"
#include "Headers/math.h"


using namespace std;

int main()
{
	//cout << " hello world "; 
	MathClass MC;
	int test;
	cout << "Hello World! ";

	// a = 5(00000101), b = 9(00001001) 
	unsigned char a = 5, b = 9;
	int d = 1, e = 2;
	printf("d+e= %d\n", MC.addition(d, e));

	// The result is 00001010  
	printf("a<<1 = %d\n", a << 1);

	// The result is 00010010  
	printf("b<<1 = %d\n", b << 1);
	PlaySound(TEXT("Action_Dash.wav"), NULL, SND_FILENAME);
	test = cin.get();

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

	Base *base = new Derived1();
	delete base;


	Base aClass = Derived1();
	aClass.~Base();

	
	system("pause");
	return 0; 
}