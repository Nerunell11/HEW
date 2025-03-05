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
   {WORLD_LIMIT_LEFT, WORLD_LIMIT_UP, 80, 1},   // 天井
   {WORLD_LIMIT_LEFT, WORLD_LIMIT_DOWN, 80, 1}, // 地面


   {WORLD_LIMIT_RIGHT, 1, 1, 24},               // 右壁
   {WORLD_LIMIT_LEFT, 1, 1, 24},                // 左壁
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
    while (MapData[i][0] != -1)
    {
        CreateField(MapData[i][0], MapData[i][1], MapData[i][2], MapData[i][3]);
        i++;
    }

	// ランダムな足場を作成

    int RandomFieldX = 39;
	int RandomFieldY = 24;
    int RandomFieldWidth = 1;
    int RandomFieldHeight = 1;



    while (1)
    {//生成された足場が天井より高くなる場合終了
        if (WORLD_LIMIT_UP > RandomFieldY)
        {
            break;
        }

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

OBJECT* GetField()
{
    return &field[0];
}
