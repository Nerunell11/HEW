//gameover.cpp
#include	"game.h"	//�^�C�}�[�p
#include	"result.h"

void	InitGameOver()
{
	//��ʂ̃N���A
	clrscr();

}
void	FinalizeGameOver()
{

}
void	UpdateGameOver()
{
	//�L�[���͑҂�
	if (IsKeyRelease(PPK_ENTER))
	{
		//�V�[���̐؂�ւ��i�^�C�g���֐؂�ւ���j
		SetScene(SCENE_TITLE);
	}
}
void	DrawGameOver()
{
	//�����̕\���F��ύX
	textcolor(WHITE);
	gotoxy(20, 18);
	std::cout << "GameOver!!�@Press Enter Key";

	// �o�ߎ��Ԃ̕\��
	gotoxy(20, 20);
	std::cout << "�o�ߎ��Ԃ�" << elapsedTime.count() << "�b�I�I";
}