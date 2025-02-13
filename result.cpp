
//result.cpp

#include	"result.h"

void	InitResult()
{
	//画面のクリア
	clrscr();
}
void	FinalizeResult()
{

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
}