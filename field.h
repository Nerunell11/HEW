#pragma once

//field.h

#define		CONIOEX
#include	"common.h"

#define		FIELD_MAX	(400)//����A�V��Ȃǂ̌����

extern OBJECT field[FIELD_MAX];

//�v���g�^�C�v�錾
void	InitField();
void	FinalizeField();
void	UpdateField();

void	CreateField(float x, float y, float w, float h);


