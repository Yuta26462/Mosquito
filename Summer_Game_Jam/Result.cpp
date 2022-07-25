#include "Result.h"
#include "Title.h"
#include "main.h"
#include "DxLib.h"

void Result::Initialize() const {

}
void Result::Finalize() const {

}

BaseScene* Result::Update() {
	//zキーでタイトル画面へ移動
	if (g_KeyFlg & PAD_INPUT_A) {
		return new Title();
	}
	else {
		return this;
	}
}

void Result::Draw() const {
	DrawGraph(0, 0, Result_img, FALSE);
	DrawString(280, 220, "Result画面", 0x000000);
	DrawString(250, 400, "zキーで次のシーンへ", 0x000000);
}