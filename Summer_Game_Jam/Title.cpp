#include "Title.h"
#include "GameMain.h"
#include "main.h"
#include "DxLib.h"
#include"player.h"

void Title::Initialize() const {
	Player_Initialize();
}
void Title::Finalize() const{
	Player_Finalize();
}

BaseScene* Title::Update() {
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
	//�^�C�g���摜�\��
	DrawGraph(0, 0, Title_img, FALSE);
	DrawString(100, 400, "A�{�^���Ŏ��̃V�[����", 0x000000);
	DrawString(400, 400, "Y�{�^���ŏI��", 0x000000);
}