
//key.cpp

#include "key.h"
/*
PPK_UP = 0,
PPK_DOWN,
PPK_LEFT,
PPK_RIGHT,
PPK_ENTER,
PPK_Z,
PPK_X,
PPK_A,
PPK_S,
PPK_D,
*/

//�L�[�����\���̂̍쐬��������
KEYINFO	   KeyAssign[] =  //enum�̒�`�̏��ԂƓ����ɂ��邱��
{
	{PK_UP, 0,0,0,0,0,0},		//��
	{PK_DOWN, 0,0,0,0,0,0},		//��
	{PK_LEFT, 0,0,0,0,0,0},		//��
	{PK_RIGHT, 0,0,0,0,0,0},	//�E
	{PK_ENTER, 0,0,0,0,0,0},	//�G���^�[
	{PK_Z, 0,0,0,0,0,0},			//Z
	{PK_X, 0,0,0,0,0,0},			//X
	{PK_A, 0,0,0,0,0,0},			//A
	{PK_S, 0,0,0,0,0,0},			//S
	{PK_D, 0,0,0,0,0,0},			//D


	{-1, 0,0,0,0,0,0}			//�z��̍Ō��\���_�~�[���

};

//�L�[�\���̂̏�����
void	InitKey()
{
	int		i = 0;
	while (KeyAssign[i].Key != -1)//�L�[�̎�ނ�-1(�_�~�[�f�[�^)�łȂ���΃��[�v
	{
		KeyAssign[i].Press = 0;
		KeyAssign[i].Release = 0;
		KeyAssign[i].Trigger = 0;

		KeyAssign[i].PressOld = 0;
		KeyAssign[i].ReleaseOld = 0;
		KeyAssign[i].TriggerOld = 0;
		i++;
	};

}

//���݂̃L�[�����쐬
void	UpdateKey()
{
	int		i = 0;
	while (KeyAssign[i].Key != -1)
	{
		//�v���X���͂��擾�i���݂̃L�[�̏�ԁj
		KeyAssign[i].Press = inport(KeyAssign[i].Key);
		//�g���K�[���͂��쐬
		KeyAssign[i].Trigger = (KeyAssign[i].PressOld ^ KeyAssign[i].Press) & (KeyAssign[i].Press);
		//�����[�X���͂��쐬
		KeyAssign[i].Release = (KeyAssign[i].PressOld ^ KeyAssign[i].Press) & (~KeyAssign[i].Press);

		KeyAssign[i].PressOld = KeyAssign[i].Press;	//���݂̏�Ԃ�ۑ�
		i++;
	};

}

//�w��̃L�[�̌��݂̏�Ԃ𒲂ׂ� true=�����Ă���@�@false=�����Ă��Ȃ�
bool	IsKeyPress(int key)
{
	return (KeyAssign[key].Press == 1);
}

//�w��̃L�[�̃g���K�[���͂𒲂ׂ� true=�����Ă���@�@false=�����Ă��Ȃ�
bool	IsKeyTrigger(int key)
{
	return (KeyAssign[key].Trigger == 1);
}

//�w��̃L�[�̃����[�X���͂𒲂ׂ� true=�����Ă���@�@false=�����Ă��Ȃ�
bool	IsKeyRelease(int key)
{
	return (KeyAssign[key].Release == 1);
}







