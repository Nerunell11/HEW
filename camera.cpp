//camera.cpp

#include "camera.h"

OBJECT camera;

void InitCamera()
{
	//�J�����̏����ʒu
	camera.PositionX = CAMERA_START_POSX;
	camera.PositionY = CAMERA_START_POSY;
	camera.PositionXOld = camera.PositionX;
	camera.PositionYOld = camera.PositionY;

}


void	FinalizeCamera()
{

}


void	UpdateCamera()
{

}

OBJECT* GetCamera()
{
	return &camera;
}
