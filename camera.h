#pragma once

//camera.h

#define		CONIOEX	//<<<<<<<<<main.cpp�ȊO��common.h�̏�ɏ����Ă���
#include	"common.h"	

//�J�����̏����ʒu
#define 	CAMERA_START_POSX	(12)
#define 	CAMERA_START_POSY	(WORLD_LIMIT_DOWN-12)//�c�`��͈͂�24

//�v���g�^�C�v�錾
void	InitCamera();
void	FinalizeCamera();
void	UpdateCamera();



