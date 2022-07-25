#include "GameMain.h"
#include "Result.h"
#include "enemy.h"
#include "main.h"
#include "DxLib.h"
#include "player.h"


BaseScene* GameMain::Update() {
	static bool StartFlg = true;
	if (StartFlg) {
		enemy->InitEnemy(enemy);
		StartFlg = false;
	}
	
	enemy->MoveEnemy(enemy);
	Player_Update();
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
}

void GameMain::Finalize() const {
	Player_Finalize();
}

void GameMain::Draw() const{
	DrawGraph(0, 0, GameMain_img, FALSE);
	for (int i = 0; i < 10; i++) {
		enemy[i].DrawEnemy(enemy[i].GetEnemyX(),enemy[i].GetEnemyY());
	}
	
	DrawString(270, 220, "GameMain画面", 0x000000);
	DrawString(250, 400, "Yボタンで次のシーンへ", 0x000000);
	Player_Draw();
}