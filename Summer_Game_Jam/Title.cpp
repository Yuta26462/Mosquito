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
	//zキーでゲームメインへ移動
	if (g_KeyFlg & PAD_INPUT_A) {
		return new GameMain();
	}//スペースキーでゲーム終了
	else if (g_KeyFlg & PAD_INPUT_Y) {
		return nullptr;
	}
	else {
		return this;
	}
}

void Title::Draw() const {
	//タイトル画像表示
	DrawGraph(0, 0, Title_img, FALSE);
	DrawString(100, 400, "Aボタンで次のシーンへ", 0x000000);
	DrawString(400, 400, "Yボタンで終了", 0x000000);
}