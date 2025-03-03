//gameover.cpp
#include	"game.h"	//タイマー用
#include	"result.h"

void	InitGameOver()
{
	//画面のクリア
	clrscr();

}
void	FinalizeGameOver()
{

}
void	UpdateGameOver()
{
	//キー入力待ち
	if (IsKeyRelease(PPK_ENTER))
	{
		//シーンの切り替え（タイトルへ切り替える）
		SetScene(SCENE_TITLE);
	}
}
void	DrawGameOver()
{
	//文字の表示色を変更
	textcolor(WHITE);
	gotoxy(20, 18);
	std::cout << "GameOver!!　Press Enter Key";

	// 経過時間の表示
	gotoxy(20, 20);
	std::cout << "経過時間は" << elapsedTime.count() << "秒！！";
}