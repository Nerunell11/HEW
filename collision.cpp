
//collision.cpp

#include	"collision.h"
#include	"Player.h"
#include	"field.h"


//�v���C���[�@�΁@����
//px, py �t�B�[���h�ɂԂ����Ă��邩�𒲂ׂ������W
//
bool	CollisionPlayerField(float px, float py)
{
	OBJECT* player = GetPlayer();	//�v���C���[�\���̂��擾
	OBJECT* field = GetField();		//�t�B�[���h�\���̂̐擪�̃|�C���^���擾
	//�\���̂��g�p�����H
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




//�Փ˔���
//�_�Ƌ�`
//
//Px,Py=�_�̍��W
//Lx,Ly=��`�̍���̍��W 
//Sx,Sy=��`�̉��c�T�C�Y
//
bool	CollisionPointBox(float Px, float Py, float Lx, float Ly, float Sx, float Sy)
{
	//�E���̍��W�����
	float	Rx = Lx + Sx;
	float	Ry = Ly + Sy;

	//�_�̍��W��XY����2�̍��W�̊Ԃɂ��邩�H
	if ((Px >= Lx) && (Px <= Rx) && (Py >= Ly) && (Py <= Ry))
	{
		return true;
	}

	return false;

}
//��`�Ƌ�`
//
//L1x,L1y=��`�P�̍�����W
//S1x,S1y=��`�P�̉��c�T�C�Y
//L2x,L2y=��`�Q�̍�����W
//S2x,S2y=��`�Q�̉��c�T�C�Y
//
bool	CollisionBoxBox(float L1x, float L1y, float S1x, float S1y,
	float L2x, float L2y, float S2x, float S2y)
{
	//��`�P�̉E���̍��W�����
	float R1x = L1x + S1x;
	float R1y = L1y + S1y;
	//��`�Q�̉E���̍��W�����
	float R2x = L2x + S2x;
	float R2y = L2y + S2y;

	if ((R1x < L2x) || (L1x > R2x) || (L2y > R1y) || (R2y < L1y))
	{
		return false;//�������Ă��Ȃ�
	}

	return true;
}

