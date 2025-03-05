#include "draw.h"


// �`�揈��
void DrawField()
{
    OBJECT* camera = GetCamera();
    float cameraLeft = camera->PositionX;
    float cameraRight = CAMERA_WIDTH;
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
                        for (int x = 0; x < field[i].Width; x++)
                        {
                            if (posx + x >= cameraLeft && posx + x <= cameraRight)
                            {
                                gotoxy((int)(posx + x), (int)(posy + y));
                                std::cout << "=";
                            }
                        }
                    }
                }
            }
        }
    }
}

void DrawPlayer() // �`��
{
    OBJECT* camera = GetCamera(); // �J�����̈ʒu���擾
    OBJECT* Player = GetPlayer(); // �v���C���[�̈ʒu���擾

    // �J�����͈͓̔��Ƀv���C���[�����邩�m�F
    int relativePosX = (int)(Player->PositionX - camera->PositionX);
    int relativePosY = (int)(Player->PositionY - camera->PositionY);
    int relativePosXOld = (int)(Player->PositionXOld - camera->PositionX);
    int relativePosYOld = (int)(Player->PositionYOld - camera->PositionY);

    if (relativePosX >= 0 && relativePosX < CAMERA_WIDTH && relativePosY >= 0 && relativePosY < CAMERA_HEIGHT)
    {
        // �O��̃v���C���[������
        gotoxy(relativePosXOld, relativePosYOld);
        std::cout << " "; // �ݒ肵�����W�ɃX�y�[�X��\�����ď�������

        // �����̕\���F��ύX
        textcolor(RED); // ������ԂɕύX

        // ���݂̃v���C���[��\��
        gotoxy(relativePosX, relativePosY);
        std::cout << "P"; // �Ƃ肠����P
    }

    Player->PositionXOld = Player->PositionX; // ���݂̍��W��ۑ�
    Player->PositionYOld = Player->PositionY;
}
