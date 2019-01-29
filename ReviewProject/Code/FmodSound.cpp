#include "Headers/FmodSound.h"
using namespace std;

FmodSound::FmodSound()
{
	usingDebug = false;
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


	if (usingDebug)
		cout << "FmodSound Initialize Called and debug is "<< usingDebug << "\n";
}

FmodSound::FmodSound(bool inputDebug)
{
	usingDebug = inputDebug;
	/*
		Create a System object and initialize
	*/
	result = FMOD::System_Create(&system);

	result = system->getVersion(&version);
	if (usingDebug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";
	//ERRCHECK(result);

	if (version < FMOD_VERSION)
	{
		printf("FMOD lib version %08x doesn't match header version %08x", version, FMOD_VERSION);
	}

	result = system->init(32, FMOD_INIT_NORMAL, extradriverdata);
	if (usingDebug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";

	cout << "debug is " << usingDebug << "\n";
	if (usingDebug)
		cout << "FmodSound Initialize Called and debug is " << usingDebug <<" \n";
}

void FmodSound::LoadSound(string SoundName)
{
	const char * SoundConstantCh = SoundName.c_str();
	FMOD::Sound *AddingSound ;
	result = system->createSound(Common_MediaPath(SoundConstantCh), FMOD_DEFAULT, 0, &AddingSound);
	//Common_MediaPath("drumloop.wav");
	//result = sound1->setMode(FMOD_LOOP_OFF);    /* drumloop.wav has embedded loop points which automatically makes looping turn on, */
		   /* so turn it off here.  We could have also just put FMOD_LOOP_OFF in the above CreateSound call. */

	LoadedSoundsVector.push_back(AddingSound);

	if (usingDebug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";
}

void FmodSound::PlayLoadedSound(int SoundNumber)
{
	FMOD::Sound *PlayingSound = LoadedSoundsVector.at(SoundNumber);

	result = system->playSound(PlayingSound, 0, false, &channel);
	if (usingDebug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";
}

void FmodSound::PauseSound(int SoundNumber)
{
	FMOD::Sound *PlayingSound = LoadedSoundsVector.at(SoundNumber);

	result = system->playSound(PlayingSound, 0, true, &channel);
	if (usingDebug)
		cout << "result is " << FMOD_ErrorString(result) << "\n";
}

void FmodSound::Update()
{
	system->update();
}

FmodSound::~FmodSound() {
	result = sound1->release();
	if (usingDebug)
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