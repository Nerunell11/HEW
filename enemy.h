#pragma once

#define		CONIOEX
#include	"common.h"


//敵の数

#define		ENEMY_MAX	(5)


//プロトタイプ宣言
void	InitEnemy();
void	FinalizeEnemy();
void	UpdateEnemy();
void	DrawEnemy();

OBJECT* GetEnemy();

