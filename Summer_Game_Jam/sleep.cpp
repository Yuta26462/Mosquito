#include"Dxlib.h"
#include"sleep.h"
#include "enemy.h"
#include "Result.h"
#include "GameMain.h"

#define PI 3.141592654

bool finishFlg;

void Sleep_Initialize() {
	gauge = 0;
	finishFlg = false;
	ImageSleep = LoadGraph("Resource/images/Player_Sleep.png");
	ImageSleep2 = LoadGraph("Resource/images/sleep.png");
}

void Sleep_Finalize() {
	DeleteGraph(ImageSleep);
	DeleteGraph(ImageSleep2);
}

void Sleep_Update(Enemy* enemy) {
	if (enemy->GetEnemyAliveFlg(enemy))gauge--;
	if (20 * gauge / gaugeMax <= -640) {
		finishFlg = true;
	}
	else {
		finishFlg = false;
	}
}

void Sleep_Draw() {
	DrawBox(0, 0, 620 + 20, 10 + 20, black, TRUE);
	if (640 + 20 * gauge / gaugeMax >= 320) {
		DrawBox(0, 0, 640 + 20 * gauge / gaugeMax, 10 + 20, blue, TRUE);
	}
	else if (640 + 20 * gauge / gaugeMax < 320 && 640 + 20 * gauge / gaugeMax >= 160 ){
		DrawBox(0, 0, 640 + 20 * gauge / gaugeMax, 10 + 20, yello, TRUE);
	}
	else {
		DrawBox(0, 0, 640 + 20 * gauge / gaugeMax, 10 + 20, red, TRUE);
	}
	DrawBox(0, 0, 620 + 20, 10 + 20, black, FALSE);
	SetFontSize(20);
	DrawString(260, 5, "êáñ∞ÉQÅ[ÉW", 0x000000);
}

void Sleep_Player_Draw() {
	if (gauge <= 0) {
		DrawRotaGraph(320, 390, 0.7, PI / 2, ImageSleep, TRUE);
	}
	if (gauge <= -960) {
		DeleteGraph(ImageSleep);
		DrawRotaGraph(320, 390, 0.6, 0, ImageSleep2, TRUE);
	}
}