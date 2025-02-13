#pragma once

//collision.h

#define CONIOEX
#include "common.h"


//�v���C���[�@�΁@����
//px, py �t�B�[���h�ɂԂ����Ă��邩�𒲂ׂ������W
//
bool	CollisionPlayerField(float px, float py);

//�e�P�@�΁@�G�S��
// bullet=�e�\���̃|�C���^�[
bool	CollisonBulletEnemy(OBJECT* bullet);





//�Փ˔���
//�_�Ƌ�`
//
//Px,Py=�_�̍��W
//Lx,Ly=��`�̍���̍��W 
//Sx,Sy=��`�̉��c�T�C�Y
//
bool	CollisionPointBox(float Px, float Py, float Lx, float Ly, float Sx, float Sy);

//��`�Ƌ�`
//
//L1x,L1y=��`�P�̍�����W
//S1x,S1y=��`�P�̉��c�T�C�Y
//L2x,L2y=��`�Q�̍�����W
//S2x,S2y=��`�Q�̉��c�T�C�Y
//
bool	CollisionBoxBox(float L1x, float L1y, float S1x, float S1y,
						float L2x, float L2y, float S2x, float S2y);


/*

  R1x=L1x+S1x					R2x=L2x+S2x
  R1y=L1y+S1y                   R2y=L2y+S2y

  (L1x,L1y)                     (L2x,L2y)
     o---------                       o-------------------
	 |        |                       |                  |
	 |        |                       |                  |
	 |        |                       |                  |
	 ---------o                       |                  |
	       (R1x,R1y)                  |                  |
		                              |------------------o
									                 (R2x,R2y)

     �������Ă��Ȃ�����  
	 R1x < L2x         ��`�P����`�Q�̊��S�ɍ����ɂ���
	 L1x > R2x         ��`�P����`�Q�̊��S�ɉ����ɂ��遃�����E���ɂ���ɏC���I
	 L2y > R1y         ��`�Q����`�P�̊��S�ɉ����ɂ���
	 R2y < L1y         ��`�Q����`�P�̊��S�ɏ㑤�ɂ���
	 �ǂꂩ1�ł���������Γ�����Ȃ��ƍl����


	 
*/

//-------------------
//�~�Ɖ~�i�~�Ɠ_�j




