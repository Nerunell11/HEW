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
   //{WORLD_LIMIT_LEFT, WORLD_LIMIT_UP, 80, 1},   // �V��
   //{WORLD_LIMIT_LEFT, WORLD_LIMIT_DOWN, 80, 1}, // �n��

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

    for (int x = 0; x < 80; x++)
    {

        //�V��
        CreateField(x, WORLD_LIMIT_UP, 2, 1);

        //��
        CreateField(x, WORLD_LIMIT_DOWN, 0, 1);
    }

    for (int y = 0; y <WORLD_LIMIT_HEIGHT; y++)
    {
		//����
        CreateField(WORLD_LIMIT_LEFT, 24-y, 1, 1);
       
		//�E��
        CreateField(WORLD_LIMIT_RIGHT, 24-y, 1, 1);
    }
  

	// �����_���ȑ�����쐬

    int RandomFieldX = 39;
	int RandomFieldY = WORLD_LIMIT_DOWN;
    int RandomFieldWidth = 0;
    int RandomFieldHeight = 1;



    while (1)
    {//�������ꂽ���ꂪ�V���荂���Ȃ�ꍇ�I��
        

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

        if (WORLD_LIMIT_UP > RandomFieldY)
        {
            break;
        }

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
