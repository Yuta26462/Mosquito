#include "Result.h"
#include "Title.h"
#include "main.h"
#include "DxLib.h"
#include "sleep.h"

bool StartFlg;

void Result::Initialize() const {

}
void Result::Finalize() const {

}

BaseScene* Result::Update() {
	//Bボタンでタイトルへ
	if (g_KeyFlg & 32) {
		StartFlg = true;
		return new Title();
	}
	else {
		return this;
	}
}

void Result::Draw() const {
	DrawGraph(0, 0, Result_img, FALSE);
}