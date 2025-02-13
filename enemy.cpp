
#include	"enemy.h"

OBJECT		Enemy[ENEMY_MAX];		//�G�\����


OBJECT* GetEnemy()
{
	return &Enemy[0];
}

void	InitEnemy()
{
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		//�G�̏�����
		Enemy[i].PositionX = 30.0f;	//�K���Ȓl
		Enemy[i].PositionY = 20.0f;
		Enemy[i].PositionXOld = Enemy[i].PositionX;
		Enemy[i].PositionYOld = Enemy[i].PositionY;
		Enemy[i].VelocityX = ((float)rand() / RAND_MAX) / 2.0f;//�K���Ȓl
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
				Enemy[i].VelocityX *= -1.0f;				//�ړ������̔��]
				Enemy[i].PositionX = SCREEN_LIMIT_LEFT;	//���W�̕␳
			}
			else if ((int)Enemy[i].PositionX > SCREEN_LIMIT_RIGHT)
			{
				Enemy[i].VelocityX *= -1.0f;				//�ړ������̔��]
				Enemy[i].PositionX = SCREEN_LIMIT_RIGHT;	//���W�̕␳
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

	//�����F�̕ύX
	textcolor(COLORS::YELLOW);
	for (int i = 0; i < ENEMY_MAX; i++)
	{
		if (Enemy[i].Use == true)
		{
			//�O��̓G������
			gotoxy((int)Enemy[i].PositionXOld, (int)Enemy[i].PositionYOld);
			std::cout << " ";
			//���݂̓G��\��
			gotoxy((int)Enemy[i].PositionX, (int)Enemy[i].PositionY);
			std::cout << "E";
		}
	}


}

