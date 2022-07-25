#include "SceneManager.h"
#include "Title.h"
#include "main.h"
#include "DxLib.h"
#include<math.h>

class Fps {
	int mStartTime; //����J�n����
	int mCount;  //�J�E���^
	float mFps;  //fps
	static const int N = 60;  //���ς����T���v����
	static const int FPS = 60;  //�ݒ肵��FPS

public:
	Fps() {
		mStartTime = 0;
		mCount = 0;
		mFps = 0;
	}
	bool Update() {
		if (mCount == 0) {//1�t���[���ڂȂ玞�����L��
			mStartTime = GetNowCount();
		}
		if (mCount == N) {
			int t = GetNowCount();
			mFps = 1000.f / ((t - mStartTime) / (float)N);
			mCount = 0;
			mStartTime = t;
		}
		mCount++;
		return true;
	}
	void Draw() {
		DrawFormatString(100, 100, GetColor(255, 255, 255), "%.1f", mFps);
	}
	void Wait() {
		int tookTime = GetNowCount() - mStartTime;
		int waitTime = mCount * 1000 / FPS - tookTime;
		if (waitTime > 0) {
			Sleep(waitTime);
		}
	}
};

int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

//�摜�p�ϐ�
int Title_img;
int GameMain_img;
int Result_img;
int Enemy_img;
int Die_Enemy_img;

int JoyPadX, JoyPadY, PadTimer;
int SelectX, SelectY;

int LoadImages();           //�摜�ǂݍ��݊֐�

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	Fps fps;
    SetMainWindowText("��");

    ChangeWindowMode(TRUE); //�E�B���h�E���[�h��L��
    SetWindowSize(1280, 960);
    
    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������
    if (LoadImages() == -1)return -1;

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���
    
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);   //�t�H���g���A���`�G�C�W���O�Ή�4�~4�ɂ���B

    SceneManager scenMG(new Title());

    scenMG.Initialize();
    // �Q�[�����[�v
    while (scenMG.Update() != nullptr && ProcessMessage() == 0) {
        // ���̓L�[�擾
        g_OldKey = g_NowKey;
        g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
       // g_NowKey = GetJoypadInputState(DX_INPUT_PAD1);
        g_KeyFlg = g_NowKey & ~g_OldKey;

        GetJoypadAnalogInput(&JoyPadX, &JoyPadY, DX_INPUT_PAD1);    //�A�i���O�X�e�B�b�N���W���擾
        SetJoypadDeadZone(DX_INPUT_PAD1, 0.3f);     //�p�x�̐������ɘa

        SelectX = 0;
        SelectY = 0;

        if (++PadTimer > 10) {
            PadTimer = 0;
            if (JoyPadX > 100)SelectX = 1;
            if (JoyPadX < -100)SelectX = -1;
            if (JoyPadY > 100)SelectY = 1;
            if (JoyPadY < -100)SelectY = -1;
        }

        ClearDrawScreen();		// ��ʂ̏�����

		fps.Update();
		fps.Draw();
        scenMG.Draw();

		fps.Wait();
        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

    }
    scenMG.Finalize();
    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}

int LoadImages() {
    if ((Title_img = LoadGraph("Resource/Images/Title.png")) == -1)return -1;
    if ((GameMain_img = LoadGraph("Resource/Images/background.png")) == -1)return -1;
    if ((Result_img = LoadGraph("Resource/Images/Ranking.png")) == -1)return -1;
    if ((Enemy_img = LoadGraph("Resource/Images/ka.png")) == -1)return -1;
    if ((Die_Enemy_img = LoadGraph("Resource/Images/Die_ka.png")) == -1)return -1;
    return 0;
}

int GetSelectX(void) {
    if (SelectX == 1 || SelectX == -1) {
        int Key = SelectX;
        return Key;
    }
    else { return 0; }
}

int GetSelectY(void) {
    if (SelectY == 1 || SelectY == -1) {
        int Key = SelectY;
        return Key;
    }else{ return 0; }
}

int GetJoyPadX(void) { 
    if (-1000 <= JoyPadX && JoyPadX <= 1000) {
        int PadX = JoyPadX;
        return PadX;
    }else { return 0; }
}

int GetJoyPadY(void) {
    if (-1000 <= JoyPadY && JoyPadY <= 1000) {
        int PadY = JoyPadY;
        return PadY;
    }
    else { return 0; }
}