#pragma once

//field.h

#define		CONIOEX
#include	"common.h"

#define		FIELD_MAX	(200)//����A�V��Ȃǂ̌����


//�v���g�^�C�v�錾
void	InitField();
void	FinalizeField();
void	UpdateField();
void	DrawField();

void	CreateField(float x, float y, float w, float h);
OBJECT* GetField();

