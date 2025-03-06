
#include	"common.h"	//���ʎ����@�K���C���N���[�h����

#include	"player.h"

#include	"title.h"
#include	"game.h"
#include	"result.h"
#include	"gameover.h"
//==================================================
//Library�t�H���_�[��main.cpp�Ɠ����t�H���_�K�w�փR�s�[������
//������main.cpp�ւ�����ǉ�
//==================================================
#ifndef _DEBUG
#pragma comment(lib, "./Library/Release/HEW.lib")
#else
#pragma comment(lib, "./Library/Debug/HEW.lib")
#endif


DWORD dwMode_default;  // �R���\�[���̃f�t�H���g��Ԃ�ێ�����ϐ�

// Function prototype declarations
// 
bool HEWStartup();
bool HEWCleanup();
//===============�����܂�===============================

//*****************************************************************************
//	�}�N����`
//*****************************************************************************

#define DEBUG_TIMER (500)	// �f�o�b�O�\���̊Ԋu 500ms
#define WINDOWPOS_X (275)	// �E�B���h�E�̏����ʒu
#define WINDOWPOS_Y (100)	// �E�B���h�E�̏����ʒu

//*****************************************************************************
//	�v���g�^�C�v�錾
//*****************************************************************************
void WindowConsoleInitialize(void);		// �E�B���h�E���̏�����

//#ifdef _DEBUG	//_DEBUG����`����Ă���ꍇ�idebug���[�h���j

	void DispFPS(void);	// �f�o�b�O���̂ݗL���Ȋ֐������ƂȂ�

//#endif

void	Init();
void	Uninit();
void	Update();
void	Draw();

//*****************************************************************************
//	�O���[�o���ϐ�
//*****************************************************************************
int g_fpsCounter;				// FPS�J�E���^

GAMESCENE	g_Scene = SCENE_NONE;		//���݂̃V�[��
GAMESCENE	g_SceneNext = SCENE_TITLE;	//�J�ڐ�̃V�[��


//=============================================================================
//	���C���֐�
//=============================================================================
int main(void)
{
	int execLastTime;	// �Q�[���������������ԁi�^�C�}�[�l�j
	int fpsLastTime;	// �f�o�b�O�\�����������ԁi�^�C�}�[�l�j
	int currentTime;	// ���݂̎��ԁi�^�C�}�[�l�j
	int frameCount;		// �Q�[���̏�����������

	setcaption((char*)"AT11A241_08_�≺��");	//�N���X_�o�Ȕԍ�_���� �ɂ��悤

	// �^�C�}�[����\�������x�ɐݒ�
	// 1/1000�b���Ƃ�1��������^�C�}�[���g����i�����ł͂Ȃ��j
	timeBeginPeriod(1);

	execLastTime =
		fpsLastTime = timeGetTime();	// ���݂̃^�C�}�[�l�擾

	srand((UINT)execLastTime);	//����������

	// �ϐ���0�ɏ�����
	currentTime =
		frameCount = 0;

	// �E�B���h�E���̏�����
	HEWStartup();

	// �J�[�\���\���n�e�e
	setcursortype(NOCURSOR);


	//==========================
	// ���̕ӂŏ������������s��
	//==========================

	InitKey();		//�L�[�����̏�����

	// ��������Q�[�����[�v
	do
	{
		currentTime = timeGetTime();	// ���݂̃^�C�}�[�l

		//�f�o�b�O�pFPS�\���@0.5�b�Ɉ��X�V����
		if ((currentTime - fpsLastTime) >= DEBUG_TIMER)
		{//�����񐔂ƌo�ߎ��Ԃ���P�b�Ԃɓ�C���[�v�o���邩���v�Z
			g_fpsCounter = frameCount * 1000 / (currentTime - fpsLastTime);
			fpsLastTime = currentTime;	//�\���������Ԃ�ۑ�
			frameCount = 0;				//�Q�[�����[�v�J�E���g���Z�b�g
		}

		//�O��Q�[���������s�������ԂƁA���݂̎��Ԃ̍���
		// 1/60�b�i��16.7�~���b�j�ȏ�ɂȂ����珈�����s��
		// FPS�͂�������60�ɂȂ�
		if ((currentTime - execLastTime) >= (1000 / 60))//�R�����g�ɂ����PC�̖{�C��������
		{
			execLastTime = currentTime;//�Q�[���������s���Ԃ�ۑ�

			//������
			Init();
			//�X�V����
			Update();
			//�`�揈��
			Draw();
			//�T�E���h
			UpdateSound();
			//�I������
			//Uninit();

			//�����񐔃J�E���^�[
			frameCount++;
			// �f�o�b�O���̂݊֐����Ă΂��
			
//#ifdef _DEBUG
			DispFPS();
//#endif
		}
	} while (!inport(PK_ESC)); // ESC�����܂Ń��[�v

	// �J�[�\���\���n�m
	setcursortype(NORMALCURSOR);

	// �^�C�}�[����\��߂�
	timeEndPeriod(1);

	HEWCleanup();
	return 0;
}

// =============================================================================
// �E�B���h�E�ݒ�̏������iHEW�p�ݒ�j
// =============================================================================
void WindowConsoleInitialize(void)
{
	// Set console window position
	HWND consoleWindow = GetConsoleWindow();
	int x, y;
	x = WINDOWPOS_X;
	y = WINDOWPOS_Y;
	SetWindowPos(consoleWindow, 0, x, y, 0, 0, SWP_NOSIZE | SWP_NOZORDER);

	// Set console window size
	SMALL_RECT windowSize = { 0, 0, 80, 25 };
	SetConsoleWindowInfo(GetStdHandle(STD_OUTPUT_HANDLE), TRUE, &windowSize);

	// Set console buffer size
	// �E�B���h�E�T�C�Y��80, 25�ŌŒ肷�邱��
	COORD coord;
	coord.X = 80;
	coord.Y = 25;
	SetConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE), coord);

	// Set console font style and size
	CONSOLE_FONT_INFOEX cfi;
	cfi.cbSize = sizeof(cfi);
	cfi.nFont = 0;
	// ���t�H���g�T�C�Y�̂ݕύX��//////////////////////////
	cfi.dwFontSize.X = 12;						// Width of each character in the font
	cfi.dwFontSize.Y = 24;						// Height
	// ���t�H���g�T�C�Y�̂ݕύX��/////////////////////////
	cfi.FontFamily = FF_DONTCARE;
	cfi.FontWeight = FW_NORMAL;
	wcscpy_s(cfi.FaceName, L"MS Gothic");       // Choose your font
	SetCurrentConsoleFontEx(GetStdHandle(STD_OUTPUT_HANDLE), FALSE, &cfi);
}

// =============================================================================
//������
// =============================================================================
void	Init()
{

	if (g_Scene != g_SceneNext)	//�V�[���J�ڂ̃��N�G�X�g�`�F�b�N
	{
		Uninit();				//���݂̃V�[�����I��

		g_Scene = g_SceneNext;	//�V�[���̐؂�ւ�

		switch (g_Scene)		//���݂̃V�[���̏�����
		{
			case SCENE_TITLE:
				InitTitle();	break;
			case SCENE_GAME:
				InitGame();		break;
			case SCENE_GAMEOVER:
				InitGameOver();	break;
			case SCENE_RESULT:
				InitResult();	break;
		}
		
	}


}

// =============================================================================
//�@�I��
// =============================================================================
void	Uninit()
{
	switch (g_Scene)	//���݂̃V�[�����I��
	{
		case SCENE_TITLE:
			FinalizeTitle();	break;
		case SCENE_GAME:
			FinalizeGame();		break;
		case SCENE_GAMEOVER:
			FinalizeGameOver();	break;
		case SCENE_RESULT:
			FinalizeResult();	break;
	}

}

// =============================================================================
//�X�V
// =============================================================================
void	Update()
{

	UpdateKey();	//�L�[�����쐬����

	switch (g_Scene)	//���݂̃V�[�����I��
	{
		case SCENE_TITLE:
			UpdateTitle();	break;
		case SCENE_GAME:
			UpdateGame();	break;
		case SCENE_GAMEOVER:
			UpdateGameOver();	break;
		case SCENE_RESULT:
			UpdateResult();	break;
	}

}

// =============================================================================
//�\��
// =============================================================================
void	Draw()
{
	switch (g_Scene)	//���݂̃V�[�����I��
	{
		case SCENE_TITLE:
			DrawTitle();	break;
		case SCENE_GAME:
			DrawGame();		break;
		case SCENE_GAMEOVER:
			DrawGameOver();	break;
		case SCENE_RESULT:
			DrawResult();	break;
	}
	//�����̐F��߂�
	textcolor(WHITE);

}

//�V�[���̐؂�ւ�
void	SetScene(GAMESCENE scene)
{
	g_SceneNext = scene;
}


//�V�[���̎擾
GAMESCENE GetScene()
{
	return g_Scene;
}

//#ifdef _DEBUG
// =============================================================================
// �f�o�b�O�\��
// =============================================================================
void DispFPS(void)
{
	// �F�ݒ�
	textcolor(LIGHTCYAN);

	gotoxy(1, 1);	// �\���ʒu�ݒ�
	std::cout << "FPS:" << g_fpsCounter;	// FPS�l�\��

	// �F�ݒ�(���Ƃɖ߂�)
	textcolor(WHITE);
}
//#endif
