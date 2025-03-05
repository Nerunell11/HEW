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

	// �����_���ȑ�����쐬

    int RandomFieldX = 39;
	int RandomFieldY = 24;
    int RandomFieldWidth = 1;
    int RandomFieldHeight = 1;



    while (1)
    {//�������ꂽ���ꂪ�V���荂���Ȃ�ꍇ�I��
        if (WORLD_LIMIT_UP > RandomFieldY)
        {
            break;
        }

        // �����������������
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 3);
		// 1�`3�̗����𐶐�
		int random = dis(gen);

        //��������
		switch (random)
        {
		    case 1://����ɐ���
		    {
				if (WORLD_LIMIT_LEFT < RandomFieldX-4)
				{
					RandomFieldX -= 4;
					RandomFieldY -= 2;
                    break;
				}
		    }

		    case 2://�E��ɐ���
            {
				if (WORLD_LIMIT_RIGHT > RandomFieldX + 4)
				{
					RandomFieldX += 4;
					RandomFieldY -= 2;
					break;
				}
              
            }
			case 3://�^��ɐ���
			{
				RandomFieldY -= 2;
			}

        }


        //�`��
        float x = RandomFieldX;
        float y = RandomFieldY;
        float w = RandomFieldWidth;
        float h = RandomFieldHeight;

        CreateField(x, y, w, h);
    }
}

// �I������
void FinalizeField()
{

}

// �X�V����
void UpdateField()
{

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
