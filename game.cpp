
//game.cpp

#include	"game.h"
#include	"Player.h"
#include	"field.h"
#include	"item.h"


void	InitGame()
{
	//��ʂ̃N���A
	clrscr();

	InitPlayer();
	InitField();
	InitItem();


}
void	FinalizeGame()
{
	FinalizePlayer();
	FinalizeField();
	FinalizeItem();

}
void	UpdateGame()
{

	UpdatePlayer();
	UpdateField();
	UpdateItem();

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
	DrawItem();
	DrawPlayer();

	//�����̕\���F��ύX
	textcolor(WHITE);
	gotoxy(30, 13);
	std::cout << "		�Q�[���ł��@Press Enter Key";
}

