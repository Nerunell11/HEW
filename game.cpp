
//game.cpp

#include	"game.h"
#include	"Player.h"
#include	"field.h"
#include	"item.h"


void	InitGame()
{
	//画面のクリア
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

	//キー入力待ち
	if (IsKeyRelease(PPK_ENTER))
	{
		//シーンの切り替え（リザルトへ切り替える）
		SetScene(SCENE_RESULT);
	}
}
void	DrawGame()
{
	DrawField();
	DrawItem();
	DrawPlayer();

	//文字の表示色を変更
	textcolor(WHITE);
	gotoxy(30, 13);
	std::cout << "		ゲームです　Press Enter Key";
}

