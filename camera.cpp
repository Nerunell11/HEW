#include "camera.h"

OBJECT camera; //カメラ構造体

void InitCamera()
{
    // カメラの初期位置
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
        // プレイヤーの位置を取得
        OBJECT* player = GetPlayer();

        // カメラの位置をプレイヤーの位置に合わせて更新
        camera.PositionX = player->PositionX - CAMERA_WIDTH / 2;
        camera.PositionY = player->PositionY - CAMERA_HEIGHT / 2;

        // カメラの位置を更新（X軸は固定）
        camera.PositionYOld = camera.PositionY;

        camera.VelocityY += camera.AccelerationY;
        camera.PositionY += camera.VelocityY;

        // 必要に応じてカメラの位置を制限するロジックを追加
        // 例: 画面の端を超えないようにする
    }
}

void DrawCamera()
{
    // カメラの描画処理を追加する場合はここに記述
}

void CameraCheck()
{
    camera.VelocityX = 0; // 移動量リセット
    camera.VelocityY = 0;

    // キー入力
    // 上方向
    if (IsKeyRelease(PPK_W) || IsKeyRelease(PPK_UP))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY -= 2.0f;
    }
    // 左方向
    else if (IsKeyRelease(PPK_A) || IsKeyRelease(PPK_LEFT))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY -= 2.0f;
    }
    // 右方向
    else if (IsKeyRelease(PPK_D) || IsKeyRelease(PPK_RIGHT))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY -= 2.0f;
    }
    // 下方向
    else if (IsKeyRelease(PPK_S) || IsKeyRelease(PPK_DOWN))
    {
        camera.Mode = CAMERA_MOVE;
        camera.PositionY += 2.0f;
        std::cout << "Move down\n"; // デバッグ用
    }
    // 何も押されていない
    else
    {
        camera.Mode = CAMERA_IDLE;
    }
}

void CameraMove()
{
    // カメラのモードをIDLEに戻す
    camera.Mode = CAMERA_IDLE;
}

OBJECT* GetCamera()
{
    return &camera;
}
