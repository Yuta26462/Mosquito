#include "Title.h"
#include "GameMain.h"
#include "main.h"
#include "DxLib.h"

BaseScene* Title::Update() {
	//zキーでゲームメインへ移動
	if (g_KeyFlg & PAD_INPUT_A) {
		return new GameMain();
	}//スペースキーでゲーム終了
	else if (g_KeyFlg & PAD_INPUT_M) {
		return nullptr;
	}
	else {
		return this;
	}
}

void Title::Draw() const {
	//タイトル画像表示
	DrawGraph(0, 0, Title_img, FALSE);
}