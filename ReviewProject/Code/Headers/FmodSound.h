#pragma once
#include "FmodInc/fmod.h"
#include "FmodInc/fmod.hpp";
#include "FmodInc/fmod_errors.h";
#include "FmodSound.h"

#include <vector>
#include <iostream>
#include <string>

class FmodSound
{
public:
	// variables 
	FMOD::System     *system;
	FMOD::Sound      *sound1, *sound2, *sound3;
	FMOD::Channel    *channel = 0;
	FMOD_RESULT       result;
	unsigned int      version;
	void             *extradriverdata = 0;
	//vector<FMOD::Sound>    SoundsVector;

	// class 
	FmodSound();
	FmodSound(bool debug);

	void LoadSound();
	void PlayLoadedSound(int number);
	int ReturnIncrease(int number);
	
	void Update();

	bool Debug = false;

	~FmodSound();
};

const char *Common_MediaPath(const char *fileName);