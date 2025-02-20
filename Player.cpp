// Player.cpp

#include "Player.h"
#include "common.h" // 共通ヘッダファイル
#include <iostream> // デバッグ用

OBJECT Player; // プレイヤー構造体

void InitPlayer() // 初期化
{
    // プレイヤーの初期化
    Player.PositionX = PLAYER_START_POSX; // 適当な値
    Player.PositionY = PLAYER_START_POSY;
    Player.PositionXOld = Player.PositionX;
    Player.PositionYOld = Player.PositionY;

    Player.Mode = PLAYER_IDLE;
    Player.Use = true;

    Player.Width = 0.8f;
    Player.Height = 0.8f;

    std::cout << "Player initialized at (" << Player.PositionX << ", " << Player.PositionY << ")\n"; // デバッグ用
}

void FinalizePlayer() // 終了処理
{

}

void UpdatePlayer() // 更新処理
{
    if (Player.Use == true)
    {
        // プレイヤーの状態ごとの処理
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

    // 画面外チェック
    if ((int)Player.PositionX < SCREEN_LIMIT_LEFT)
    {
        Player.PositionX = SCREEN_LIMIT_LEFT; // 座標の補正
        Player.VelocityX = 0.0f;
    }
    else if ((int)Player.PositionX > SCREEN_LIMIT_RIGHT)
    {
        Player.PositionX = SCREEN_LIMIT_RIGHT; // 座標の補正
        Player.VelocityX = 0.0f;
    }
    if (Player.PositionY < SCREEN_LIMIT_UP)
    {
        Player.PositionY = SCREEN_LIMIT_UP; // 座標の補正
        Player.VelocityY = 0.0f;
    }
    else if (Player.PositionY > SCREEN_LIMIT_DOWN)
    {
        Player.PositionY = SCREEN_LIMIT_DOWN; // 座標の補正
        Player.VelocityY = 0.0f;
    }
}

void DrawPlayer() // 描画
{
    // 前回のプレイヤーを消去
    // 画面の座標はint型なので、型変換を行って表示座標を設定する
    gotoxy((int)Player.PositionXOld, (int)Player.PositionYOld);
    std::cout << " "; // 設定した座標にスペースを表示して消去する
    // 文字の表示色を変更
    textcolor(RED); // 文字を赤に変更
    // 現在のプレイヤーを表示
    gotoxy((int)Player.PositionX, (int)Player.PositionY);
    std::cout << "P"; // とりあえずP

    Player.PositionXOld = Player.PositionX; // 現在の座標を保存
    Player.PositionYOld = Player.PositionY;
}

// 静止状態判定
void PlayerCheck()
{
    Player.VelocityX = 0; // 移動量リセット
    Player.VelocityY = 0;

    // キー入力
    // 上方向
    if (IsKeyRelease(PPK_W) || IsKeyRelease(PPK_UP))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionY -= 1.0f;
        std::cout << "Move up\n"; // デバッグ用
    }
    // 左方向
    else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX -= 1.0f;
        std::cout << "Move left\n"; // デバッグ用
    }
    // 右方向
    else if (IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX += 1.0f;
        std::cout << "Move right\n"; // デバッグ用
    }
    // 下方向
    else if (IsKeyRelease(PPK_S) || IsKeyRelease(PPK_DOWN))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionY += 1.0f;
        std::cout << "Move down\n"; // デバッグ用
    }
    // 何も押されていない
    else
    {
        Player.Mode = PLAYER_IDLE;
    }
}

// 動作
void PlayerMove()
{
    // プレイヤーのモードをIDLEに戻す
    Player.Mode = PLAYER_IDLE;
}

// プレイヤー構造体の取得
OBJECT* GetPlayer()
{
    return &Player;
}
