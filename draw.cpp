#include "draw.h"

int ScrollY = 0; // スクロール量



// 描画初期化
void DrawInit()
{
    ScrollY = 0;
}



// 描画処理
void DrawField()
{


   
    OBJECT* camera = GetCamera(); // カメラの位置を取得
    OBJECT* field = GetField(); // フィールドの位置を取得

    for (int i = FIELD_MAX - 1; i >= 0; i--)
    {
        if (field[i].Use == true)
        {
            float posx = field[i].PositionX;
            float posy = field[i].PositionY;
            if ((posy >= 0 && posy <= 24) && (posx >= 0 && posx <= 79))
            {
                gotoxy((int)(posx), (int)(posy));

                switch (int(field[i].Width))
                {
                case 0:
					textcolor(WHITE);
                    break;
				case 1://壁
					textcolor(WHITE);
                    break;
                case 2:
                    textcolor(YELLOW);
                    break;
                default:
                    break;
                }

                
                std::cout << "=";
            }
           
        }
    }

   
    textcolor(WHITE);
}

void DrawPlayer() // 描画
{
    OBJECT* camera = GetCamera(); // カメラの位置を取得
    OBJECT* Player = GetPlayer(); // プレイヤーの位置を取得

 
    // 前回のプレイヤーを消去
    gotoxy(Player->PositionXOld, Player->PositionYOld);
    std::cout << " "; // 設定した座標にスペースを表示して消去する

    // 文字の表示色を変更
    textcolor(RED); // 文字を赤に変更

    // 現在のプレイヤーを表示
    gotoxy(Player->PositionX, Player->PositionY);
    std::cout << "P"; // とりあえずP
   
    Player->PositionXOld = Player->PositionX; // 現在の座標を保存
    Player->PositionYOld = Player->PositionY;
    
}

//Drawの中で変数をいじるな

void DrawScroll()
{
    //プレイヤーが三段登ったら呼び出す

    if (PlayerUpCount != 0 && PlayerUpCount % 3 == 0)
    {
		do
        {
			OBJECT* Player = GetPlayer(); // プレイヤーの位置を取得
			OBJECT* camera = GetCamera(); // カメラの位置を取得

            clrscr();

			//std::cout << "CameraMove\n";//デバッグ用
			ScrollY += 6;
			camera->PositionY -= 6.0f;
			Player->PositionY += 6.0f;

			DownField(6.0f);
			
			PlayerUpCount = 0;
		} while (PlayerUpCount!=0);
    }
}

//clrscr();
//std::cout << "CameraMove\n";
//ScrollY += 6;
