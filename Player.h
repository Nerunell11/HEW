#pragma once	//�w�b�_�[�t�@�C����d��`�̖h�~


#define		CONIOEX	//<<<<<<<<<main.cpp�ȊO��common.h�̏�ɏ����Ă���
#include	"common.h"	


//�v���C���[�̈ړ���
#define	PLAYER_SPEED_X		(0.2f)
#define	PLAYER_SPEED_Y		(PLAYER_SPEED_X / 2.0f)//�c�͉��̔����̃X�s�[�h
//�v���C���[�̃X�^�[�g�ʒu
#define	PLAYER_START_POSX	(SCREEN_LIMIT_RIGHT  / 2)
#define PLAYER_START_POSY	(SCREEN_LIMIT_DOWN - 1)
//���������x
#define	PLAYER_GRAVITY		(9.8f / 350.0f)	//�l�͂��������ɒ���
#define	PLAYER_JUMP_SPEED	(PLAYER_SPEED_Y * 5.0f)
#define	PLAYER_BRAKE		(0.9f)		//�ړ����x�̌���


//�v���C���[�̏��
enum PLAYERMODE
{
	PLAYER_IDLE = 0,	//�Î~��ԁi�L�[���͖����j
	PLAYER_WALK,		//����
	PLAYER_JUMP,		//�W�����v�i�㏸�j
	PLAYER_FALL,		//�W�����v�i���~�j

};


//�v���g�^�C�v�錾
void	InitPlayer();		//������
void	FinalizePlayer();	//�I������
void	UpdatePlayer();		//�X�V����
void	DrawPlayer();		//�`��

void	PlayerIdle();		//�Î~���
void	PlayerWalk();		//����
void	PlayerJump();		//�W�����v�i�㏸�j
void	PlayerFall();		//�W�����v�i���~�j

OBJECT* GetPlayer();		//�v���C���[�\���̂̎擾

