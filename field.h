#pragma once

//field.h

#define		CONIOEX
#include	"common.h"

#define		FIELD_MAX	(200)//足場、天井などの個数上限


//プロトタイプ宣言
void	InitField();
void	FinalizeField();
void	UpdateField();
void	DrawField();

void	CreateField(float x, float y, float w, float h);
OBJECT* GetField();

