#pragma once
#include "FmodInc/fmod.h"
#include "FmodInc/fmod.hpp";
#include "FmodInc/fmod_errors.h";
#include "FmodSound.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class FmodSound
{
public:
	// variables 
	FMOD::System     *system;
	FMOD::Sound      *sound1, *sound2, *sound3;
	FMOD::Channel    *channel = 0;
	FMOD::Channel    *channel2 = 0;
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata = 0;
	std::vector<FMOD::Sound*>    LoadedSoundsVector;
	std::vector<FMOD::Channel*>    LoadedChannelVector;

	// class 
	FmodSound();
	FmodSound(bool debug);

	void LoadSound(string SoundName);
	void PlayLoadedSound(int number);
	int ReturnIncrease(int number);
	void PauseSound(int number);
	
	void Update();

	bool usingDebug = false;

	~FmodSound();
};

const char *Common_MediaPath(const char *fileName);