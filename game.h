#pragma once

//game.h

#ifndef GAME_H 
#define GAME_H


#define CONIOEX
#include  "common.h"

extern std::chrono::duration<double> elapsedTime;


//プロトタイプ宣言
void	InitGame();
void	FinalizeGame();
void	UpdateGame();
void	DrawGame();

#endif // GAME_H