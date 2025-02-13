#pragma once



#define CONIOEX
#include  "conioex.h"

void  UpdateSound();
int  StartSound(char* filename, bool repeat);
void StopSound();


void  InitSE();
void  FinalizeSE();
void StartSE(int SeNo);

enum SENO
{
	SE_ID00 = 0,
	SE_ID01,


	SE_MAX
};

