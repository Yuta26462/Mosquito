#include "GameMain.h"
#include "Result.h"
#include "enemy.h"
#include "main.h"
#include "DxLib.h"
#include "player.h"
#include "sleep.h"


GameMain::GameMain() {
	Main_BGM = LoadSoundMem("Resource/Sounds/BGM/Title.wav");
	MainUp_BGM = LoadSoundMem("Resource/Sounds/BGM/GameMain_UP.wav");
	Wind_chimes_SE = LoadSoundMem("Resource/Sounds/SE/wind_chimes.wav");
	PlaySoundMem(Main_BGM, DX_PLAYTYPE_BACK, TRUE);
	PlaySoundMem(Wind_chimes_SE, DX_PLAYTYPE_BACK, TRUE);
	static bool StartFlg = true;
	TimeLimt = 1800;
	Player_Initialize();
	Sleep_Initialize();
	enemy->InitEnemy(enemy);
	StatusFont = CreateFontToHandle("StatusFont", 20, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
}

BaseScene* GameMain::Update() {
	
	enemy->MoveEnemy(enemy,TimeLimt);
	enemy->CheckEnemyAlive(enemy);
	Player_Update();
	Sleep_Update(enemy);
	//デバッグ用		Yボタンでリザルト画面へ
	if (TimeLimt-- < 1 || g_KeyFlg & 128 || finishFlg == true) {
		StopSoundMem(Main_BGM);
		StopSoundMem(Wind_chimes_SE);
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
	DrawExtendGraph(0, 0,641,481, GameMain_img, FALSE);
	Sleep_Player_Draw();
	for (int i = 0; i < 10; i++) {
		enemy->DrawEnemy(enemy[i]);
	}
	/*for (int j = 0; j < 6; j++) {
		DrawFormatString(30 * j, 200, 0xffffff, "%d", enemy->GetEnemyIntoArea(j));
	}*/
	
	//DrawFormatString(100, 350, 0x000000, "Died_Enemy:%d", enemy->GetDied_enemy());
	
	Player_Draw();
	Sleep_Draw();
	/*for (int j = 0; j < 10; j++) {
		DrawFormatString(enemy[i])
	}*/
	DrawFormatStringFToHandle(500, 50, 0xffffff, StatusFont, "Time:%d", GetTime() / 60);
	DrawFormatStringFToHandle(500, 100, 0xffffff, StatusFont, "Score:%d", enemy->GetScore());
	DrawFormatStringFToHandle(500, 150, 0xffffff, StatusFont, "Combo:%d", enemy->GetCombo());
}

int GameMain::GetTime() const {
	return TimeLimt;
}