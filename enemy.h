#pragma once

#define		CONIOEX
#include	"common.h"


//�G�̐�

#define		ENEMY_MAX	(5)


//�v���g�^�C�v�錾
void	InitEnemy();
void	FinalizeEnemy();
void	UpdateEnemy();
void	DrawEnemy();

OBJECT* GetEnemy();

