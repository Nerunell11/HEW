#pragma once

//camera.h

#define		CONIOEX	//<<<<<<<<<main.cpp以外でcommon.hの上に書いておく
#include	"common.h"	

//カメラの初期位置
#define 	CAMERA_START_POSX	(12)
#define 	CAMERA_START_POSY	(WORLD_LIMIT_DOWN-12)//縦描画範囲は24

//プロトタイプ宣言
void	InitCamera();
void	FinalizeCamera();
void	UpdateCamera();



