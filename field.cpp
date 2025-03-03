#include "camera.h"
#include "field.h"

// �t�B�[���h�\���̔z��
OBJECT field[FIELD_MAX];

// �t�B�[���h�z�u�e�[�u��
//
// ������W�@�@�T�C�Y
// Posx, PosY, Width, Height

// �t�B�[���h�񎟌��z��
float MapData[][4] =
{
   {WORLD_LIMIT_LEFT, WORLD_LIMIT_UP, 80, 1},   // �V��
   {WORLD_LIMIT_LEFT, WORLD_LIMIT_DOWN, 80, 1}, // �n��


   {WORLD_LIMIT_RIGHT, 1, 1, 24},               // �E��
   {WORLD_LIMIT_LEFT, 1, 1, 24},                // ����
    {-1, -1, -1, -1}                             // �f�[�^�̏I�[
};

// ������
void InitField()
{
    for (int i = 0; i < FIELD_MAX; i++)
    {
        field[i].Use = false;
    }

    // ������쐬
    int i = 0;
    while (MapData[i][0] != -1)
    {
        CreateField(MapData[i][0], MapData[i][1], MapData[i][2], MapData[i][3]);
        i++;
    }

    // �����_���Ƀt�B�[���h�v�f�𐶐�

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
    //    // �V��𒴂���ꍇ�͏I��
    //    if (WORLD_LIMIT_UP > RandomFieldY)
    //    {
    //        break;
    //    }
    //    // �����̃V�[�h��������
    //    std::srand(static_cast<unsigned int>(std::time(nullptr)));
    //    int random = 0;
    //    random = static_cast<float>((std::rand() % 3) + 1); // 1����3�͈̔͂Ń����_��

    //    float x = RandomFieldX;
    //    float y = RandomFieldY;
    //    float w = RandomFieldWidth;
    //    float h = RandomFieldHeight;

    //    CreateField(x, y, w, h);
    //}
}

// �I������
void FinalizeField()
{

}

// �X�V����
void UpdateField()
{

}

// �`�揈��
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

            // �J�����͈͓̔��ɂ���I�u�W�F�N�g�̂ݕ`��
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

// ����̍쐬
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
