
//bullet.cpp

#include	"bullet.h"
#include	"collision.h"

//�e�\���̔z��
OBJECT	Bullet[BULLET_MAX];


//������
void	InitBullet()
{
	//�\���̂̏�����
	for (int i = 0; i < BULLET_MAX; i++)
	{
		Bullet[i].Use = false;
	}

}

//�I������
void	FinalizeBullet()
{
}

//�X�V����
void	UpdateBullet()
{
	//�S�Ă̍\���̂��`�F�b�N
	for (int i = 0; i < BULLET_MAX; i++)
	{	//�\���̂��g�p���Ȃ珈��
		if (Bullet[i].Use == true)
		{
			bool ret = CollisonBulletEnemy(&Bullet[i]);

			//���݂̍��W��ۑ�
			Bullet[i].PositionXOld = Bullet[i].PositionX;
			Bullet[i].PositionYOld = Bullet[i].PositionY;
			//���݂̍��W�X�V
			Bullet[i].PositionX += Bullet[i].VelocityX;
			Bullet[i].PositionY += Bullet[i].VelocityY;

		}

	}

}

//�`��
void	DrawBullet()
{

	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].Use == true)
		{
			//�O��̈ʒu����ړ����Ă�����Â��e������
			if (
				((int)Bullet[i].PositionXOld != (int)Bullet[i].PositionX) ||
				((int)Bullet[i].PositionYOld != (int)Bullet[i].PositionY)
				)
			{
				gotoxy((int)Bullet[i].PositionXOld, (int)Bullet[i].PositionYOld);
				std::cout << " ";
			}
			//��ʊO�`�F�b�N
			if (
				(int)Bullet[i].PositionX < SCREEN_LIMIT_LEFT ||
			    (int)Bullet[i].PositionX > SCREEN_LIMIT_RIGHT ||
			    (int)Bullet[i].PositionY < SCREEN_LIMIT_UP ||
			    (int)Bullet[i].PositionY > SCREEN_LIMIT_DOWN
				)
			{
				//��ʊO�Ȃ̂őO��̃L�����N�^������
				gotoxy((int)Bullet[i].PositionXOld, (int)Bullet[i].PositionYOld);
				std::cout << " ";
				//�\���̂𖢎g�p�ɂ���
				Bullet[i].Use = false;
			}
			else
			{
				//�����̕\���F��ύX
				textcolor(GREEN);
				//���݂̍��W�ɕ\��
				gotoxy((int)Bullet[i].PositionX, (int)Bullet[i].PositionY);
				std::cout << "o";
			}

		}

	}


}

//�e�쐬�֐�
//
//�����@x,y �o�����W�@�@dx,dy �ړ��X�s�[�h
//
void	CreateBullet(float x, float y, float dx, float dy)
{
	//���g�p�̍\���̂�������
	for (int i = 0; i < BULLET_MAX; i++)
	{
		if (Bullet[i].Use == false)
		{	//�e�\���̂�������
			Bullet[i].Use = true;
			Bullet[i].PositionX = x;
			Bullet[i].PositionXOld = x;
			Bullet[i].PositionY = y;
			Bullet[i].PositionYOld = y;
			Bullet[i].VelocityX = dx;
			Bullet[i].VelocityY = dy;

			Bullet[i].Width = 0.8f;
			Bullet[i].Height = 0.8f;

			break;//���[�v���甲���ďI������

		}

	}
}

//�e�\���̎擾
OBJECT* GetBullet()
{
	return  &Bullet[0];
}




