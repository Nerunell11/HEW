#pragma once	//�w�b�_�[�t�@�C����d��`�̖h�~

#ifndef PLAYER_H
#define PLAYER_H

#define		CONIOEX	//<<<<<<<<<main.cpp�ȊO��common.h�̏�ɏ����Ă���
#include	"common.h"	
#include	"field.h"

//�v���C���[�̃X�^�[�g�ʒu
#define	PLAYER_START_POSX	(SCREEN_LIMIT_RIGHT / 2)
#define PLAYER_START_POSY	(WORLD_LIMIT_DOWN-1)							//(abs(WORLD_LIMIT_UP + WORLD_LIMIT_DOWN))



extern int PlayerUpCount;


//�v���C���[�̏��
enum PLAYERMODE
{
	PLAYER_IDLE = 0,	//�Î~��ԁi�L�[���͖����j
	PLAYER_MOVE,		//�ړ�
	PLAYER_JUMP,		//�W�����v�i�㏸�j
	PLAYER_FALL,		//�W�����v�i���~�j

};


//�v���g�^�C�v�錾
void	InitPlayer();		//������
void	FinalizePlayer();	//�I������
void	UpdatePlayer();		//�X�V����


void	PlayerCheck();		
void	PlayerMove();		//�v���C���[�̈ړ�

OBJECT* GetPlayer();		//�v���C���[�̈ʒu���擾


#endif
