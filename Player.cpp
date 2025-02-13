
#include	"collision.h"
#include	"Player.h"
#include	"bullet.h"


OBJECT		Player;				//�v���C���[�\����

void	InitPlayer()		//������
{

	//�v���C���[�̏�����
	Player.PositionX = PLAYER_START_POSX;	//�K���Ȓl
	Player.PositionY = PLAYER_START_POSY;
	Player.PositionXOld = Player.PositionX;
	Player.PositionYOld = Player.PositionY;
	Player.VelocityX = 0;	//�K���Ȓl
	Player.VelocityY = 0;

	Player.AccelerationX = 0.0f;
	Player.AccelerationY = 0.0f;
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
			PlayerIdle(); 
			break;
		case PLAYER_WALK:
			PlayerWalk();
			break;
		case PLAYER_JUMP:
			PlayerJump();
			break;
		case PLAYER_FALL:
			PlayerFall();
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


	//���L�[�Œe������
	if (IsKeyTrigger(PPK_DOWN))
	{
		//�v���C���[�̌����Ă�������֒e���o���ɂ́H
		CreateBullet(Player.PositionX, Player.PositionY, BULLET_SPEED, 0.0f);

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

//�Î~���
void	PlayerIdle()
{
	Player.VelocityX = 0;	//�ړ��ʃ��Z�b�g
	Player.VelocityY = 0;

	//�L�[����
	if (IsKeyPress(PPK_A))
	{//W�L�[��������Ă���
		Player.Mode = PLAYER_WALK;
	}
	else if (IsKeyPress(PPK_D))
	{//S�L�[��������Ă���
		Player.Mode = PLAYER_WALK;
	}

	if (IsKeyPress(PPK_UP))	//����L�[�ŃW�����v
	//if (IsKeyTrigger(PPK_UP))	//����L�[�ŃW�����v
	//	if (IsKeyRelease(PPK_UP))	//����L�[�ŃW�����v
	{
		Player.Mode = PLAYER_JUMP;
		Player.AccelerationY = PLAYER_GRAVITY;	//�������i�d�͉����j
		Player.VelocityY = -PLAYER_JUMP_SPEED;	//�W�����v�X�s�[�h
	}


}
//����
void	PlayerWalk()
{
	//�L�[����
	if (IsKeyPress(PPK_A))
	{//W�L�[��������Ă���
		Player.VelocityX = -PLAYER_SPEED_X;
	}
	else if (IsKeyPress(PPK_D))
	{//S�L�[��������Ă���
		Player.VelocityX = PLAYER_SPEED_X;
	}
	else
	{	//�ړ��L�[�������Ă��Ȃ��ꍇ�͌�������
		Player.VelocityX *= PLAYER_BRAKE;
		if (fabs(Player.VelocityX) < 0.05f)	//��Βl�Ŕ���
		{
			Player.VelocityX = 0.0f;	//�����I�ɐÎ~
			Player.Mode = PLAYER_IDLE;	//���[�h�ύX
		}
	}

	if (IsKeyTrigger(PPK_UP))	//����L�[�ŃW�����v
	{
		Player.Mode = PLAYER_JUMP;
		Player.AccelerationY = PLAYER_GRAVITY;	//�������i�d�͉����j
		Player.VelocityY = -PLAYER_JUMP_SPEED;	//�W�����v�X�s�[�h
	}

	//�t�B�[���h�Ƃ̓����蔻��
	float	px = Player.PositionX;
	float	py = Player.PositionY;

	if (!CollisionPlayerField(px, py + 1.0f))//�����`�F�b�N
	{
		Player.Mode = PLAYER_FALL;	//�������[�h�ֈڍs
	}

	if (Player.VelocityX > 0.0f)
	{
		px += Player.Width;	//�|�C���g���E�����ɂ��炷
	}
	else
	{
		px -= Player.Width;	//�|�C���g���������ɂ��炷
	}

	if (CollisionPlayerField(px, py))	//�ړ���̃`�F�b�N
	{
		Player.VelocityX = 0.0f;		//�Ԃ����Ă���X�g�b�v
	}

	Player.PositionX += Player.VelocityX;	//���݂̍��W�̍X�V
	Player.PositionY += Player.VelocityY;


}
//�W�����v�i�㏸�j
void	PlayerJump()
{
	//�L�[����
	if (IsKeyPress(PPK_A))
	{//A�L�[��������Ă���
		Player.VelocityX = -PLAYER_SPEED_X;
	}
	else if (IsKeyPress(PPK_D))
	{//D�L�[��������Ă���
		Player.VelocityX = PLAYER_SPEED_X;
	}
	else
	{	//�ړ��L�[�������Ă��Ȃ��ꍇ�͌�������
		Player.VelocityX *= PLAYER_BRAKE;
		if (fabs(Player.VelocityX) < 0.05f)	//��Βl�Ŕ���
		{
			Player.VelocityX = 0.0f;	//�����I�ɐÎ~
			//Player.Mode = PLAYER_IDLE;	//���[�h�ύX
		}
	}

	Player.VelocityY += Player.AccelerationY;//�W�����v�����x�̏���

	if (Player.VelocityY > 0.0f)	//�W�����v�̒��_�ɗ�����
	{
		Player.Mode = PLAYER_FALL;	//�����ֈڍs����
		Player.VelocityY = 0.0f;
	}

	//�t�B�[���h�Ƃ̓����蔻��
	float	px = Player.PositionX;
	float	py = Player.PositionY;

	if (CollisionPlayerField(px, py - 1.0f))//����`�F�b�N
	{
		Player.VelocityX = 0.0f;//���Ԃ�����ړ��X�g�b�v
		Player.VelocityY = 0.0f;
	}

	//���Ƃ��΂ߏ�������`�F�b�N����H


	Player.PositionX += Player.VelocityX;	//���݂̍��W�̍X�V
	Player.PositionY += Player.VelocityY;


}
//�W�����v�i���~�j
void	PlayerFall()
{
	//�L�[����
	if (IsKeyPress(PPK_A))
	{//A�L�[��������Ă���
		Player.VelocityX = -PLAYER_SPEED_X;
	}
	else if (IsKeyPress(PPK_D))
	{//D�L�[��������Ă���
		Player.VelocityX = PLAYER_SPEED_X;
	}
	else
	{	//�ړ��L�[�������Ă��Ȃ��ꍇ�͌�������
		Player.VelocityX *= PLAYER_BRAKE;
		if (fabs(Player.VelocityX) < 0.05f)	//��Βl�Ŕ���
		{
			Player.VelocityX = 0.0f;	//�����I�ɐÎ~
			//Player.Mode = PLAYER_IDLE;	//���[�h�ύX
		}
	}

	Player.VelocityY += Player.AccelerationY;//�W�����v�����x�̏���
	if (Player.VelocityY > 1.0f)	//�������x�̌��E�`�F�b�N
	{
		Player.VelocityY = 1.0f;
	}


	//�t�B�[���h�Ƃ̓����蔻��
	float	px = Player.PositionX;
	float	py = Player.PositionY;

	if (CollisionPlayerField(px, py + 1.0f))//�����`�F�b�N
	{
		Player.VelocityX = 0.0f;
		Player.VelocityY = 0.0f;
		Player.Mode = PLAYER_WALK;//WALK���[�h�ֈڍs
	}

	//���Ƃ��΂߉��������`�F�b�N����H

	Player.PositionX += Player.VelocityX;	//���݂̍��W�̍X�V
	Player.PositionY += Player.VelocityY;

	////�Ƃ肠�����̒��n����
	//if ((int)Player.PositionY > PLAYER_START_POSY)
	//{
	//	Player.PositionY = PLAYER_START_POSY;
	//	Player.Mode = PLAYER_WALK;	//��������WALK�Ɉڍs
	//	Player.VelocityY = 0.0f;
	//}

}
//�v���C���[�\���̂̎擾
OBJECT* GetPlayer()
{
	return &Player;
}

/*
* �W�����v�������������L�[���͍쐬
* 
*/

