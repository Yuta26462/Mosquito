#include "Title.h"
#include "GameMain.h"
#include "main.h"
#include "DxLib.h"

BaseScene* Title::Update() {
	//z�L�[�ŃQ�[�����C���ֈړ�
	if (g_KeyFlg & PAD_INPUT_A) {
		return new GameMain();
	}//�X�y�[�X�L�[�ŃQ�[���I��
	else if (g_KeyFlg & PAD_INPUT_M) {
		return nullptr;
	}
	else {
		return this;
	}
	if (GetSelectY() == 1 /*&& SelectNo > 0*/)SelectNo = 1;
	if (GetSelectY() == -1 /*&& SelectNo < 3*/)SelectNo--;
	SelectNo = 1;

	if (g_KeyFlg & PAD_INPUT_A) {
		switch (SelectNo)
		{
		case 0:
			return new GameMain();
			break;
		/*case 1:
			return new Result();
			break;*/
		case 2:
			return new Title();
			break;
		default:
			break;
		}
	}
}

void Title::Draw() const {
	//�^�C�g���摜�\��
	DrawGraph(0, 0, Title_img, FALSE);
	DrawString(100, 400, "z�L�[�Ŏ��̃V�[����", 0x000000);
	DrawString(400, 400, "�X�y�[�X�L�[�ŏI��", 0x000000);
	DrawCircleAA(250, 270 + SelectNo * 50, 10.2f, 3, 0xFFFFFF, TRUE);
	DrawFormatString(200, 200, 0xFFFFFF, "%d", GetSelectX());
	DrawFormatString(200, 250, 0xFFFFFF, "%d", GetSelectY());
	DrawFormatString(200, 280, 0xFFFFFF, "SelectNo:%d", SelectNo);
}