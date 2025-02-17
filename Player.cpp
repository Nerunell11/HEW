
#include	"collision.h"
#include	"Player.h"



OBJECT		Player;				//�v���C���[�\����

void	InitPlayer()		//������
{

	//�v���C���[�̏�����
	Player.PositionX = PLAYER_START_POSX;	//�K���Ȓl
	Player.PositionY = PLAYER_START_POSY;
	Player.PositionXOld = Player.PositionX;
	Player.PositionYOld = Player.PositionY;

	Player.Mode = PLAYER_IDLE;
	Player.Use = true;

	Player.Width = 0.8f;
	Player.Height = 0.8f;

}
void	FinalizePlayer()	//�I������
{

}
void	UpdatePlayer()		//�X�V����
{

if (Player.Use == true)
{	//�v���C���[�̏�Ԃ��Ƃ̏���
	switch (Player.Mode)
	{
	case PLAYER_IDLE:
		PlayerCheck();
		break;
	case PLAYER_MOVE:
		PlayerMove();
		break;
	case PLAYER_JUMP:
		//PlayerJump();
		break;
	}
}

//��ʊO�`�F�b�N
if ((int)Player.PositionX < SCREEN_LIMIT_LEFT)
{
	Player.PositionX = SCREEN_LIMIT_LEFT;	//���W�̕␳
	Player.VelocityX = 0.0f;
}
else if ((int)Player.PositionX > SCREEN_LIMIT_RIGHT)
{
	Player.PositionX = SCREEN_LIMIT_RIGHT;	//���W�̕␳
	Player.VelocityX = 0.0f;
}
if (Player.PositionY < SCREEN_LIMIT_UP)
{
	Player.PositionY = SCREEN_LIMIT_UP;		//���W�̕␳
	Player.VelocityY = 0.0f;
}
else if (Player.PositionY > SCREEN_LIMIT_DOWN)
{
	Player.PositionY = SCREEN_LIMIT_DOWN;	//���W�̕␳
	Player.VelocityY = 0.0f;
}
}
void	DrawPlayer()		//�`��
{

	//�O��̃v���C���[������
	//��ʂ̍��W��int�^�Ȃ̂ŁA�^�ϊ����s���ĕ\�����W��ݒ肷��
	gotoxy((int)Player.PositionXOld, (int)Player.PositionYOld);
	std::cout << " ";	//�ݒ肵�����W�ɃX�y�[�X��\�����ď�������
	//�����̕\���F��ύX
	textcolor(RED);				//������ԂɕύX
	//���݂̃v���C���[��\��
	gotoxy((int)Player.PositionX, (int)Player.PositionY);
	std::cout << "P";	//�Ƃ肠����P

	Player.PositionXOld = Player.PositionX;	//���݂̍��W��ۑ�
	Player.PositionYOld = Player.PositionY;

}

//�Î~��Ԕ���
void	PlayerCheck()
{
	Player.VelocityX = 0;	//�ړ��ʃ��Z�b�g
	Player.VelocityY = 0;

	//�L�[����
	//�����
	if (IsKeyRelease(PPK_W) || IsKeyRelease(PPK_UP))
	{
		Player.Mode = PLAYER_JUMP;
	}
	//���E����
	else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT) ||
			 IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
	{
			Player.Mode = PLAYER_MOVE;
	}

	//����������Ă��Ȃ�
	else
	{
		Player.Mode = PLAYER_IDLE;
	}
}

//����
void	PlayerMove()
{
	if (IsKeyRelease(PPK_W) || IsKeyRelease(PPK_UP))
	{
		//���ꂪ��ɂ����
		if (!CollisionPlayerField(Player.PositionX, Player.PositionY++))
		{
			Player.PositionY++;
		}
		//���ꂪ�Ȃ��Ă����v�ł�
	}

	else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT))
	{
		//���ꂪ����ɂ����
		if (!CollisionPlayerField(Player.PositionX--, Player.PositionY++))
		{
			Player.VelocityX--;
		}
		//���ꂪ�Ȃ��Ȃ�
		else
		{
			//GameOver����
		}
	}

	else if (IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
	{
		//���ꂪ�E��ɂ����
		if (!CollisionPlayerField(Player.PositionX++, Player.PositionY++))
		{
			Player.VelocityX++;
		}
		//���ꂪ�Ȃ��Ȃ�
		else
		{
			//GameOver����
		}
	}
	else
	{

	}
		
	Player.PositionX += Player.VelocityX;	//���݂̍��W�̍X�V
	Player.PositionY += Player.VelocityY;

}

//�v���C���[�\���̂̎擾
OBJECT* GetPlayer()
{
	return &Player;
}
