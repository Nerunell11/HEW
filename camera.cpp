#include "camera.h"

OBJECT camera; //�J�����\����

void InitCamera()
{
    // �J�����̏����ʒu
    camera.PositionX = CAMERA_START_POSX;
    camera.PositionY = CAMERA_START_POSY;
    camera.PositionXOld = camera.PositionX;
    camera.PositionYOld = camera.PositionY;

    camera.Mode = CAMERA_IDLE;
    camera.Use = true;
}

void FinalizeCamera()
{

}

void UpdateCamera()
{
   
}



void CameraCheck()
{//�v���C���[���O�i�o������Ăяo��

    camera.Mode = CAMERA_MOVE;
    camera.PositionY -= 6.0f;


    camera.Mode = CAMERA_IDLE;
}

void CameraMove()
{
    // �J�����̃��[�h��IDLE�ɖ߂�
    camera.Mode = CAMERA_IDLE;
}

OBJECT* GetCamera()
{
    return &camera;
}
