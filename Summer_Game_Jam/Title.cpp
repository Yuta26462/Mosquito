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
}

void Title::Draw() const {
	//�^�C�g���摜�\��
	DrawGraph(0, 0, Title_img, FALSE);
	DrawString(100, 400, "z�L�[�Ŏ��̃V�[����", 0x000000);
	DrawString(400, 400, "�X�y�[�X�L�[�ŏI��", 0x000000);
}