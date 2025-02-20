
// key.h
#pragma once

#define CONIOEX			//main.cpp�ȊO��conioex���g�����͕K��#define����
#include "conioex.h"

//���̃Q�[���Ŏg���L�[��ݒ肷��
enum
{
	PPK_UP = 0,
	PPK_DOWN,
	PPK_LEFT,
	PPK_RIGHT,
	PPK_ENTER,
	PPK_W,
	PPK_A,
	PPK_S,
	PPK_D,

	//�K�v�ȕ��͒ǉ�����

};

//�L�[���\����
struct KEYINFO
{
	int		Key;		//�L�[�̎��
	int		Press;		//���݂̃L�[�̏��
	int		Trigger;	//�g���K�[����
	int		Release;	//�����[�X����

	int		PressOld;	//�O��̏��
	int		TriggerOld;
	int		ReleaseOld;
};

//�v���g�^�C�v�錾
void	InitKey();		//�Q�[�����[�v�ɓ���O�Ɉ��Ă�
void	UpdateKey();	//�Q�[�����[�v���ň��Ă�

//�ȉ��͕K�v�Ȏ��ɉ���ł��Ă�
bool	IsKeyPress(int key);	//key�̃v���X���͂𒲂ׂ�
bool	IsKeyTrigger(int key);	//key�̃g���K�[���͂𒲂ׂ�
bool	IsKeyRelease(int key);	//key�̃����[�X���͂𒲂ׂ�








