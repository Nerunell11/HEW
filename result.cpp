
//result.cpp

#include	"result.h"

void	InitResult()
{
	//��ʂ̃N���A
	clrscr();
}
void	FinalizeResult()
{

}
void	UpdateResult()
{
	//�L�[���͑҂�
	if (IsKeyRelease(PPK_ENTER))
	{
		//�V�[���̐؂�ւ��i�^�C�g���֐؂�ւ���j
		SetScene(SCENE_TITLE);
	}
}
void	DrawResult()
{
	//�����̕\���F��ύX
	textcolor(WHITE);
	gotoxy(20, 18);
	std::cout << "���U���g�ł��@Press Enter Key";
}