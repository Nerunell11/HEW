
#include	"collision.h"
#include	"Player.h"
#include	"bullet.h"


OBJECT		Player;				//プレイヤー構造体

void	InitPlayer()		//初期化
{

	//プレイヤーの初期化
	Player.PositionX = PLAYER_START_POSX;	//適当な値
	Player.PositionY = PLAYER_START_POSY;
	Player.PositionXOld = Player.PositionX;
	Player.PositionYOld = Player.PositionY;
	Player.VelocityX = 0;	//適当な値
	Player.VelocityY = 0;

	Player.AccelerationX = 0.0f;
	Player.AccelerationY = 0.0f;
	Player.Mode = PLAYER_IDLE;
	Player.Use = true;

	Player.Width = 0.8f;
	Player.Height = 0.8f;

}
void	FinalizePlayer()	//終了処理
{

}
void	UpdatePlayer()		//更新処理
{

	if (Player.Use == true)
	{	//プレイヤーの状態ごとの処理
		switch (Player.Mode)
		{
		case PLAYER_IDLE:
			PlayerIdle(); 
			break;
		case PLAYER_WALK:
			PlayerWalk();
			break;
		case PLAYER_JUMP:
			PlayerJump();
			break;
		case PLAYER_FALL:
			PlayerFall();
			break;
		}
	}

	//画面外チェック
	if ((int)Player.PositionX < SCREEN_LIMIT_LEFT)
	{
		Player.PositionX = SCREEN_LIMIT_LEFT;	//座標の補正
		Player.VelocityX = 0.0f;
	}
	else if ((int)Player.PositionX > SCREEN_LIMIT_RIGHT)
	{
		Player.PositionX = SCREEN_LIMIT_RIGHT;	//座標の補正
		Player.VelocityX = 0.0f;
	}
	if (Player.PositionY < SCREEN_LIMIT_UP)
	{
		Player.PositionY = SCREEN_LIMIT_UP;		//座標の補正
		Player.VelocityY = 0.0f;
	}
	else if (Player.PositionY > SCREEN_LIMIT_DOWN)
	{
		Player.PositionY = SCREEN_LIMIT_DOWN;	//座標の補正
		Player.VelocityY = 0.0f;
	}


	//下キーで弾を撃つ
	if (IsKeyTrigger(PPK_DOWN))
	{
		//プレイヤーの向いている方向へ弾を出すには？
		CreateBullet(Player.PositionX, Player.PositionY, BULLET_SPEED, 0.0f);

	}




}
void	DrawPlayer()		//描画
{

	//前回のプレイヤーを消去
	//画面の座標はint型なので、型変換を行って表示座標を設定する
	gotoxy((int)Player.PositionXOld, (int)Player.PositionYOld);
	std::cout << " ";	//設定した座標にスペースを表示して消去する
	//文字の表示色を変更
	textcolor(RED);				//文字を赤に変更
	//現在のプレイヤーを表示
	gotoxy((int)Player.PositionX, (int)Player.PositionY);
	std::cout << "P";	//とりあえずP

	Player.PositionXOld = Player.PositionX;	//現在の座標を保存
	Player.PositionYOld = Player.PositionY;

}

//静止状態
void	PlayerIdle()
{
	Player.VelocityX = 0;	//移動量リセット
	Player.VelocityY = 0;

	//キー入力
	if (IsKeyPress(PPK_A))
	{//Wキーが押されている
		Player.Mode = PLAYER_WALK;
	}
	else if (IsKeyPress(PPK_D))
	{//Sキーが押されている
		Player.Mode = PLAYER_WALK;
	}

	if (IsKeyPress(PPK_UP))	//矢印上キーでジャンプ
	//if (IsKeyTrigger(PPK_UP))	//矢印上キーでジャンプ
	//	if (IsKeyRelease(PPK_UP))	//矢印上キーでジャンプ
	{
		Player.Mode = PLAYER_JUMP;
		Player.AccelerationY = PLAYER_GRAVITY;	//加減速（重力加速）
		Player.VelocityY = -PLAYER_JUMP_SPEED;	//ジャンプスピード
	}


}
//歩き
void	PlayerWalk()
{
	//キー入力
	if (IsKeyPress(PPK_A))
	{//Wキーが押されている
		Player.VelocityX = -PLAYER_SPEED_X;
	}
	else if (IsKeyPress(PPK_D))
	{//Sキーが押されている
		Player.VelocityX = PLAYER_SPEED_X;
	}
	else
	{	//移動キーを押していない場合は減速処理
		Player.VelocityX *= PLAYER_BRAKE;
		if (fabs(Player.VelocityX) < 0.05f)	//絶対値で判定
		{
			Player.VelocityX = 0.0f;	//強制的に静止
			Player.Mode = PLAYER_IDLE;	//モード変更
		}
	}

	if (IsKeyTrigger(PPK_UP))	//矢印上キーでジャンプ
	{
		Player.Mode = PLAYER_JUMP;
		Player.AccelerationY = PLAYER_GRAVITY;	//加減速（重力加速）
		Player.VelocityY = -PLAYER_JUMP_SPEED;	//ジャンプスピード
	}

	//フィールドとの当たり判定
	float	px = Player.PositionX;
	float	py = Player.PositionY;

	if (!CollisionPlayerField(px, py + 1.0f))//足元チェック
	{
		Player.Mode = PLAYER_FALL;	//落下モードへ移行
	}

	if (Player.VelocityX > 0.0f)
	{
		px += Player.Width;	//ポイントを右方向にずらす
	}
	else
	{
		px -= Player.Width;	//ポイントを左方向にずらす
	}

	if (CollisionPlayerField(px, py))	//移動先のチェック
	{
		Player.VelocityX = 0.0f;		//ぶつかってたらストップ
	}

	Player.PositionX += Player.VelocityX;	//現在の座標の更新
	Player.PositionY += Player.VelocityY;


}
//ジャンプ（上昇）
void	PlayerJump()
{
	//キー入力
	if (IsKeyPress(PPK_A))
	{//Aキーが押されている
		Player.VelocityX = -PLAYER_SPEED_X;
	}
	else if (IsKeyPress(PPK_D))
	{//Dキーが押されている
		Player.VelocityX = PLAYER_SPEED_X;
	}
	else
	{	//移動キーを押していない場合は減速処理
		Player.VelocityX *= PLAYER_BRAKE;
		if (fabs(Player.VelocityX) < 0.05f)	//絶対値で判定
		{
			Player.VelocityX = 0.0f;	//強制的に静止
			//Player.Mode = PLAYER_IDLE;	//モード変更
		}
	}

	Player.VelocityY += Player.AccelerationY;//ジャンプ加速度の処理

	if (Player.VelocityY > 0.0f)	//ジャンプの頂点に来たら
	{
		Player.Mode = PLAYER_FALL;	//落下へ移行する
		Player.VelocityY = 0.0f;
	}

	//フィールドとの当たり判定
	float	px = Player.PositionX;
	float	py = Player.PositionY;

	if (CollisionPlayerField(px, py - 1.0f))//頭上チェック
	{
		Player.VelocityX = 0.0f;//頭ぶつけたら移動ストップ
		Player.VelocityY = 0.0f;
	}

	//横とか斜め上方向もチェックする？


	Player.PositionX += Player.VelocityX;	//現在の座標の更新
	Player.PositionY += Player.VelocityY;


}
//ジャンプ（下降）
void	PlayerFall()
{
	//キー入力
	if (IsKeyPress(PPK_A))
	{//Aキーが押されている
		Player.VelocityX = -PLAYER_SPEED_X;
	}
	else if (IsKeyPress(PPK_D))
	{//Dキーが押されている
		Player.VelocityX = PLAYER_SPEED_X;
	}
	else
	{	//移動キーを押していない場合は減速処理
		Player.VelocityX *= PLAYER_BRAKE;
		if (fabs(Player.VelocityX) < 0.05f)	//絶対値で判定
		{
			Player.VelocityX = 0.0f;	//強制的に静止
			//Player.Mode = PLAYER_IDLE;	//モード変更
		}
	}

	Player.VelocityY += Player.AccelerationY;//ジャンプ加速度の処理
	if (Player.VelocityY > 1.0f)	//落下速度の限界チェック
	{
		Player.VelocityY = 1.0f;
	}


	//フィールドとの当たり判定
	float	px = Player.PositionX;
	float	py = Player.PositionY;

	if (CollisionPlayerField(px, py + 1.0f))//足元チェック
	{
		Player.VelocityX = 0.0f;
		Player.VelocityY = 0.0f;
		Player.Mode = PLAYER_WALK;//WALKモードへ移行
	}

	//横とか斜め下方向もチェックする？

	Player.PositionX += Player.VelocityX;	//現在の座標の更新
	Player.PositionY += Player.VelocityY;

	////とりあえずの着地処理
	//if ((int)Player.PositionY > PLAYER_START_POSY)
	//{
	//	Player.PositionY = PLAYER_START_POSY;
	//	Player.Mode = PLAYER_WALK;	//いったんWALKに移行
	//	Player.VelocityY = 0.0f;
	//}

}
//プレイヤー構造体の取得
OBJECT* GetPlayer()
{
	return &Player;
}

/*
* ジャンプ完成＝＝＝＞キー入力作成
* 
*/

