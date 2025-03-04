#pragma once

//camera.h

#define		CONIOEX	//<<<<<<<<<main.cpp以外でcommon.hの上に書いておく
#include	"common.h"	
#include	"Player.h"

//カメラの初期位置
#define 	CAMERA_START_POSX	(WORLD_LIMIT_UP)
#define 	CAMERA_START_POSY	(WORLD_LIMIT_DOWN-24) // 縦描画範囲は24

//カメラの幅と高さ
#define CAMERA_WIDTH  (80)
#define CAMERA_HEIGHT (24)

enum CAMERAMODE
{
	CAMERA_IDLE = 0,	//静止状態（キー入力無し）
	CAMERA_MOVE,		//移動
	CAMERA_JUMP,		//ジャンプ（上昇）
	CAMERA_FALL,		//ジャンプ（下降）
};

//プロトタイプ宣言
void	InitCamera();
void	FinalizeCamera();
void	UpdateCamera();

void	CameraCheck();
void	CameraMove();
OBJECT* GetCamera();

