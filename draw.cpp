#include "draw.h"

int ScrollY = 0; // スクロール量

// 描画処理
void DrawField()
{
        for (int i = FIELD_MAX - 1; i >= 0; i--)
        {
            if (field[i].Use == true)
            {
                float posx = field[i].PositionX;
                float posy = field[i].PositionY;
                

                for (int y = field[i].Height - 1; y >= 0; y--)
                {
                    // 天井が描画されないようにする
                    if (posy + y < 0)
                    {
                        continue;
                    }

                    for (int x = 0; x < field[i].Width; x++)
                    {
                        gotoxy((int)(posx + x), (int)(posy + y + ScrollY));
                        std::cout << "=";
                    }
                }
            }
        }

}

void DrawPlayer() // 描画
{
    OBJECT* camera = GetCamera(); // カメラの位置を取得
    OBJECT* Player = GetPlayer(); // プレイヤーの位置を取得

 
        // 前回のプレイヤーを消去
        gotoxy(Player->PositionXOld, Player->PositionYOld+ScrollY);
        std::cout << " "; // 設定した座標にスペースを表示して消去する

        // 文字の表示色を変更
        textcolor(RED); // 文字を赤に変更

        // 現在のプレイヤーを表示
        gotoxy(Player->PositionX, Player->PositionY+ScrollY);
        std::cout << "P"; // とりあえずP
   
        Player->PositionXOld = Player->PositionX; // 現在の座標を保存
        Player->PositionYOld = Player->PositionY;
    
}

void DrawScroll()
{
    //プレイヤーが三段登ったら呼び出す

    if (PlayerUpCount != 0 && PlayerUpCount % 3 == 0)
    {
		do
        {
            clrscr();
			std::cout << "CameraMove\n";//デバッグ用
			ScrollY += 6;
			PlayerUpCount = 0;
		} while (PlayerUpCount!=0);
    }
}

//clrscr();
//std::cout << "CameraMove\n";
//ScrollY += 6;
