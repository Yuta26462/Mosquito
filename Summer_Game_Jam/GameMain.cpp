#include "GameMain.h"
#include "Result.h"
#include "enemy.h"
#include "main.h"
#include "DxLib.h"
#include "player.h"
#include "sleep.h"

//GameMain::GameMain() {
//	//enemy = 0;
//	//Enemy_cnt = 0;
//}

BaseScene* GameMain::Update() {
	static bool StartFlg = true;
	if (StartFlg) {
		enemy->InitEnemy(enemy);
		StartFlg = false;
	}
	
	enemy->MoveEnemy(enemy,TimeLimt);
	Player_Update();
	Sleep_Update();
	//z?L?[????U???g??????
	if (TimeLimt-- < 1 || g_KeyFlg & PAD_INPUT_Y) {
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
		enemy[i].DrawEnemy(enemy[i].GetEnemyX(),enemy[i].GetEnemyY(),enemy[i].GetEnemyFlg());
	}
	
	DrawFormatString(100, 400, 0x000000, "Died_Enemy:%d", enemy->GetDied_enemy());
	DrawFormatString(500, 100, 0x000000, "Time:%d", GetTime()/60);
	DrawString(270, 220, "GameMain???", 0x000000);
	DrawString(250, 400, "Y?{?^???????V?[????", 0x000000);
	Player_Draw();
}

int GameMain::GetTime() const{
	return TimeLimt;
}
	Sleep_Draw();
}