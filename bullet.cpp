
//bullet.cpp

#include	"bullet.h"
#include	"collision.h"

//弾構造体配列
OBJECT	Bullet[BULLET_MAX];


//初期化
void	InitBullet()
{
	//構造体の初期化
	for (int i = 0; i < BULLET_MAX; i++)
	{
		Bullet[i].Use = false;
	}

}

//終了処理
void	FinalizeBullet()
{
}

//更新処理
void	UpdateBullet()
{
	//全ての構造体をチェック
	for (int i = 0; i < BULLET_MAX; i++)
	{	//構造体が使用中なら処理
		if (Bullet[i].Use == true)
		{
			bool ret = CollisonBulletEnemy(&Bullet[i]);

			//現在の座標を保存
			Bullet[i].PositionXOld = Bullet[i].PositionX;
			Bullet[i].PositionYOld = Bullet[i].PositionY;
			//現在の座標更新
			Bullet[i].PositionX += Bullet[i].VelocityX;
			Bullet[i].PositionY += Bullet[i].VelocityY;

		}

	}

}

//描画
void	DrawBullet()
{

	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].Use == true)
		{
			//前回の位置から移動していたら古い弾を消去
			if (
				((int)Bullet[i].PositionXOld != (int)Bullet[i].PositionX) ||
				((int)Bullet[i].PositionYOld != (int)Bullet[i].PositionY)
				)
			{
				gotoxy((int)Bullet[i].PositionXOld, (int)Bullet[i].PositionYOld);
				std::cout << " ";
			}
			//画面外チェック
			if (
				(int)Bullet[i].PositionX < SCREEN_LIMIT_LEFT ||
			    (int)Bullet[i].PositionX > SCREEN_LIMIT_RIGHT ||
			    (int)Bullet[i].PositionY < SCREEN_LIMIT_UP ||
			    (int)Bullet[i].PositionY > SCREEN_LIMIT_DOWN
				)
			{
				//画面外なので前回のキャラクタを消去
				gotoxy((int)Bullet[i].PositionXOld, (int)Bullet[i].PositionYOld);
				std::cout << " ";
				//構造体を未使用にする
				Bullet[i].Use = false;
			}
			else
			{
				//文字の表示色を変更
				textcolor(GREEN);
				//現在の座標に表示
				gotoxy((int)Bullet[i].PositionX, (int)Bullet[i].PositionY);
				std::cout << "o";
			}

		}

	}


}

//弾作成関数
//
//引数　x,y 出現座標　　dx,dy 移動スピード
//
void	CreateBullet(float x, float y, float dx, float dy)
{
	//未使用の構造体を見つける
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].Use == false)
		{	//弾構造体を初期化
			Bullet[i].Use = true;
			Bullet[i].PositionX = x;
			Bullet[i].PositionXOld = x;
			Bullet[i].PositionY = y;
			Bullet[i].PositionYOld = y;
			Bullet[i].VelocityX = dx;
			Bullet[i].VelocityY = dy;

			Bullet[i].Width = 0.8f;
			Bullet[i].Height = 0.8f;

			break;//ループから抜けて終了する

		}

	}
}

//弾構造体取得
OBJECT* GetBullet()
{
	return  &Bullet[0];
}




