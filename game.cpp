
//game.cpp

#include	"game.h"
#include	"Player.h"
#include	"field.h"
#include	"camera.h"

void	InitGame()
{
	//画面のクリア
	clrscr();

	InitPlayer();
	InitField();
	InitCamera();


}
void	FinalizeGame()
{
	FinalizePlayer();
	FinalizeField();
	FinalizeCamera();

}
void	UpdateGame()
{

	UpdatePlayer();
	UpdateField();
	UpdateCamera();

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
	DrawPlayer();
	

	//文字の表示色を変更
	textcolor(WHITE);
	gotoxy(30, 13);
	std::cout << "		ゲームです　Press Enter Key";
}

