
//title.cpp

#include	"title.h"

static char soundfile[] = "asset\\popcorn1.mp3";

void	InitTitle()
{
	//��ʂ̃N���A
	clrscr();
	//�^�C�g���T�E���h
	StartSound(&soundfile[0], true);
}
void	FinalizeTitle()
{
	StopSound();
}
void	UpdateTitle()
{
	//�L�[���͑҂�
	if (IsKeyRelease(PPK_ENTER))
	{
		//�V�[���̐؂�ւ��i�Q�[���֐؂�ւ���j
		SetScene(SCENE_GAME);
	}

}
void	DrawTitle()
{
	//�����̕\���F��ύX
	textcolor(WHITE);
	gotoxy(35, 10);
	std::cout << "�o�ꂦ��������\n";
	gotoxy(35,12);
	std::cout << "Press Enter Key...\n";
}