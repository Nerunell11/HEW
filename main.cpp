
#include	"common.h"	//共通事項　必ずインクルードする

#include	"player.h"

#include	"title.h"
#include	"game.h"
#include	"result.h"
#include	"gameover.h"
//==================================================
//Libraryフォルダーをmain.cppと同じフォルダ階層へコピーした後
//自分のmain.cppへここを追加
//==================================================
#ifndef _DEBUG
#pragma comment(lib, "./Library/Release/HEW.lib")
#else
#pragma comment(lib, "./Library/Debug/HEW.lib")
#endif


DWORD dwMode_default;  // コンソールのデフォルト状態を保持する変数

// Function prototype declarations
// 
bool HEWStartup();
bool HEWCleanup();
//===============ここまで===============================

//*****************************************************************************
//	マクロ定義
//*****************************************************************************

#define DEBUG_TIMER (500)	// デバッグ表示の間隔 500ms
#define WINDOWPOS_X (275)	// ウィンドウの初期位置
#define WINDOWPOS_Y (100)	// ウィンドウの初期位置

//*****************************************************************************
//	プロトタイプ宣言
//*****************************************************************************
void WindowConsoleInitialize(void);		// ウィンドウ情報の初期化

//#ifdef _DEBUG	//_DEBUGが定義されている場合（debugモード時）

	void DispFPS(void);	// デバッグ時のみ有効な関数扱いとなる

//#endif

void	Init();
void	Uninit();
void	Update();
void	Draw();

//*****************************************************************************
//	グローバル変数
//*****************************************************************************
int g_fpsCounter;				// FPSカウンタ

GAMESCENE	g_Scene = SCENE_NONE;		//現在のシーン
GAMESCENE	g_SceneNext = SCENE_TITLE;	//遷移先のシーン


//=============================================================================
//	メイン関数
//=============================================================================
int main(void)
{
	int execLastTime;	// ゲーム処理をした時間（タイマー値）
	int fpsLastTime;	// デバッグ表示をした時間（タイマー値）
	int currentTime;	// 現在の時間（タイマー値）
	int frameCount;		// ゲームの処理をした回数

	setcaption((char*)"AT11A241_08_岩下稔");	//クラス_出席番号_氏名 にしよう

	// タイマー分解能を高精度に設定
	// 1/1000秒ごとに1ずつ増えるタイマーを使える（時刻ではない）
	timeBeginPeriod(1);

	execLastTime =
		fpsLastTime = timeGetTime();	// 現在のタイマー値取得

	srand((UINT)execLastTime);	//乱数初期化

	// 変数を0に初期化
	currentTime =
		frameCount = 0;

	// ウィンドウ情報の初期化
	HEWStartup();

	// カーソル表示ＯＦＦ
	setcursortype(NOCURSOR);


	//==========================
	// この辺で初期化処理を行う
	//==========================

	InitKey();		//キー処理の初期化

	// ここからゲームループ
	do
	{
		currentTime = timeGetTime();	// 現在のタイマー値

		//デバッグ用FPS表示　0.5秒に一回更新する
		if ((currentTime - fpsLastTime) >= DEBUG_TIMER)
		{//処理回数と経過時間から１秒間に南海ループ出来るかを計算
			g_fpsCounter = frameCount * 1000 / (currentTime - fpsLastTime);
			fpsLastTime = currentTime;	//表示した時間を保存
			frameCount = 0;				//ゲームループカウントリセット
		}

		//前回ゲーム処理を行った時間と、現在の時間の差が
		// 1/60秒（約16.7ミリ秒）以上になったら処理を行う
		// FPSはだいたい60になる
		if ((currentTime - execLastTime) >= (1000 / 60))//コメントにするとPCの本気が見られる
		{
			execLastTime = currentTime;//ゲーム処理実行時間を保存

			//初期化
			Init();
			//更新処理
			Update();
			//描画処理
			Draw();
			//サウンド
			UpdateSound();
			//終了処理
			//Uninit();

			//処理回数カウンター
			frameCount++;
			// デバッグ時のみ関数が呼ばれる
			
//#ifdef _DEBUG
			DispFPS();
//#endif
		}
	} while (!inport(PK_ESC)); // ESC押すまでループ

	// カーソル表示ＯＮ
	setcursortype(NORMALCURSOR);

	// タイマー分解能を戻す
	timeEndPeriod(1);

	HEWCleanup();
	return 0;
}

// =============================================================================
// ウィンドウ設定の初期化（HEW用設定）
// =============================================================================
void WindowConsoleInitialize(void)
{
	// Set console window position
	HWND consoleWindow = GetConsoleWindow();
	int x, y;
	x = WINDOWPOS_X;
	y = WINDOWPOS_Y;
	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// Set console window size
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

	// Set console buffer size
	// ウィンドウサイズは80, 25で固定すること
	COORD coord;
	coord.X = 80;
	coord.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	// Set console font style and size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	// ↓フォントサイズのみ変更可↓//////////////////////////
	cfi.dwFontSize.X = 12;						// Width of each character in the font
	cfi.dwFontSize.Y = 24;						// Height
	// ↑フォントサイズのみ変更可↑/////////////////////////
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"MS Gothic");       // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

// =============================================================================
//初期化
// =============================================================================
void	Init()
{

	if (g_Scene != g_SceneNext)	//シーン遷移のリクエストチェック
	{
		Uninit();				//現在のシーンを終了

		g_Scene = g_SceneNext;	//シーンの切り替え

		switch (g_Scene)		//現在のシーンの初期化
		{
			case SCENE_TITLE:
				InitTitle();	break;
			case SCENE_GAME:
				InitGame();		break;
			case SCENE_GAMEOVER:
				InitGameOver();	break;
			case SCENE_RESULT:
				InitResult();	break;
		}
		
	}


}

// =============================================================================
//　終了
// =============================================================================
void	Uninit()
{
	switch (g_Scene)	//現在のシーンを終了
	{
		case SCENE_TITLE:
			FinalizeTitle();	break;
		case SCENE_GAME:
			FinalizeGame();		break;
		case SCENE_GAMEOVER:
			FinalizeGameOver();	break;
		case SCENE_RESULT:
			FinalizeResult();	break;
	}

}

// =============================================================================
//更新
// =============================================================================
void	Update()
{

	UpdateKey();	//キー情報を作成する

	switch (g_Scene)	//現在のシーンを終了
	{
		case SCENE_TITLE:
			UpdateTitle();	break;
		case SCENE_GAME:
			UpdateGame();	break;
		case SCENE_GAMEOVER:
			UpdateGameOver();	break;
		case SCENE_RESULT:
			UpdateResult();	break;
	}

}

// =============================================================================
//表示
// =============================================================================
void	Draw()
{
	switch (g_Scene)	//現在のシーンを終了
	{
		case SCENE_TITLE:
			DrawTitle();	break;
		case SCENE_GAME:
			DrawGame();		break;
		case SCENE_GAMEOVER:
			DrawGameOver();	break;
		case SCENE_RESULT:
			DrawResult();	break;
	}
	//文字の色を戻す
	textcolor(WHITE);

}

//シーンの切り替え
void	SetScene(GAMESCENE scene)
{
	g_SceneNext = scene;
}


//シーンの取得
GAMESCENE GetScene()
{
	return g_Scene;
}

//#ifdef _DEBUG
// =============================================================================
// デバッグ表示
// =============================================================================
void DispFPS(void)
{
	// 色設定
	textcolor(LIGHTCYAN);

	gotoxy(1, 1);	// 表示位置設定
	std::cout << "FPS:" << g_fpsCounter;	// FPS値表示

	// 色設定(もとに戻す)
	textcolor(WHITE);
}
//#endif
