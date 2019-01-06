//#pragma comment(lib, "winmm.lib")

#include "Headers/BaseClass.h"
#include "Headers/math.h"
#include "FmodInc/fmod.h"
#include "FmodInc/fmod.hpp";
#include "FmodInc/common.h";
#include "FmodInc/fmod_errors.h";
#include "Headers/FmodSound.h";

#include <iostream>
#include <string>
#include <vector> 
#include <windows.h>

using namespace std;

static unsigned int gPressedButtons = 0;

void TestMathClass()
{
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
}

void TestStrings()
{

	//declaration
	vector<string> Strings;

	Strings.push_back("hello world");
	Strings.push_back("civilization");
	Strings.push_back("lets go eat lunch");

	for (int i = 0; i < Strings.size(); i++)
	{
		int size = Strings[i].size();
		cout << Strings[i] << " has a size of  " << size << endl;
	}
}

void TestDervived()
{
	Base *base = new Derived1();
	delete base;


	Base aClass = Derived1();
	aClass.~Base();
}

void PlaySoundOld()
{
	PlaySound(TEXT("Action_Dash.wav"), NULL, SND_FILENAME);
}

void pointerReview()
{

}



int main()
{
	TestMathClass();
	//TestStrings();
	//TestDervived();
	//PlaySoundOld();

	static unsigned int inputButton = 0;
	static unsigned int ExitPress = 27;

	FmodSound FSound = new FmodSound();
	FSound.LoadSound();
	
	do
	{
		int channelsplaying = 0;
		if (inputButton == 1)
		{
			FSound.PlayLoadedSound(1);
		}


		cin >> inputButton;
		FSound.Update();
		Sleep(10);
	} while (inputButton != 2);
	
	FSound.~FmodSound();
	system("pause");
	return 0; 
}