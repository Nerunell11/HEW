

//field.cpp

#include	"field.h"

//フィール構造体配列
OBJECT	field[FIELD_MAX];

//フィールド配置テーブル
//
// 左上座標　　サイズ
//Posx, PosY, Width, Height
//
float	MapData[][4] =
{
	{SCREEN_LIMIT_LEFT, SCREEN_LIMIT_DOWN, 80, 1},//地面
	{50, 23, 8, 1},
	{40, 20, 8, 1},




	{-1,-1,-1,-1}	//データの終端
};




//初期化
void	InitField()
{
	for (int i = 0; i < FIELD_MAX; i++)
	{
		field[i].Use = false;
	}

	//足場を作成
	int	i = 0;
	while (MapData[i][0] != -1)
	{
		CreateField(MapData[i][0], MapData[i][1], MapData[i][2], MapData[i][3]);
		i++;
	};




}

//終了処理
void	FinalizeField()
{

}

//更新処理
void	UpdateField()
{

}

//描画処理
void	DrawField()
{
	for (int i = 0; i < FIELD_MAX; i++)
	{
		if (field[i].Use == true)
		{
			float posx = field[i].PositionX;
			float posy = field[i].PositionY;

			for (int y = 0; y < field[i].Height; y++)
			{
				gotoxy((int)posx, (int)posy);
				for (int x = 0; x < field[i].Width; x++)
				{
					std::cout << "=";
				}
				posy++;
			}

		}

	}

}

//足場の作成
void	CreateField(float x, float y, float w, float h)
{
	for (int i = 0; i < FIELD_MAX; i++)
	{
		if (field[i].Use == false)
		{
			field[i].Use = true;
			field[i].PositionX = x;
			field[i].PositionY = y;
			field[i].Width = w;
			field[i].Height = h;
			break;
		}
	}
}

OBJECT* GetField()
{
	return &field[0];
}


