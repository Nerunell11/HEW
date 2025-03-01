#pragma once

//���̃t�@�C���͊�{�I�ɑS�Ẵv���O�����ɃC���N���[�h����

//conioex�֘A�ŏo�Ă���x���𖳎�����
#pragma warning(disable:4311)
#pragma warning(disable:4312)
#pragma warning(disable:4302)


#include "conioex.h"//�O���[�]�[���ȓ���@�\��ǉ�
#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <time.h>
#include <cstdlib>
#include <ctime>


#include	"key.h"	//�L�[���͏���
#include    "sound.h"
//#include	"collision.h"


//�Q�[���V�[���̒�`
enum GAMESCENE
{
	SCENE_NONE = 0,		//�Ȃɂ��Ȃ�
	SCENE_TITLE,		//�^�C�g�����
	SCENE_GAME,			//�Q�[��
	SCENE_RESULT,		//���U���g


	SCENE_MAX			//��ԍŌ�̃f�\�^(�V�[���̌�)
};




//�}�N����`
// 
//��ʂ̒[��\�����W���` �l�͓K��
#define	SCREEN_LIMIT_UP		(1)
#define	SCREEN_LIMIT_DOWN	(24)
#define	SCREEN_LIMIT_LEFT	(1)
#define	SCREEN_LIMIT_RIGHT	(80)

//���[���h�̒[��\�����W���`
#define WORLD_LIMIT_UP		(1)
#define WORLD_LIMIT_DOWN	(102)
#define WORLD_LIMIT_LEFT	(1)
#define WORLD_LIMIT_RIGHT	(80)



//�\���̒�`
struct OBJECT
{
	bool	Use;						//�g�p���t���O
	int		Mode;						//�L�����N�^�[�̏�� �Î~�@�����@�W�����v

	float	PositionX, PositionY;		//�\�����W
	float	PositionXOld, PositionYOld;	//�O��̕\�����W
	float	VelocityX, VelocityY;		//�ړ�����

	float	AccelerationX, AccelerationY;	//�����x

	float		Width;	//��
	float		Height;	//����

	float		AnimationCounter;
	float		AnimationTimer;
	//�L�����N�^�[�̌�����\���ϐ���ǉ�

};


//�v���g�^�C�v�錾

//�V�[���̐؂�ւ�
void	SetScene(GAMESCENE scene);
//�V�[���̎擾
GAMESCENE GetScene();


