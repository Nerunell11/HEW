
#include "sound.h"
#include  "conioex.h"

int SoundID = -1;
bool Repeat = false;

int  SeID[SE_MAX];
static char SEfile[][256] =
{ 
	"asset\\popcorn1.mp3",
	"asset\\popcorn1.mp3",
	"asset\\popcorn2.mp3",
	"asset\\popcorn2.mp3",
	"asset\\popcorn3.mp3",
	"asset\\popcorn3.mp3",
	"asset\\letsgo!.mp3",
	"asset\\letsgo!.mp3",
};

void  UpdateSound()
{
	if (SoundID != -1)
	{
		if (Repeat == true)
		{
			updatesound(SoundID);
		}
	}
}
int  StartSound(char* filename, bool repeat)
{
	if (SoundID != -1)
	{
		StopSound();
	}
	SoundID = opensound(filename);
	playsound(SoundID, repeat);

	return SoundID;
}
void StopSound()
{
	if (SoundID != -1)
	{
		stopsound(SoundID);
		closesound(SoundID);
		SoundID = -1;
	}
}


void  InitSE()
{
	for (int i = 0; i < SE_MAX; i++)
	{
		SeID[i] = -1;
	}
	for (int i = 0; i < SE_MAX; i++)
	{
		SeID[i] = opensound(&SEfile[i][0]);
		if (SeID[i] == 0)
		{
			SeID[i] = -1;
		}
		
	}
}

void FinalizeSE()
{

	for (int i = 0; i < SE_MAX; i++)
	{
		if (SeID[i] != -1)
		{
			stopsound(SeID[i]);
			closesound(SeID[i]);
			SeID[i] = -1;
		}
	}
}

void StartSE(int SeNo)
{
	if (SeID[SeNo] != -1)
	{
		playsound(SeID[SeNo], false);
	}

	return ;
}




