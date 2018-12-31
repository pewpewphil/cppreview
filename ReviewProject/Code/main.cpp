//#pragma comment(lib, "winmm.lib")

#include "Headers/BaseClass.h"
#include "Headers/math.h"
#include "FmodInc/fmod.h"
#include "FmodInc/fmod.hpp";
#include "FmodInc/common.h";
#include "FmodInc/fmod_errors.h";

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

const char *Common_MediaPath(const char *fileName)
{
	char *filePath = (char *)calloc(256, sizeof(char));

	strcat_s(filePath,256, "media/");
	strcat_s(filePath,256, fileName);
	cout << "output=" << filePath << "\n";
	return filePath;
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



int main()
{
	TestMathClass();
	//TestStrings();
	//TestDervived();
	//PlaySoundOld();
	
	FMOD::System     *system;
	FMOD::Sound      *sound1, *sound2, *sound3;
	FMOD::Channel    *channel = 0;
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata = 0;
	static unsigned int inputButton = 0;
	static unsigned int ExitPress = 27;

	/*
		Create a System object and initialize
	*/
	result = FMOD::System_Create(&system);

	result = system->getVersion(&version);
	cout << "result is "<< FMOD_ErrorString(result)<<"\n";
	//ERRCHECK(result);

	if (version < FMOD_VERSION)
	{
		printf("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	cout << "result is "<< FMOD_ErrorString(result) << "\n";


	result = system->createSound(Common_MediaPath("drumloop.wav"), FMOD_DEFAULT, 0, &sound1);
	//Common_MediaPath("drumloop.wav");
	cout << "result is "<< FMOD_ErrorString(result) << "\n";

	//result = sound1->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
           /* so turn it off here.  We could have also just put FMOD_LOOP_OFF in the above CreateSound call. */

	do
	{
		int channelsplaying = 0;
		if (inputButton == 1)
		{
			result = system->playSound(sound1, 0, false, &channel);
			cout << "result is " << FMOD_ErrorString(result) << "\n";
		}

			
		if (channel)
		{
			system->getChannelsPlaying(&channelsplaying, NULL);
		}

		cin >> inputButton;
		system->update();
		Sleep(10);
	} while (inputButton != 2);
	
	result = sound1->release();
	//system("pause");
	return 0; 
}