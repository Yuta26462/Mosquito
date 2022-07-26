#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"
#include"player.h"

void Title::Initialize() const {
	Player_Initialize();
	PlaySoundMem(Title_BGM, DX_PLAYTYPE_BACK, TRUE);
}
void Title::Finalize() const{
	Player_Finalize();
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
		if (GetSelectY() == -1 && SelectNo > 0) {
				SelectNo--;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}
		if (GetSelectY() == 1 && SelectNo < 3){
				SelectNo++;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}

		if (g_KeyFlg & 16) {
			PlaySoundMem(OK_SE, DX_PLAYTYPE_BACK, TRUE);
			switch (SelectNo)
			{
			case 0:
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
		DrawString(100, 200, "�Ⴊ�U�ɕ�����ꂽ�g���ɏo�������I", 0xDC6560);
		DrawString(100, 230, "�X�e�B�b�N��\���{�^���ŉႪ����Ƃ���ɍ��킹�āA", 0xDC6560);
		DrawString(100, 260, "A�{�^��������������|�����Ƃ��ł����I", 0xDC6560);
		DrawString(100, 290, "�ԈႦ���ɘA���ŉ��|���Ă�����", 0xDC6560);
		DrawString(100, 320, "�R���{���������āA�l���ł���X�R�A�������Ă�������", 0xDC6560);
		DrawString(100, 350, "�撣���Ă�������|�����I�I", 0xDC6560);
		DrawStringToHandle(120, 400, "B�{�^���Ń^�C�g���ɖ߂�", 0xFFFFFF, MenuFont, 0xDC6560);
	}
	else if (MenuChangeFlg == 2) {//�N���W�b�g
		DrawGraph(0, 0, Credit_img, FALSE);
		DrawString(100, 200, "�^�C�g���@�@�@��", 0xDC6560);
		DrawString(100, 230, "����ҁ@�@�@�@���ۓd�q�r�W�l�X���w�Z L�`�[��", 0xDC6560);
		DrawString(100, 260, "�f�ޗ��p", 0xDC6560);
		DrawString(100, 290, "�摜�@�@�@�@�݂񂿂肦�i https://min-chi.material.jp/ �j", 0xDC6560);
		DrawString(100, 320, "BGM", 0xDC6560);
		DrawString(100, 350, "SE", 0xDC6560);


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