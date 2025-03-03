// Player.cpp

#include "Player.h"
#include "camera.h"
#include "common.h" // ���ʃw�b�_�t�@�C��
#include <iostream> // �f�o�b�O�p
#include"field.h"

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

    // �v���C���[�̑����ɑ��ꂪ���邩�m�F
    bool isOnPlatform = false;
    for (int i = 0; i < FIELD_MAX; i++)
    {
        if (field[i].Use)
        {
            float platformX = field[i].PositionX;
            float platformY = field[i].PositionY;
            float platformWidth = field[i].Width;
            float platformHeight = field[i].Height;

            if (Player.PositionX >= platformX && Player.PositionX <= platformX + platformWidth &&
                Player.PositionY + 1 == platformY)
            {
                isOnPlatform = true;
                break;
            }
        }
    }

    // ���ꂪ�Ȃ��ꍇ�̓Q�[���I�[�o�[
    if (!isOnPlatform)
    {
        SetScene(SCENE_GAMEOVER);
    }


	//�v���C���[���V�����Ȃ烊�U���g�V�[����
    if (Player.PositionY <= WORLD_LIMIT_UP)
    {
        SetScene(SCENE_RESULT);
        //�N���A�^�C���^�C�}�[��~
    }
}

void DrawPlayer() // �`��
{
    OBJECT* camera = GetCamera(); // �J�����̈ʒu���擾

    // �J�����͈͓̔��Ƀv���C���[�����邩�m�F
    int relativePosX = (int)(Player.PositionX - camera->PositionX);
    int relativePosY = (int)(Player.PositionY - camera->PositionY);
    int relativePosXOld = (int)(Player.PositionXOld - camera->PositionX);
    int relativePosYOld = (int)(Player.PositionYOld - camera->PositionY);

    if (relativePosX >= 0 && relativePosX < CAMERA_WIDTH && relativePosY >= 0 && relativePosY < CAMERA_HEIGHT)
    {
        // �O��̃v���C���[������
        gotoxy(relativePosXOld, relativePosYOld);
        std::cout << " "; // �ݒ肵�����W�ɃX�y�[�X��\�����ď�������

        // �����̕\���F��ύX
        textcolor(RED); // ������ԂɕύX

        // ���݂̃v���C���[��\��
        gotoxy(relativePosX, relativePosY);
        std::cout << "P"; // �Ƃ肠����P
    }

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
        Player.PositionY -= 2.0f;
        std::cout << "Move up\n"; // �f�o�b�O�p
    }
    // ������
    else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX -= 1.0f;
		Player.PositionY -= 2.0f;
        std::cout << "Move left\n"; // �f�o�b�O�p
    }
    // �E����
    else if (IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX += 1.0f;
		Player.PositionY -= 2.0f;
        std::cout << "Move right\n"; // �f�o�b�O�p
    }
    // ������
    else if (IsKeyRelease(PPK_S) || IsKeyRelease(PPK_DOWN))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionY += 2.0f;
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
