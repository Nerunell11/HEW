
//game.cpp

#include	"game.h"
#include	"Player.h"
#include	"field.h"
#include	"camera.h"

void	InitGame()
{
	//��ʂ̃N���A
	clrscr();

	InitPlayer();
	InitField();
	InitCamera();


}
void	FinalizeGame()
{
	FinalizePlayer();
	FinalizeField();
	FinalizeCamera();

}
void	UpdateGame()
{

	UpdatePlayer();
	UpdateField();
	UpdateCamera();

	//�L�[���͑҂�
	if (IsKeyRelease(PPK_ENTER))
	{
		//�V�[���̐؂�ւ��i���U���g�֐؂�ւ���j
		SetScene(SCENE_RESULT);
	}
}
void	DrawGame()
{
	DrawField();
	DrawPlayer();
	

	//�����̕\���F��ύX
	textcolor(WHITE);
	gotoxy(30, 13);
	std::cout << "		�Q�[���ł��@Press Enter Key";
}

