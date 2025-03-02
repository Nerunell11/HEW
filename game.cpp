#include "game.h"
#include "Player.h"
#include "field.h"
#include "camera.h"

void InitGame()
{
    // 画面のクリア
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

    // メッセージの表示
    textcolor(WHITE);
    gotoxy(30, 13);
    std::cout << "Game in progress. Press Enter Key";
}
