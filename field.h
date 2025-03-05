#pragma once

//field.h

#define		CONIOEX
#include	"common.h"

#define		FIELD_MAX	(400)//足場、天井などの個数上限

extern OBJECT field[FIELD_MAX];

//プロトタイプ宣言
void	InitField();
void	FinalizeField();
void	UpdateField();

void	CreateField(float x, float y, float w, float h);


