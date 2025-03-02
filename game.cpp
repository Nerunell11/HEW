#include "game.h"
#include "Player.h"
#include "field.h"
#include "camera.h"

void InitGame()
{
    // ��ʂ̃N���A
    clrscr();

    InitPlayer();
    InitField();
    InitCamera();
}

void FinalizeGame()
{
    FinalizePlayer();
    FinalizeField();
    FinalizeCamera();
}

void UpdateGame()
{
    UpdatePlayer();
    UpdateCamera();
    UpdateField();
   
    // �L�[���͂̃`�F�b�N
    if (IsKeyRelease(PPK_ENTER))
    {
        // �V�[���̐؂�ւ��i���U���g�V�[���ցj
        SetScene(SCENE_RESULT);
    }
}

void DrawGame()
{
    DrawField();
    DrawPlayer();

    // ���b�Z�[�W�̕\��
    textcolor(WHITE);
    gotoxy(30, 13);
    std::cout << "Game in progress. Press Enter Key";
}
