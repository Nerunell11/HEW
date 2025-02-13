#pragma once	//ヘッダーファイル二重定義の防止


#define		CONIOEX	//<<<<<<<<<main.cpp以外でcommon.hの上に書いておく
#include	"common.h"	


//プレイヤーの移動量
#define	PLAYER_SPEED_X		(0.2f)
#define	PLAYER_SPEED_Y		(PLAYER_SPEED_X / 2.0f)//縦は横の半分のスピード
//プレイヤーのスタート位置
#define	PLAYER_START_POSX	(SCREEN_LIMIT_RIGHT  / 2)
#define PLAYER_START_POSY	(SCREEN_LIMIT_DOWN - 1)
//落下加速度
#define	PLAYER_GRAVITY		(9.8f / 350.0f)	//値はいい感じに調整
#define	PLAYER_JUMP_SPEED	(PLAYER_SPEED_Y * 5.0f)
#define	PLAYER_BRAKE		(0.9f)		//移動速度の減衰


//プレイヤーの状態
enum PLAYERMODE
{
	PLAYER_IDLE = 0,	//静止状態（キー入力無し）
	PLAYER_WALK,		//歩き
	PLAYER_JUMP,		//ジャンプ（上昇）
	PLAYER_FALL,		//ジャンプ（下降）

};


//プロトタイプ宣言
void	InitPlayer();		//初期化
void	FinalizePlayer();	//終了処理
void	UpdatePlayer();		//更新処理
void	DrawPlayer();		//描画

void	PlayerIdle();		//静止状態
void	PlayerWalk();		//歩き
void	PlayerJump();		//ジャンプ（上昇）
void	PlayerFall();		//ジャンプ（下降）

OBJECT* GetPlayer();		//プレイヤー構造体の取得

