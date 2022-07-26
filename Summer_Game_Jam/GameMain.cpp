#include "GameMain.h"
#include "Result.h"
#include "enemy.h"
#include "main.h"
#include "DxLib.h"
#include "player.h"
#include "sleep.h"


BaseScene* GameMain::Update() {
	static bool StartFlg = true;
	if (StartFlg) {
		enemy->InitEnemy(enemy);
		StartFlg = false;
	}
	
	enemy->MoveEnemy(enemy,TimeLimt);
	enemy->CheckEnemyAlive(enemy);
	Player_Update();
	Sleep_Update(enemy);
	//デバッグ用		Yボタンでリザルト画面へ
	if (TimeLimt-- < 1 || g_KeyFlg & 128 || finishFlg == true) {
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

void GameMain::Draw() const{
	DrawGraph(0, 0, GameMain_img, FALSE);
	for (int i = 0; i < 10; i++) {
		enemy[i].DrawEnemy(enemy[i].GetEnemyX(),enemy[i].GetEnemyY(),enemy[i].GetEnemyFlg()/*,enemy[i].GetEnemyDflg()*/);
	}
	
	DrawFormatString(100, 400, 0x000000, "Died_Enemy:%d", enemy->GetDied_enemy());
	DrawFormatString(500, 100, 0x000000, "Time:%d", GetTime()/60);
	Player_Draw();
	Sleep_Draw();
}

int GameMain::GetTime() const{
	return TimeLimt;
}