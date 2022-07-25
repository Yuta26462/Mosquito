#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"
#include"player.h"

void Title::Initialize() const {
	Player_Initialize();
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
	SelectNo = 0;
	MenuChangeFlg = 0;
}

BaseScene* Title::Update() {

	{	//���j���[
		if (GetSelectY() == -1) { if (SelectNo > 0)SelectNo--; }
		if (GetSelectY() == 1){if (SelectNo < 3)SelectNo++; }

		if (g_KeyFlg & 16) {
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
			if (g_KeyFlg & 32)MenuChangeFlg = 0;
		}

		return this;
	}

	//z�L�[�ŃQ�[�����C���ֈړ�
	if (g_KeyFlg & PAD_INPUT_A) {
		
		return new GameMain();
	}//�X�y�[�X�L�[�ŃQ�[���I��
	else if (g_KeyFlg & PAD_INPUT_Y) {
		return nullptr;
	}
	else {
		return this;
	}
}

void Title::Draw() const {

	if (MenuChangeFlg == 1) {//�������
		DrawGraph(0, 0, Help_img, FALSE);
		DrawString(100, 200, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 230, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 260, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 290, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 320, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 350, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawStringToHandle(120, 400, "z�L�[�Ŏ��̃V�[����", 0xFFFFFF, MenuFont, 0xDC6560);
	}
	else if (MenuChangeFlg == 2) {//�N���W�b�g
		DrawGraph(0, 0, Credit_img, FALSE);
		DrawString(100, 200, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 230, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 260, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 290, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 320, "z�L�[�Ŏ��̃V�[����", 0xDC6560);
		DrawString(100, 350, "z�L�[�Ŏ��̃V�[����", 0xDC6560);


	}else {
		//�^�C�g���摜�\��
		DrawGraph(0, 0, Title_img, FALSE);
		DrawString(100, 400, "z�L�[�Ŏ��̃V�[����", 0x000000);
		DrawString(400, 400, "�X�y�[�X�L�[�ŏI��", 0x000000);
		DrawStringToHandle(230, 250, "�X�^�[�g", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 295, "�������", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 340, "�N���W�b�g", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 385, "�Q�[���I��", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawCircleAA(200, 270 + SelectNo * 45, 16.0f, 3, 0xDC6560, TRUE);
		

	}
}