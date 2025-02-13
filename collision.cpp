
//collision.cpp

#include	"collision.h"
#include	"Player.h"
#include	"field.h"


//プレイヤー　対　足場
//px, py フィールドにぶつかっているかを調べたい座標
//
bool	CollisionPlayerField(float px, float py)
{
	OBJECT* player = GetPlayer();	//プレイヤー構造体を取得
	OBJECT* field = GetField();		//フィールド構造体の先頭のポインタを取得
	//構造体が使用中か？
	if (player->Use == true)
	{
		for (int i = 0; i < FIELD_MAX; i++)
		{
			if (field[i].Use == true)
			{
				float	Lx = field[i].PositionX;
				float	Ly = field[i].PositionY;
				float	Sx = field[i].Width;
				float	Sy = field[i].Height;
				bool	ret = CollisionPointBox(px, py, Lx, Ly, Sx, Sy);
				if (ret == true)
				{
					return true;
				}
			}
		}
	}
	return	false;
}




//衝突判定
//点と矩形
//
//Px,Py=点の座標
//Lx,Ly=矩形の左上の座標 
//Sx,Sy=矩形の横縦サイズ
//
bool	CollisionPointBox(float Px, float Py, float Lx, float Ly, float Sx, float Sy)
{
	//右下の座標を作る
	float	Rx = Lx + Sx;
	float	Ry = Ly + Sy;

	//点の座標がXY共に2つの座標の間にあるか？
	if ((Px >= Lx) && (Px <= Rx) && (Py >= Ly) && (Py <= Ry))
	{
		return true;
	}

	return false;

}
//矩形と矩形
//
//L1x,L1y=矩形１の左上座標
//S1x,S1y=矩形１の横縦サイズ
//L2x,L2y=矩形２の左上座標
//S2x,S2y=矩形２の横縦サイズ
//
bool	CollisionBoxBox(float L1x, float L1y, float S1x, float S1y,
	float L2x, float L2y, float S2x, float S2y)
{
	//矩形１の右下の座標を作る
	float R1x = L1x + S1x;
	float R1y = L1y + S1y;
	//矩形２の右下の座標を作る
	float R2x = L2x + S2x;
	float R2y = L2y + S2y;

	if ((R1x < L2x) || (L1x > R2x) || (L2y > R1y) || (R2y < L1y))
	{
		return false;//当たっていない
	}

	return true;
}

