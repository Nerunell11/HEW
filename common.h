#pragma once

//このファイルは基本的に全てのプログラムにインクルードする

//conioex関連で出てくる警告を無視する
#pragma warning(disable:4311)
#pragma warning(disable:4312)
#pragma warning(disable:4302)


#include "conioex.h"//グレーゾーンな特殊機能を追加
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>


#include	"key.h"	//キー入力処理
#include    "sound.h"
//#include	"collision.h"


//ゲームシーンの定義
enum GAMESCENE
{
	SCENE_NONE = 0,		//なにもなし
	SCENE_TITLE,		//タイトル画面
	SCENE_GAME,			//ゲーム
	SCENE_RESULT,		//リザルト


	SCENE_MAX			//一番最後のデ―タ(シーンの個数)
};




//マクロ定義
// 
//画面の端を表す座標を定義 値は適当
#define	SCREEN_LIMIT_UP		(1)
#define	SCREEN_LIMIT_DOWN	(24)
#define	SCREEN_LIMIT_LEFT	(1)
#define	SCREEN_LIMIT_RIGHT	(80)

//ワールドの端を表す座標を定義
#define WORLD_LIMIT_UP		(1)
#define WORLD_LIMIT_DOWN	(102)
#define WORLD_LIMIT_LEFT	(1)
#define WORLD_LIMIT_RIGHT	(80)



//構造体定義
struct OBJECT
{
	bool	Use;						//使用中フラグ
	int		Mode;						//キャラクターの状態 静止　歩く　ジャンプ

	float	PositionX, PositionY;		//表示座標
	float	PositionXOld, PositionYOld;	//前回の表示座標
	float	VelocityX, VelocityY;		//移動方向

	float	AccelerationX, AccelerationY;	//加速度

	float		Width;	//幅
	float		Height;	//高さ

	float		AnimationCounter;
	float		AnimationTimer;
	//キャラクターの向きを表す変数を追加

};


//プロトタイプ宣言

//シーンの切り替え
void	SetScene(GAMESCENE scene);
//シーンの取得
GAMESCENE GetScene();


