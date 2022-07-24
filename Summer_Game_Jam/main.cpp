#include "SceneManager.h"
#include "Title.h"
#include "main.h"
#include "DxLib.h"

int	g_OldKey;				// �O��̓��̓L�[
int	g_NowKey;				// ����̓��̓L�[
int	g_KeyFlg;				// ���̓L�[���

//�摜�p�ϐ�
int Title_img;
int GameMain_img;
int Result_img;

int LoadImages();           //�摜�ǂݍ��݊֐�

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {

    SetMainWindowText("�^�C�g������");

    ChangeWindowMode(TRUE); //�E�B���h�E���[�h��L��
    SetWindowSize(1280, 960);
    
    if (DxLib_Init() == -1) return -1;	// DX���C�u�����̏���������
    if (LoadImages() == -1)return -1;

    SetDrawScreen(DX_SCREEN_BACK);	// �`����ʂ𗠂ɂ���
    
    ChangeFontType(DX_FONTTYPE_ANTIALIASING_4X4);   //�t�H���g���A���`�G�C�W���O�Ή�4�~4�ɂ���B

    SceneManager scenMG(new Title());
    // �Q�[�����[�v
    while (scenMG.Update() != nullptr && ProcessMessage() == 0) {
        // ���̓L�[�擾
        g_OldKey = g_NowKey;
        g_NowKey = GetJoypadInputState(DX_INPUT_KEY_PAD1);
        g_KeyFlg = g_NowKey & ~g_OldKey;

        ClearDrawScreen();		// ��ʂ̏�����


        scenMG.Draw();

        ScreenFlip();			// ����ʂ̓��e��\��ʂɔ��f

    }

    DxLib_End();	// DX���C�u�����g�p�̏I������

    return 0;	// �\�t�g�̏I��
}

int LoadImages() {
    if ((Title_img = LoadGraph("Resource/Images/Title.png")) == -1)return -1;
    if ((GameMain_img = LoadGraph("Resource/Images/background.png")) == -1)return -1;
    if ((Result_img = LoadGraph("Resource/Images/Ranking.png")) == -1)return -1;
    return 0;
}