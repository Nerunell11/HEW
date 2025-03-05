#include "draw.h"


// �`�揈��
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
                    // �V�䂪�`�悳��Ȃ��悤�ɂ���
                    if (posy + y < 0)
                    {
                        continue;
                    }

                    for (int x = 0; x < field[i].Width; x++)
                    {
                        gotoxy((int)(posx + x), (int)(posy + y));
                        std::cout << "=";
                    }
                }
            }
        }
}


void DrawPlayer() // �`��
{
    OBJECT* camera = GetCamera(); // �J�����̈ʒu���擾
    OBJECT* Player = GetPlayer(); // �v���C���[�̈ʒu���擾

 
        // �O��̃v���C���[������
        gotoxy(Player->PositionXOld, Player->PositionYOld);
        std::cout << " "; // �ݒ肵�����W�ɃX�y�[�X��\�����ď�������

        // �����̕\���F��ύX
        textcolor(RED); // ������ԂɕύX

        // ���݂̃v���C���[��\��
        gotoxy(Player->PositionX, Player->PositionY);
        std::cout << "P"; // �Ƃ肠����P
   
        Player->PositionXOld = Player->PositionX; // ���݂̍��W��ۑ�
        Player->PositionYOld = Player->PositionY;
    
}
