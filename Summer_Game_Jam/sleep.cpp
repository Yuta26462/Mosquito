#include"Dxlib.h"
#include"sleep.h"
#include "enemy.h"
#include "Result.h"
#include "GameMain.h"

bool finishFlg;
bool StartFlg;
void Sleep_Initialize() {
	gauge = 0;
	finishFlg = false;
	ImageSleep = LoadGraph("Resource/images/Player_Sleep");
	ImageSleep = LoadGraph("Resource/images/sleep.png");
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
		DrawBox(0, 0, 620 + 20, 10 + 20, black, TRUE);		//?g??`??
		DrawBox(0, 0, 640 + 20 * gauge / gaugeMax, 10 + 20, blue, TRUE);	//HP?Q?[?W??`??
		DrawBox(0, 0, 620 + 20, 10 + 20, black, FALSE);		//?g??`??
}