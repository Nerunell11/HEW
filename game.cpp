#include "game.h"
#include "Player.h"
#include "field.h"
#include "camera.h"

//�O���[�o���ϐ�
//�^�C�}�[
std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
std::chrono::duration<double> elapsedTime;

void InitGame()
{
    // ��ʂ̃N���A
    clrscr();

    // �^�C�}�[�̊J�n
    startTime = std::chrono::high_resolution_clock::now();
   

    InitPlayer();
    InitField();
    InitCamera();
}

void FinalizeGame()
{
    // �^�C�}�[�̒�~
    endTime = std::chrono::high_resolution_clock::now();
    elapsedTime = endTime - startTime;

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

}
