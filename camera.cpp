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
   
}



void CameraCheck()
{//プレイヤーが三段登ったら呼び出す

    camera.Mode = CAMERA_MOVE;
    camera.PositionY -= 6.0f;


    camera.Mode = CAMERA_IDLE;
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
