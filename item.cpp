#include "item.h"

OBJECT Item[ITEM_MAX];

float	ItemData[][2] =
{
	{20, 23},
	{10, 20},
	{60, 10},



	{-1,-1}	//データの終端
};

//Animation Pattern
char ItemAnime[][2] =
{
	"I",
	"T",
	"E",
	"M",
};

void	InitItem()
{
	for (int i = 0; i < ITEM_MAX; i++)
	{
		Item[i].Use = false;
	}

	//足場を作成
	int	i = 0;
	while (ItemData[i][0] != -1)
	{
		CreateItem(ItemData[i][0], ItemData[i][1]);
		i++;
	};
}
void	FinalizeItem()
{

}
void	UpdateItem()
{
	for (int i = 0; i < ITEM_MAX; i++)
	{
		if (Item[i].Use == true)
		{
			Item[i].AnimationTimer += 0.5f;
			if (Item[i].AnimationTimer > 20.0f)
			{
				Item[i].AnimationTimer = 0.0f;
				Item[i].AnimationCounter += 1.0f;
				if (Item[i].AnimationCounter >= 4.0f)
				{
					Item[i].AnimationCounter = 0.0f;
				}
			}
		}
	}
}
void	DrawItem()
{
	for (int i = 0; i < ITEM_MAX; i++)
	{
		if (Item[i].Use == true)
		{
			textcolor(CYAN);

			gotoxy((int)Item[i].PositionX, (int)Item[i].PositionY);
			std::cout << ItemAnime[(int)Item[i].AnimationCounter][0];
		}
	}
}

void	CreateItem(float x, float y)
{
	for (int i = 0; i < ITEM_MAX; i++)
	{
		if (Item[i].Use == false)
		{	//弾構造体を初期化
			Item[i].Use = true;
			Item[i].PositionX = x;
			Item[i].PositionXOld = x;
			Item[i].PositionY = y;
			Item[i].PositionYOld = y;

			Item[i].Width = 0.8f;
			Item[i].Height = 0.8f;

			Item[i].AnimationCounter = 0.0f;
			Item[i].AnimationTimer = 0.0f;

			break;//ループから抜けて終了する

		}

	}
}
OBJECT* GetItem()
{
	return &Item[0];
}