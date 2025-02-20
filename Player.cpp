// Player.cpp

#include "Player.h"
#include "common.h" // ���ʃw�b�_�t�@�C��
#include <iostream> // �f�o�b�O�p

OBJECT Player; // �v���C���[�\����

void InitPlayer() // ������
{
    // �v���C���[�̏�����
    Player.PositionX = PLAYER_START_POSX; // �K���Ȓl
    Player.PositionY = PLAYER_START_POSY;
    Player.PositionXOld = Player.PositionX;
    Player.PositionYOld = Player.PositionY;

    Player.Mode = PLAYER_IDLE;
    Player.Use = true;

    Player.Width = 0.8f;
    Player.Height = 0.8f;

    std::cout << "Player initialized at (" << Player.PositionX << ", " << Player.PositionY << ")\n"; // �f�o�b�O�p
}

void FinalizePlayer() // �I������
{

}

void UpdatePlayer() // �X�V����
{
    if (Player.Use == true)
    {
        // �v���C���[�̏�Ԃ��Ƃ̏���
        switch (Player.Mode)
        {
        case PLAYER_IDLE:
            PlayerCheck();
            break;
        case PLAYER_MOVE:
            PlayerMove();
            break;
        case PLAYER_JUMP:
            // PlayerJump();
            break;
        }
    }

    // ��ʊO�`�F�b�N
    if ((int)Player.PositionX < SCREEN_LIMIT_LEFT)
    {
        Player.PositionX = SCREEN_LIMIT_LEFT; // ���W�̕␳
        Player.VelocityX = 0.0f;
    }
    else if ((int)Player.PositionX > SCREEN_LIMIT_RIGHT)
    {
        Player.PositionX = SCREEN_LIMIT_RIGHT; // ���W�̕␳
        Player.VelocityX = 0.0f;
    }
    if (Player.PositionY < SCREEN_LIMIT_UP)
    {
        Player.PositionY = SCREEN_LIMIT_UP; // ���W�̕␳
        Player.VelocityY = 0.0f;
    }
    else if (Player.PositionY > SCREEN_LIMIT_DOWN)
    {
        Player.PositionY = SCREEN_LIMIT_DOWN; // ���W�̕␳
        Player.VelocityY = 0.0f;
    }
}

void DrawPlayer() // �`��
{
    // �O��̃v���C���[������
    // ��ʂ̍��W��int�^�Ȃ̂ŁA�^�ϊ����s���ĕ\�����W��ݒ肷��
    gotoxy((int)Player.PositionXOld, (int)Player.PositionYOld);
    std::cout << " "; // �ݒ肵�����W�ɃX�y�[�X��\�����ď�������
    // �����̕\���F��ύX
    textcolor(RED); // ������ԂɕύX
    // ���݂̃v���C���[��\��
    gotoxy((int)Player.PositionX, (int)Player.PositionY);
    std::cout << "P"; // �Ƃ肠����P

    Player.PositionXOld = Player.PositionX; // ���݂̍��W��ۑ�
    Player.PositionYOld = Player.PositionY;
}

// �Î~��Ԕ���
void PlayerCheck()
{
    Player.VelocityX = 0; // �ړ��ʃ��Z�b�g
    Player.VelocityY = 0;

    // �L�[����
    // �����
    if (IsKeyRelease(PPK_W) || IsKeyRelease(PPK_UP))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionY -= 1.0f;
        std::cout << "Move up\n"; // �f�o�b�O�p
    }
    // ������
    else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX -= 1.0f;
        std::cout << "Move left\n"; // �f�o�b�O�p
    }
    // �E����
    else if (IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX += 1.0f;
        std::cout << "Move right\n"; // �f�o�b�O�p
    }
    // ������
    else if (IsKeyRelease(PPK_S) || IsKeyRelease(PPK_DOWN))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionY += 1.0f;
        std::cout << "Move down\n"; // �f�o�b�O�p
    }
    // ����������Ă��Ȃ�
    else
    {
        Player.Mode = PLAYER_IDLE;
    }
}

// ����
void PlayerMove()
{
    // �v���C���[�̃��[�h��IDLE�ɖ߂�
    Player.Mode = PLAYER_IDLE;
}

// �v���C���[�\���̂̎擾
OBJECT* GetPlayer()
{
    return &Player;
}
