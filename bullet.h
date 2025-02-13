#pragma once

//bullet.h

#define		CONIOEX
#include	"common.h"

//�e�̍ő吔
#define		BULLET_MAX	(10)

//�e�̃X�s�[�h
#define		BULLET_SPEED	(0.4f)


//�v���g�^�C�v�錾
void	InitBullet();
void	FinalizeBullet();
void	UpdateBullet();
void	DrawBullet();

//�e�쐬�֐�
void	CreateBullet(float x, float y, float dx, float dy);
//�e�\���̎擾
OBJECT* GetBullet();

