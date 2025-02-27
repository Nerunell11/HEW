

//field.cpp

#include	"field.h"

//�t�B�[���\���̔z��
OBJECT	field[FIELD_MAX];

//�t�B�[���h�z�u�e�[�u��
//
// ������W�@�@�T�C�Y
//Posx, PosY, Width, Height
//
float	MapData[][4] =
{
	//X���W, Y���W, ����, �c��
	{SCREEN_LIMIT_LEFT, SCREEN_LIMIT_DOWN, 80, 1},//�n��
	{SCREEN_LIMIT_LEFT, SCREEN_LIMIT_UP, 80, 1},//�V��
	{SCREEN_LIMIT_RIGHT,1,1,24},
	{SCREEN_LIMIT_LEFT,1,1,24},
	{38, 22, 1, 1},
	{40, 20, 1, 1},


	


	
	{-1,-1,-1,-1}	//�f�[�^�̏I�[
};




//������
void	InitField()
{
	for (int i = 0; i < FIELD_MAX; i++)
	{
		field[i].Use = false;
	}

	//������쐬
	int	i = 0;
	while (MapData[i][0] != -1)
	{
		CreateField(MapData[i][0], MapData[i][1], MapData[i][2], MapData[i][3]);
		i++;
	};




}

//�I������
void	FinalizeField()
{

}

//�X�V����
void	UpdateField()
{

}

//�`�揈��
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

//����̍쐬
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


