
//key.cpp

#include "key.h"
/*
PPK_UP = 0,
PPK_DOWN,
PPK_LEFT,
PPK_RIGHT,
PPK_ENTER,
PPK_Z,
PPK_X,
PPK_A,
PPK_S,
PPK_D,
*/

//キー処理構造体の作成＆初期化
KEYINFO	   KeyAssign[] =  //enumの定義の順番と同じにすること
{
	{PK_UP, 0,0,0,0,0,0},		//上
	{PK_DOWN, 0,0,0,0,0,0},		//下
	{PK_LEFT, 0,0,0,0,0,0},		//左
	{PK_RIGHT, 0,0,0,0,0,0},	//右
	{PK_ENTER, 0,0,0,0,0,0},	//エンター
	{PK_Z, 0,0,0,0,0,0},			//Z
	{PK_X, 0,0,0,0,0,0},			//X
	{PK_A, 0,0,0,0,0,0},			//A
	{PK_S, 0,0,0,0,0,0},			//S
	{PK_D, 0,0,0,0,0,0},			//D


	{-1, 0,0,0,0,0,0}			//配列の最後を表すダミー情報

};

//キー構造体の初期化
void	InitKey()
{
	int		i = 0;
	while (KeyAssign[i].Key != -1)//キーの種類が-1(ダミーデータ)でなければループ
	{
		KeyAssign[i].Press = 0;
		KeyAssign[i].Release = 0;
		KeyAssign[i].Trigger = 0;

		KeyAssign[i].PressOld = 0;
		KeyAssign[i].ReleaseOld = 0;
		KeyAssign[i].TriggerOld = 0;
		i++;
	};

}

//現在のキー情報を作成
void	UpdateKey()
{
	int		i = 0;
	while (KeyAssign[i].Key != -1)
	{
		//プレス入力を取得（現在のキーの状態）
		KeyAssign[i].Press = inport(KeyAssign[i].Key);
		//トリガー入力を作成
		KeyAssign[i].Trigger = (KeyAssign[i].PressOld ^ KeyAssign[i].Press) & (KeyAssign[i].Press);
		//リリース入力を作成
		KeyAssign[i].Release = (KeyAssign[i].PressOld ^ KeyAssign[i].Press) & (~KeyAssign[i].Press);

		KeyAssign[i].PressOld = KeyAssign[i].Press;	//現在の状態を保存
		i++;
	};

}

//指定のキーの現在の状態を調べる true=押している　　false=押していない
bool	IsKeyPress(int key)
{
	return (KeyAssign[key].Press == 1);
}

//指定のキーのトリガー入力を調べる true=押している　　false=押していない
bool	IsKeyTrigger(int key)
{
	return (KeyAssign[key].Trigger == 1);
}

//指定のキーのリリース入力を調べる true=押している　　false=押していない
bool	IsKeyRelease(int key)
{
	return (KeyAssign[key].Release == 1);
}







