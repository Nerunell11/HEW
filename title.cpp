
//title.cpp

#include	"title.h"

static char soundfile[] = "asset\\bgm.mp3";

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
	gotoxy(50, 10);
	std::cout << "タイトルです　Press Enter Key";
}