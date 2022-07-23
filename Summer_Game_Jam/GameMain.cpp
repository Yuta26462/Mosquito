#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"

BaseScene* GameMain::Update() {
	//zキーでリザルト画面へ移動
	if (g_KeyFlg & PAD_INPUT_A) {
		return new Result();
	}
	else {
		return this;
	}
}

void GameMain::Draw() const {
	DrawGraph(0, 0, GameMain_img, FALSE);
	DrawString(250, 400, "zキーで次のシーンへ", 0x000000);
}