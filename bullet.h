#pragma once

//bullet.h

#define		CONIOEX
#include	"common.h"

//弾の最大数
#define		BULLET_MAX	(10)

//弾のスピード
#define		BULLET_SPEED	(0.4f)


//プロトタイプ宣言
void	InitBullet();
void	FinalizeBullet();
void	UpdateBullet();
void	DrawBullet();

//弾作成関数
void	CreateBullet(float x, float y, float dx, float dy);
//弾構造体取得
OBJECT* GetBullet();

