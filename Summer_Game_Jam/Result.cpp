#include "Result.h"
#include "Title.h"
#include "main.h"
#include "DxLib.h"

void Result::Initialize() const {

}
void Result::Finalize() const {

}

BaseScene* Result::Update() {
	//z�L�[�Ń^�C�g����ʂֈړ�
	if (g_KeyFlg & PAD_INPUT_A) {
		return new Title();
	}
	else {
		return this;
	}
}

void Result::Draw() const {
	DrawGraph(0, 0, Result_img, FALSE);
	DrawString(280, 220, "Result���", 0x000000);
	DrawString(250, 400, "z�L�[�Ŏ��̃V�[����", 0x000000);
}