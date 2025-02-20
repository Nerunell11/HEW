
// key.h
#pragma once

#define CONIOEX			//main.cpp以外でconioexを使う時は必ず#defineする
#include "conioex.h"

//このゲームで使うキーを設定する
enum
{
	PPK_UP = 0,
	PPK_DOWN,
	PPK_LEFT,
	PPK_RIGHT,
	PPK_ENTER,
	PPK_W,
	PPK_A,
	PPK_S,
	PPK_D,

	//必要な物は追加する

};

//キー情報構造体
struct KEYINFO
{
	int		Key;		//キーの種類
	int		Press;		//現在のキーの状態
	int		Trigger;	//トリガー入力
	int		Release;	//リリース入力

	int		PressOld;	//前回の状態
	int		TriggerOld;
	int		ReleaseOld;
};

//プロトタイプ宣言
void	InitKey();		//ゲームループに入る前に一回呼ぶ
void	UpdateKey();	//ゲームループ内で一回呼ぶ

//以下は必要な時に何回でも呼ぶ
bool	IsKeyPress(int key);	//keyのプレス入力を調べる
bool	IsKeyTrigger(int key);	//keyのトリガー入力を調べる
bool	IsKeyRelease(int key);	//keyのリリース入力を調べる








