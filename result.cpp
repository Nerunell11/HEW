
//result.cpp
#include	"game.h"	//タイマー用
#include	"result.h"


static char soundfile[] = "asset\\popcorn3.mp3";

void	InitResult()
{
	//画面のクリア
	clrscr();

	// BGMの再生
	StartSound(&soundfile[0], true);

}
void	FinalizeResult()
{
	// BGMの停止
	StopSound();
}
void	UpdateResult()
{
	//キー入力待ち
	if (IsKeyRelease(PPK_ENTER))
	{
		//シーンの切り替え（タイトルへ切り替える）
		SetScene(SCENE_TITLE);
	}
}
void	DrawResult()
{
	//文字の表示色を変更
	textcolor(WHITE);
	gotoxy(20, 18);
	std::cout << "リザルトです　Press Enter Key";

	// 経過時間の表示
	gotoxy(20, 20);
	std::cout << "クリアタイムは" << elapsedTime.count() << "秒！！";
}