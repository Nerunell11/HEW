#include "draw.h"


// 描画処理
void DrawField()
{
    OBJECT* camera = GetCamera();
    float cameraLeft = camera->PositionX;
    float cameraRight = CAMERA_WIDTH;
    float cameraTop = camera->PositionY;
    float cameraBottom = camera->PositionY + CAMERA_HEIGHT;

    for (int i = 0; i < FIELD_MAX; i++)
    {
        if (field[i].Use == true)
        {
            float posx = field[i].PositionX;
            float posy = field[i].PositionY;

            // カメラの範囲内にあるオブジェクトのみ描画
            if (posx + field[i].Width >= cameraLeft && posx <= cameraRight &&
                posy + field[i].Height >= cameraTop && posy <= cameraBottom)
            {
                for (int y = 0; y < field[i].Height; y++)
                {
                    if (posy + y >= cameraTop && posy + y <= cameraBottom)
                    {
                        for (int x = 0; x < field[i].Width; x++)
                        {
                            if (posx + x >= cameraLeft && posx + x <= cameraRight)
                            {
                                gotoxy((int)(posx + x), (int)(posy + y));
                                std::cout << "=";
                            }
                        }
                    }
                }
            }
        }
    }
}

void DrawPlayer() // 描画
{
    OBJECT* camera = GetCamera(); // カメラの位置を取得
    OBJECT* Player = GetPlayer(); // プレイヤーの位置を取得

    // カメラの範囲内にプレイヤーがいるか確認
    int relativePosX = (int)(Player->PositionX - camera->PositionX);
    int relativePosY = (int)(Player->PositionY - camera->PositionY);
    int relativePosXOld = (int)(Player->PositionXOld - camera->PositionX);
    int relativePosYOld = (int)(Player->PositionYOld - camera->PositionY);

    if (relativePosX >= 0 && relativePosX < CAMERA_WIDTH && relativePosY >= 0 && relativePosY < CAMERA_HEIGHT)
    {
        // 前回のプレイヤーを消去
        gotoxy(relativePosXOld, relativePosYOld);
        std::cout << " "; // 設定した座標にスペースを表示して消去する

        // 文字の表示色を変更
        textcolor(RED); // 文字を赤に変更

        // 現在のプレイヤーを表示
        gotoxy(relativePosX, relativePosY);
        std::cout << "P"; // とりあえずP
    }

    Player->PositionXOld = Player->PositionX; // 現在の座標を保存
    Player->PositionYOld = Player->PositionY;
}
