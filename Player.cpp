// Player.cpp

#include "Player.h"
#include "camera.h"
#include "common.h" // 共通ヘッダファイル
#include <iostream> // デバッグ用

OBJECT Player; // プレイヤー構造体


int PlayerUpCount = 0; //プレイヤーが上昇した回数

int PlayerUptime = 0; //プレイヤーが登った段




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

    PlayerUpCount = 0;
    PlayerUptime = 0;
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
            break;
        }
    }


    // 画面外チェック
    if ((int)Player.PositionX < WORLD_LIMIT_LEFT)
    {
        Player.PositionX = WORLD_LIMIT_LEFT; // 座標の補正
        Player.VelocityX = 0.0f;
    }
    else if ((int)Player.PositionX > WORLD_LIMIT_RIGHT)
    {
        Player.PositionX = WORLD_LIMIT_RIGHT; // 座標の補正
        Player.VelocityX = 0.0f;
    }
    if (Player.PositionY < WORLD_LIMIT_UP)
    {
        Player.PositionY = WORLD_LIMIT_UP; // 座標の補正
        Player.VelocityY = 0.0f;
    }
    else if (Player.PositionY > WORLD_LIMIT_DOWN)
    {
        Player.PositionY = WORLD_LIMIT_DOWN; // 座標の補正
        Player.VelocityY = 0.0f;
    }

    // プレイヤーの足元に足場があるか確認
    bool isOnPlatform = false;
    for (int i = 0; i < FIELD_MAX; i++)
    {
        if (field[i].Use)
        {
            float platformX = field[i].PositionX;
            float platformY = field[i].PositionY;

            if (Player.PositionX== platformX &&Player.PositionY + 1 == platformY)
            {
                isOnPlatform = true;
                break;
            }
        }
    }

    // 足場がない場合はゲームオーバー
    if (!isOnPlatform)
    {
        SetScene(SCENE_GAMEOVER);
    }


	//プレイヤーが天井より上ならリザルトシーンへ
    if (PlayerUptime>=WORLD_LIMIT_HEIGHT)
    {
        SetScene(SCENE_RESULT);
        //クリアタイムタイマー停止
    }

    //std::cout << "Player initialized at (" << Player.PositionX << ", " << Player.PositionY << ")\n"; // デバッグ用

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
        Player.PositionY -= 2.0f;
        //std::cout << "Move up\n"; // デバッグ用
		PlayerUpCount++;
        PlayerUptime += 2;
    }
    // 左方向
    else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX -= 4.0f;
		Player.PositionY -= 2.0f;
        //std::cout << "Move left\n"; // デバッグ用
        PlayerUpCount++;
        PlayerUptime += 2;
    }
    // 右方向
    else if (IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
    {
        Player.Mode = PLAYER_MOVE;
        Player.PositionX += 4.0f;
		Player.PositionY -= 2.0f;
        //std::cout << "Move right\n"; // デバッグ用
        PlayerUpCount++;
        PlayerUptime += 2;
    }
    // 下方向
    else if (IsKeyRelease(PPK_S) || IsKeyRelease(PPK_DOWN))
    {
        //Player.Mode = PLAYER_MOVE;
        //Player.PositionY += 2.0f;
        //std::cout << "Move down\n"; // デバッグ用
       /* PlayerUpCount--;
        PlayerUptime -= 2;*/
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
