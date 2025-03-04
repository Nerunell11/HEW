
//title.cpp

#include	"title.h"

static char soundfile[] = "asset\\popcorn1.mp3";

void	InitTitle()
{
	//画面のクリア
	clrscr();
	//タイトルサウンド
	StartSound(&soundfile[0], true);
}
void	FinalizeTitle()
{
	StopSound();
}
void	UpdateTitle()
{
	//キー入力待ち
	if (IsKeyRelease(PPK_ENTER))
	{
		//シーンの切り替え（ゲームへ切り替える）
		SetScene(SCENE_GAME);
	}

}
void	DrawTitle()
{
	//文字の表示色を変更
	textcolor(WHITE);
	gotoxy(35, 10);
	std::cout << "登れえぇぇぇぇ\n";
	gotoxy(35,12);
	std::cout << "Press Enter Key...\n";
}