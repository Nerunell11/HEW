
//game.cpp

#include	"game.h"
#include	"Player.h"
#include	"field.h"

void	InitGame()
{
	//��ʂ̃N���A
	clrscr();

	InitPlayer();
	InitField();


}
void	FinalizeGame()
{
	FinalizePlayer();
	FinalizeField();

}
void	UpdateGame()
{

	UpdatePlayer();
	UpdateField();

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

