#include "Result.h"
#include "Title.h"
#include "main.h"
#include "DxLib.h"

void Result::Initialize() const {

}
void Result::Finalize() const {

}

BaseScene* Result::Update() {
	//Bボタンでタイトルへ
	if (g_KeyFlg & 32) {
		return new Title();
	}
	else {
		return this;
	}
}

void Result::Draw() const {
	DrawGraph(0, 0, Result_img, FALSE);
}