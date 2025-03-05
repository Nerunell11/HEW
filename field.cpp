#include "camera.h"
#include "field.h"

// フィールド構造体配列
OBJECT field[FIELD_MAX];

// フィールド配置テーブル
//
// 左上座標　　サイズ
// Posx, PosY, Width, Height

// フィールド二次元配列
float MapData[][4] =
{
   //{WORLD_LIMIT_LEFT, WORLD_LIMIT_UP, 80, 1},   // 天井
   //{WORLD_LIMIT_LEFT, WORLD_LIMIT_DOWN, 80, 1}, // 地面

   {-1, -1, -1, -1}                             // データの終端
};

// 初期化
void InitField()
{
    for (int i = 0; i < FIELD_MAX; i++)
    {
        field[i].Use = false;
    }

    // 足場を作成
    int i = 0;

    for (int x = 0; x < 80; x++)
    {

        //天井
        CreateField(x, WORLD_LIMIT_UP, 2, 1);

        //床
        CreateField(x, WORLD_LIMIT_DOWN, 0, 1);
    }

    for (int y = 0; y <WORLD_LIMIT_HEIGHT; y++)
    {
		//左壁
        CreateField(WORLD_LIMIT_LEFT, 24-y, 1, 1);
       
		//右壁
        CreateField(WORLD_LIMIT_RIGHT, 24-y, 1, 1);
    }
  

	// ランダムな足場を作成

    int RandomFieldX = 39;
	int RandomFieldY = WORLD_LIMIT_DOWN;
    int RandomFieldWidth = 0;
    int RandomFieldHeight = 1;



    while (1)
    {//生成された足場が天井より高くなる場合終了
        

        // 乱数生成器を初期化
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 3);
		// 1～3の乱数を生成
		int random = dis(gen);

        //条件分岐
		switch (random)
        {
		    case 1://左上に生成
		    {
				if (WORLD_LIMIT_LEFT < RandomFieldX-4)
				{
					RandomFieldX -= 4;
					RandomFieldY -= 2;
                    break;
				}
		    }

		    case 2://右上に生成
            {
				if (WORLD_LIMIT_RIGHT > RandomFieldX + 4)
				{
					RandomFieldX += 4;
					RandomFieldY -= 2;
					break;
				}
              
            }
			case 3://真上に生成
			{
				RandomFieldY -= 2;
			}

        }


        //描画
        float x = RandomFieldX;
        float y = RandomFieldY;
        float w = RandomFieldWidth;
        float h = RandomFieldHeight;

        if (WORLD_LIMIT_UP > RandomFieldY)
        {
            break;
        }

        CreateField(x, y, w, h);
    }
}

// 終了処理
void FinalizeField()
{

}

// 更新処理
void UpdateField()
{

}


// 足場の作成
void CreateField(float x, float y, float w, float h)
{
    for (int i = 0; i < FIELD_MAX; i++)
    {
        if (field[i].Use == false)
        {
           
            field[i].Use = true;
            field[i].PositionX = x;
            field[i].PositionY = y;
            field[i].Width = w;
            field[i].Height = h;
            break;
        }
    }
}

void DownField(float y)
{
    for (int i = 0; i < FIELD_MAX; i++)
    {
        if (field[i].Use == true)
        {
            field[i].PositionY += y;
        }
    }
}


OBJECT* GetField()
{
    return &field[0];
}
