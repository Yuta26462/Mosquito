#include"Dxlib.h"
#include"sleep.h"
#include "enemy.h"
#include "Result.h"
#include "GameMain.h"

bool finishflg;

void Sleep_Initialize() {
	gauge = 0;
	finishflg = false;
	ImageSleep = LoadGraph("Resource/images/Player_Sleep");
	ImageSleep = LoadGraph("Resource/images/sleep.png");
}

void Sleep_Finalize() {
	DeleteGraph(ImageSleep);
	DeleteGraph(ImageSleep2);
}

void Sleep_Update() {
	gauge--;
	if (20 * gauge / gaugeMax <= -640) {
		finishflg = true;
	}
	else {
		finishflg = false;
	}
}

void Sleep_Draw() {
		DrawBox(0, 0, 620 + 20, 10 + 20, black, TRUE);		//˜g‚ð•`‰æ
		DrawBox(0, 0, 640 + 20 * gauge / gaugeMax, 10 + 20, blue, TRUE);	//HPƒQ[ƒW‚ð•`‰æ
		DrawBox(0, 0, 620 + 20, 10 + 20, black, FALSE);		//˜g‚ð•`‰æ
}