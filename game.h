#pragma once

//game.h

#ifndef GAME_H 
#define GAME_H


#define CONIOEX
#include  "common.h"

extern std::chrono::duration<double> elapsedTime;


//�v���g�^�C�v�錾
void	InitGame();
void	FinalizeGame();
void	UpdateGame();
void	DrawGame();

#endif // GAME_H