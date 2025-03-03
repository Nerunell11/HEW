#include "game.h"
#include "Player.h"
#include "field.h"
#include "camera.h"

//グローバル変数
//タイマー
std::chrono::time_point<std::chrono::high_resolution_clock> startTime;
std::chrono::time_point<std::chrono::high_resolution_clock> endTime;
std::chrono::duration<double> elapsedTime;

void InitGame()
{
    // 画面のクリア
    clrscr();

    // タイマーの開始
    startTime = std::chrono::high_resolution_clock::now();
   

    InitPlayer();
    InitField();
    InitCamera();
}

void FinalizeGame()
{
    // タイマーの停止
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
  
    // キー入力のチェック
    if (IsKeyRelease(PPK_ENTER))
    {
        // シーンの切り替え（リザルトシーンへ）
        SetScene(SCENE_RESULT);
    }
    
}

void DrawGame()
{
    DrawField();
    DrawPlayer();

}
