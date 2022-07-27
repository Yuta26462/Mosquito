#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"
#include"player.h"
#include "sleep.h"

void Title::Initialize() const {
	Sleep_Initialize();
	Player_Initialize();
	Sleep_Initialize();
	PlaySoundMem(Title_BGM, DX_PLAYTYPE_BACK, TRUE);
}
void Title::Finalize() const{
	Sleep_Finalize();
	Player_Finalize();
	Sleep_Finalize();
}

Title::Title() {
	MenuFont = CreateFontToHandle("MenuFont", 40, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);;
	Pointer_img = LoadGraph("Resource/Images/pointer.png");
	Help_img = LoadGraph("Resource/Images/help.png");
	Credit_img = LoadGraph("Resource/Images/Credit.png");
	Menu_img = LoadGraph("Resource/Images/menu.png");
	OK_SE = LoadSoundMem("Resource/Sounds/SE/OK.wav");
	Selecter_SE = LoadSoundMem("Resource/Sounds/SE/Selecter.wav");
	Return_SE = LoadSoundMem("Resource/Sounds/SE/Return.wav");
	Title_BGM = LoadSoundMem("Resource/Sounds/BGM/Title.wav");
	SelectNo = 0;
	MenuChangeFlg = 0;
}

BaseScene* Title::Update() {

	{	//���j���[
		if (GetSelectY() == -1 && SelectNo > 0 && MenuChangeFlg == 0) {
				SelectNo--;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}
		if (GetSelectY() == 1 && SelectNo < 3 && MenuChangeFlg == 0){
				SelectNo++;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}

		if (g_KeyFlg & 16) {
			PlaySoundMem(OK_SE, DX_PLAYTYPE_BACK, TRUE);
			switch (SelectNo)
			{
			case 0:
				StopSoundMem(Title_BGM);
				return new GameMain();
				break;
			case 1:
				//�������
				MenuChangeFlg = 1;
				break;
			case 2:
				//�N���W�b�g
				MenuChangeFlg = 2;
				break;
			case 3:
				DxLib_End();
				break;
			default:
				break;
			}
		}

		if (MenuChangeFlg == 1 || MenuChangeFlg == 2) {
			//B�{�^���Ŗ߂�
			if (g_KeyFlg & 32) { PlaySoundMem(Return_SE, DX_PLAYTYPE_BACK, TRUE); MenuChangeFlg = 0; }
		}

		return this;
	}
}

void Title::Draw() const {

	if (MenuChangeFlg == 1) {//�������
		DrawGraph(0, 0, Help_img, FALSE);
		DrawString(140, 160, "�Ⴊ�U�ɕ�����ꂽ�g���ɏo�������I", 0xffffff);
		DrawString(140, 190, "�X�e�B�b�N�ŉႪ����Ƃ���ɃJ�[�\�������킹�āA", 0xffffff);
		DrawString(140, 220, "A�{�^��������������|�����Ƃ��ł����I", 0xffffff);
		DrawString(140, 250, "�ԈႦ���ɘA���ŉ��|���Ă�����", 0xffffff);
		DrawString(140, 280, "�R���{���������āA�l���ł���X�R�A�������Ă�������", 0xffffff);
		DrawString(140, 310, "�撣���Ă�������|�����I�I", 0xffffff);
		DrawStringToHandle(90, 400, "B�{�^���Ń^�C�g���ɖ߂�", 0xFFFFFF, MenuFont, 0xDC6560);
	}
	else if (MenuChangeFlg == 2) {//�N���W�b�g
		DrawGraph(0, 0, Credit_img, FALSE);
		DrawString(100, 130, "�^�C�g��      ��", 0xffffff);
		DrawString(100, 160, "�����        ���ۓd�q�r�W�l�X���w�Z L�`�[��", 0xffffff);
		DrawString(130, 190, "�f�ޗ��p", 0xffffff);
		DrawString(100, 220, "�摜�@�@ �@ �݂񂿂肦        ", 0xffffff);
		DrawString(100, 250, "            ���炷�Ƃ�        ", 0xffffff);
		DrawString(100, 280, "BGM         ", 0xffffff);
		DrawString(100, 310, "            ", 0xffffff);
		DrawString(100, 340, "SE          �������@�@�@�@     �y�X�c����z�V�X�e��49", 0xffffff);
		DrawString(100, 370, "            ���ʉ����{�@�@�@   �y���ʉ����{�z�L�����Z��5", 0xffffff);
		DrawString(100, 400, "            ���ʉ��H�[�@�@�@   �y���ʉ��H�[�z�J�[�\���ړ�-11", 0xffffff);
		DrawString(100, 430, "            �j�R�j�E�R�����Y   �y�ł��߂Ƃ똥�z��̒��̉� ", 0xffffff);


	}else {
		//�^�C�g���摜�\��
		DrawGraph(0, 0, Title_img, FALSE);
		DrawStringToHandle(230, 250, "�X�^�[�g", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 295, "�������", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 340, "�N���W�b�g", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 385, "�Q�[���I��", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawCircleAA(200, 270 + SelectNo * 45, 16.0f, 3, 0xDC6560, TRUE);
		

	}
}