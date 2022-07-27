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
}
void Title::Finalize() const{
	Sleep_Finalize();
	Player_Finalize();
	Sleep_Finalize();
}

Title::Title() {
	MenuFont = CreateFontToHandle("MenuFont", 40, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	Pointer_img = LoadGraph("Resource/Images/pointer.png");
	Help_img = LoadGraph("Resource/Images/Background/help.png");
	Credit_img = LoadGraph("Resource/Images/Background/Credit.png");

	
	Pad_img = LoadGraph("Resource/Images/pad.png");
	OK_SE = LoadSoundMem("Resource/Sounds/SE/OK.wav");
	Selecter_SE = LoadSoundMem("Resource/Sounds/SE/Selecter.wav");
	Return_SE = LoadSoundMem("Resource/Sounds/SE/Return.wav");
	Title_BGM = LoadSoundMem("Resource/Sounds/BGM/Title.wav");
	SelectNo = 0;
	MenuChangeFlg = 0;
	PlaySoundMem(Title_BGM, DX_PLAYTYPE_BACK, TRUE);
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
		DrawString(100, 140, "�Ⴊ�U�ɕ�����ꂽ�g���ɏo�������I", 0xffffff);
		//DrawString(140, 190, "�X�e�B�b�N�ŉႪ����Ƃ���ɃJ�[�\�������킹�āA", 0xffffff);
		//DrawString(140, 220, "A�{�^��������������|�����Ƃ��ł����I", 0xffffff);
		DrawString(100, 160, "�ԈႦ���ɘA���ŉ��|���Ă����ƃR���{���������āA", 0xffffff);
		DrawString(100, 180, "�l���ł���X�R�A�������Ă�������撣���Ă�������|�����I", 0xffffff);
		//DrawString(140, 310, "�撣���Ă�������|�����I�I", 0xffffff);
		DrawRotaGraph(300, 300, 0.5, 0, Pad_img, TRUE);
		DrawStringToHandle(90, 400, "B�{�^���Ń^�C�g���ɖ߂�", 0xFFFFFF, MenuFont, 0xDC6560);
	}
	else if (MenuChangeFlg == 2) {//�N���W�b�g
		DrawGraph(0, 0, Credit_img, FALSE);
		DrawString(100, 130, "�^�C�g��", 0x7fffd4);
		DrawString(200, 130, "��", 0xffffff);
		DrawString(100, 150, "�����", 0x7fffd4);
		DrawString(200, 150, "���ۓd�q�r�W�l�X���w�Z L�`�[��", 0xffffff);
		DrawString(130, 200, "�f�ޗ��p", 0xffff00);
		DrawString(100, 230, "�摜", 0xffff00);
		DrawString(180, 230, "�݂񂿂肦        ", 0xffffff);
		DrawString(180, 250, "���炷�Ƃ�        ", 0xffffff);
		DrawString(330, 230, "BGM", 0xffff00);
		DrawString(410, 230, "DOVA-SYNDROME", 0xffffff);
		DrawString(410, 250, "MusMus", 0xffffff);
		DrawString(100, 300, "SE", 0xffff00);
		DrawString(180, 300, "�������@�@�@�@     �y�X�c����z     �V�X�e��49", 0xffffff);
		DrawString(180, 320, "OtoLogic           �yOtoLogic�z     ��@���^01", 0xffffff);
		DrawString(180, 340, "���ʉ����{�@�@�@   �y���ʉ����{�z   �L�����Z��5", 0xffffff);
		DrawString(180, 360, "���ʉ��H�[�@�@�@   �y���ʉ��H�[�z   �J�[�\���ړ�-11", 0xffffff);
		DrawString(180, 380, "�j�R�j�E�R�����Y   �y�ł��߂Ƃ똥�z ��̒��̉� ", 0xffffff);
		DrawString(180, 400, "                   �y�݂�����z     ������@������ ", 0xffffff);


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