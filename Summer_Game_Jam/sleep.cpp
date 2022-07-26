#include"Dxlib.h"
#include"sleep.h"

void Sleep_Initialize() {
	ImageSleep = LoadGraph("Resource/images/Player_Sleep");
	ImageSleep = LoadGraph("Resource/images/sleep.png");
}

void Sleep_Finalize() {
	DeleteGraph(ImageSleep);
	DeleteGraph(ImageSleep2);
}

void Sleep_Update(Enemy* enemy) {
	if (enemy->GetEnemyAliveFlg(enemy))gauge--;
}

void Sleep_Draw() {
	DrawBox(0, 0, 620 + 20, 10 + 20, black, TRUE);		//˜g‚ğ•`‰æ
	DrawBox(0, 0, 640 + 20 * gauge / gaugeMax, 10 + 20, blue, TRUE);	//HPƒQ[ƒW‚ğ•`‰æ
	DrawBox(0, 0, 620 + 20, 10 + 20, black, FALSE);		//˜g‚ğ•`‰æ
}