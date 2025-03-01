#pragma once	//ヘッダーファイル二重定義の防止


#define		CONIOEX	//<<<<<<<<<main.cpp以外でcommon.hの上に書いておく
#include	"common.h"	


//プレイヤーのスタート位置
#define	PLAYER_START_POSX	(SCREEN_LIMIT_RIGHT  / 2)
#define PLAYER_START_POSY	(WORLD_LIMIT_DOWN - 1)

//プレイヤーの状態
enum PLAYERMODE
{
	PLAYER_IDLE = 0,	//静止状態（キー入力無し）
	PLAYER_MOVE,		//移動
	PLAYER_JUMP,		//ジャンプ（上昇）
	PLAYER_FALL,		//ジャンプ（下降）

};


//プロトタイプ宣言
void	InitPlayer();		//初期化
void	FinalizePlayer();	//終了処理
void	UpdatePlayer();		//更新処理
void	DrawPlayer();		//描画

void	PlayerCheck();		
void	PlayerMove();		//プレイヤーの移動

OBJECT* GetPlayer();		//プレイヤー構造体の取得

