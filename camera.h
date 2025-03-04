#pragma once

//camera.h

#define		CONIOEX	//<<<<<<<<<main.cpp�ȊO��common.h�̏�ɏ����Ă���
#include	"common.h"	
#include	"Player.h"

//�J�����̏����ʒu
#define 	CAMERA_START_POSX	(WORLD_LIMIT_UP)
#define 	CAMERA_START_POSY	(WORLD_LIMIT_DOWN-24) // �c�`��͈͂�24

//�J�����̕��ƍ���
#define CAMERA_WIDTH  (80)
#define CAMERA_HEIGHT (24)

enum CAMERAMODE
{
	CAMERA_IDLE = 0,	//�Î~��ԁi�L�[���͖����j
	CAMERA_MOVE,		//�ړ�
	CAMERA_JUMP,		//�W�����v�i�㏸�j
	CAMERA_FALL,		//�W�����v�i���~�j
};

//�v���g�^�C�v�錾
void	InitCamera();
void	FinalizeCamera();
void	UpdateCamera();

void	CameraCheck();
void	CameraMove();
OBJECT* GetCamera();

