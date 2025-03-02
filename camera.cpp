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
    if (camera.Use == true)
    {
        // �v���C���[�̈ʒu���擾
        OBJECT* player = GetPlayer();

        // �J�����̈ʒu���v���C���[�̈ʒu�ɍ��킹�čX�V
        camera.PositionX = player->PositionX - CAMERA_WIDTH / 2;
        camera.PositionY = player->PositionY - CAMERA_HEIGHT / 2;

        // �J�����̈ʒu���X�V�iX���͌Œ�j
        camera.PositionYOld = camera.PositionY;

        camera.VelocityY += camera.AccelerationY;
        camera.PositionY += camera.VelocityY;

        // �K�v�ɉ����ăJ�����̈ʒu�𐧌����郍�W�b�N��ǉ�
        // ��: ��ʂ̒[�𒴂��Ȃ��悤�ɂ���
    }
}

void DrawCamera()
{
    // �J�����̕`�揈����ǉ�����ꍇ�͂����ɋL�q
}

void CameraCheck()
{
    camera.VelocityX = 0; // �ړ��ʃ��Z�b�g
    camera.VelocityY = 0;

    // �L�[����
    // �����
    if (IsKeyRelease(PPK_W) || IsKeyRelease(PPK_UP))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY -= 2.0f;
    }
    // ������
    else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY -= 2.0f;
    }
    // �E����
    else if (IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY -= 2.0f;
    }
    // ������
    else if (IsKeyRelease(PPK_S) || IsKeyRelease(PPK_DOWN))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY += 2.0f;
        std::cout << "Move down\n"; // �f�o�b�O�p
    }
    // ����������Ă��Ȃ�
    else
    {
        camera.Mode = CAMERA_IDLE;
    }
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
