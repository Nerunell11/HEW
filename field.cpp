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

    // ランダムにフィールド要素を生成

    //int RandomFieldX = (SCREEN_LIMIT_RIGHT / 2);
    //int RandomFieldY = (WORLD_LIMIT_DOWN - 3);
    //int RandomFieldWidth = 1;
    //int RandomFieldHeight = 1;

    //int RandomFieldXOld = RandomFieldX;
    //int RandomFieldYOld = RandomFieldY;
    //int RandomFieldWidthOld = RandomFieldWidth;
    //int RandomFieldHeightOld = RandomFieldHeight;

    //for (int k = 0; k < WORLD_LIMIT_DOWN / 3; k++) // =
    //{
    //    // 天井を超える場合は終了
    //    if (WORLD_LIMIT_UP > RandomFieldY)
    //    {
    //        break;
    //    }
    //    // 乱数のシードを初期化
    //    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //    int random = 0;
    //    random = static_cast<float>((std::rand() % 3) + 1); // 1から3の範囲でランダム

    //    float x = RandomFieldX;
    //    float y = RandomFieldY;
    //    float w = RandomFieldWidth;
    //    float h = RandomFieldHeight;

    //    CreateField(x, y, w, h);
    //}
}

// 終了処理
void FinalizeField()
{

}

// 更新処理
void UpdateField()
{

}

// 描画処理
void DrawField()
{
    OBJECT* camera = GetCamera();
    float cameraLeft = camera->PositionX;
    float cameraRight = camera->PositionX + CAMERA_WIDTH;
    float cameraTop = camera->PositionY;
    float cameraBottom = camera->PositionY + CAMERA_HEIGHT;

    for (int i = 0; i < FIELD_MAX; i++)
    {
        if (field[i].Use == true)
        {
            float posx = field[i].PositionX;
            float posy = field[i].PositionY;

            // カメラの範囲内にあるオブジェクトのみ描画
            if (posx + field[i].Width >= cameraLeft && posx <= cameraRight &&
                posy + field[i].Height >= cameraTop && posy <= cameraBottom)
            {
                for (int y = 0; y < field[i].Height; y++)
                {
                    if (posy + y >= cameraTop && posy + y <= cameraBottom)
                    {
                        gotoxy((int)posx, (int)(posy + y));
                        for (int x = 0; x < field[i].Width; x++)
                        {
                            if (posx + x >= cameraLeft && posx + x <= cameraRight)
                            {
                                std::cout << "=";
                            }
                        }
                    }
                }
            }
        }
    }
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
