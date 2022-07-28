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
	Moon_img = LoadGraph("Resource/Images/Background/Moon1.png");
	Sun_img = LoadGraph("Resource/Images/Background/Sun.png");
	PlaySoundMem(Main_BGM, DX_PLAYTYPE_BACK, TRUE);
	PlaySoundMem(Wind_chimes_SE, DX_PLAYTYPE_BACK, TRUE);
	static bool StartFlg = true;
	TimeLimt = 1800;
	Player_Initialize();
	Sleep_Initialize();
	enemy->InitEnemy();
	StatusFont = CreateFontToHandle("StatusFont", 20, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);
	MoonX = 200;
	MoonY = 130;
	SunX = 640;
	SunY = 500;
	BackgroundColor = RGB(41, 42, 62);
	Bright = 140;
}

BaseScene* GameMain::Update() {

	//GraphFilter(GameMain_img, DX_GRAPH_FILTER_HSB, 0, MoonFilter[0], MoonFilter[1], MoonFilter[2]);
	if (TimeLimt % 60 == 0) {
		BackgroundColor += RGB(7, 4, 0);
	}else if(TimeLimt % 6 == 0){
		MoonX++;
		MoonY++;
		SunX--;
		SunY--;
		Bright++;
	}
	if (TimeLimt < 900)StopSoundMem(Main_BGM);
	
	enemy->MoveEnemy(TimeLimt);
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
	DrawBoxAA(0, 0, 641, 360, BackgroundColor, TRUE, 0);
	DrawRotaGraph(MoonX, MoonY, 0.5f, 0, Moon_img, TRUE);
	DrawRotaGraph(SunX, SunY, 1.0f, 0, Sun_img, TRUE);
	SetDrawBright(Bright, Bright, Bright);
	DrawExtendGraph(0, 0,641,481, GameMain_img,TRUE);
	SetDrawBright(255, 255, 255);
	Sleep_Player_Draw();
	for (int i = 0; i < 10; i++) {
		enemy[i].DrawEnemy();
	}
	Player_Draw();
	Sleep_Draw();

	DrawStringToHandle(500, 50, "Time", 0xffff00, StatusFont);
	DrawFormatStringToHandle(570, 50, 0xffffff, StatusFont, "%d", TimeLimt / 60);
	DrawStringToHandle(500, 80, "Score", 0xffff00, StatusFont);
	DrawFormatStringToHandle(570, 80, 0xfca800, StatusFont, "%d", enemy->GetScore());
	DrawFormatStringToHandle(495, 120, 0xfca800, StatusFont, " %d", enemy->GetCombo());
	DrawStringToHandle(520, 120, " Combo", 0xffff00, StatusFont);
}

int GameMain::GetTime() const {
	return TimeLimt;
}