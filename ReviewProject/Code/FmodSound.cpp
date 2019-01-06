#include "Headers/FmodSound.h"
using namespace std;

FmodSound::FmodSound()
{

	/*
		Create a System object and initialize
	*/

	result = FMOD::System_Create(&system);

	result = system->getVersion(&version);
	cout << "result is " << FMOD_ErrorString(result) << "\n";
	//ERRCHECK(result);

	if (version < FMOD_VERSION)
	{
		printf("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	cout << "result is " << FMOD_ErrorString(result) << "\n";


	if (Debug)
		cout << "FmodSound Initialize Called";
}

FmodSound::FmodSound(bool inputDebug)
{
	Debug = inputDebug;
	/*
		Create a System object and initialize
	*/
	result = FMOD::System_Create(&system);

	result = system->getVersion(&version);
	if (Debug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";
	//ERRCHECK(result);

	if (version < FMOD_VERSION)
	{
		printf("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	if (Debug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";


	if (Debug)
		cout << "FmodSound Initialize Called";
}

void FmodSound::LoadSound()
{
	result = system->createSound(Common_MediaPath("drumloop.wav"), FMOD_DEFAULT, 0, &sound1);
	//Common_MediaPath("drumloop.wav");
	//result = sound1->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
		   /* so turn it off here.  We could have also just put FMOD_LOOP_OFF in the above CreateSound call. */

	if (Debug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";
}

void FmodSound::PlayLoadedSound(int SoundNumber)
{
	FMOD::Sound *PlayingSound = sound1;
	switch (SoundNumber)
	{
	case 1:
		PlayingSound = sound1;
		break;
	case 2:
		PlayingSound = sound2;
		break;
	default:
		break;
	}

	result = system->playSound(PlayingSound, 0, false, &channel);
	if (Debug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";
}

void FmodSound::Update()
{
	system->update();
}

FmodSound::~FmodSound() {
	result = sound1->release();
	if (Debug)
		cout << "FmodSound Destructor called\n";
}

const char *Common_MediaPath(const char *fileName)
{
	char *filePath = (char *)calloc(256, sizeof(char));

	strcat_s(filePath, 256, "media/");
	strcat_s(filePath, 256, fileName);
	cout << "output=" << filePath << "\n";
	return filePath;
}