#pragma once

#define CONIOEX
#include "common.h"

#define ITEM_MAX (3)

//�v���g�^�C�v�錾
void	InitItem();
void	FinalizeItem();
void	UpdateItem();
void	DrawItem();

void	CreateItem(float x, float y);
OBJECT* GetItem();


