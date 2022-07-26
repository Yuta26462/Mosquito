#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"
#include "player.h"
#include "sleep.h"


BaseScene* GameMain::Update() {
	Player_Update();
	Sleep_Update();
	//zキーでリザルト画面へ移動
	if (g_KeyFlg & PAD_INPUT_Y) {
		return new Result();
	}
	else {
		return this;
	}
}
void GameMain::Initialize() const {
	Player_Initialize();
	Sleep_Initialize();
}

void GameMain::Finalize() const {
	Player_Finalize();
	Sleep_Finalize();
}
void GameMain::Draw() const {
	DrawGraph(0, 0, GameMain_img, FALSE);
	DrawString(270, 220, "GameMain画面", 0x000000);
	DrawString(250, 400, "Yボタンで次のシーンへ", 0x000000);
	Player_Draw();
	Sleep_Draw();
}