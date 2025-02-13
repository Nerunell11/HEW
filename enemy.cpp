
#include	"enemy.h"

OBJECT		Enemy[ENEMY_MAX];		//敵構造体


OBJECT* GetEnemy()
{
	return &Enemy[0];
}

void	InitEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//敵の初期化
		Enemy[i].PositionX = 30.0f;	//適当な値
		Enemy[i].PositionY = 20.0f;
		Enemy[i].PositionXOld = Enemy[i].PositionX;
		Enemy[i].PositionYOld = Enemy[i].PositionY;
		Enemy[i].VelocityX = ((float)rand() / RAND_MAX) / 2.0f;//適当な値
		Enemy[i].VelocityY = ((float)rand() / RAND_MAX) / 2.0f;

		Enemy[i].Width = 0.8f;
		Enemy[i].Height = 0.8f;

		Enemy[i].Use = true;

	}
}
void	FinalizeEnemy()
{

}
void	UpdateEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].Use == true)
		{
			//Enemy[i].PositionXOld = Enemy[i].PositionX;
			//Enemy[i].PositionYOld = Enemy[i].PositionY;
			//Enemy[i].PositionX += Enemy[i].VelocityX;
			//Enemy[i].PositionY += Enemy[i].VelocityY;

			if ((int)Enemy[i].PositionX < SCREEN_LIMIT_LEFT)
			{
				Enemy[i].VelocityX *= -1.0f;				//移動方向の反転
				Enemy[i].PositionX = SCREEN_LIMIT_LEFT;	//座標の補正
			}
			else if ((int)Enemy[i].PositionX > SCREEN_LIMIT_RIGHT)
			{
				Enemy[i].VelocityX *= -1.0f;				//移動方向の反転
				Enemy[i].PositionX = SCREEN_LIMIT_RIGHT;	//座標の補正
			}
			if (Enemy[i].PositionY < SCREEN_LIMIT_UP)
			{
				Enemy[i].VelocityY *= -1.0f;
				Enemy[i].PositionY = SCREEN_LIMIT_UP;
			}
			else if (Enemy[i].PositionY > SCREEN_LIMIT_DOWN)
			{
				Enemy[i].VelocityY *= -1.0f;
				Enemy[i].PositionY = SCREEN_LIMIT_DOWN;
			}
		}
	}

}
void	DrawEnemy()
{

	//文字色の変更
	textcolor(COLORS::YELLOW);
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].Use == true)
		{
			//前回の敵を消去
			gotoxy((int)Enemy[i].PositionXOld, (int)Enemy[i].PositionYOld);
			std::cout << " ";
			//現在の敵を表示
			gotoxy((int)Enemy[i].PositionX, (int)Enemy[i].PositionY);
			std::cout << "E";
		}
	}


}

