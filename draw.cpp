#include "draw.h"

int ScrollY = 0; // �X�N���[����



// �`�揉����
void DrawInit()
{
    ScrollY = 0;
}



// �`�揈��
void DrawField()
{


   
    OBJECT* camera = GetCamera(); // �J�����̈ʒu���擾
    OBJECT* field = GetField(); // �t�B�[���h�̈ʒu���擾

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
				case 1://��
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

//Draw�̒��ŕϐ����������

void DrawScroll()
{
    //�v���C���[���O�i�o������Ăяo��

    if (PlayerUpCount != 0 && PlayerUpCount % 3 == 0)
    {
		do
        {
			OBJECT* Player = GetPlayer(); // �v���C���[�̈ʒu���擾
			OBJECT* camera = GetCamera(); // �J�����̈ʒu���擾

            clrscr();

			//std::cout << "CameraMove\n";//�f�o�b�O�p
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
