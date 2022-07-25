#include"DxLib.h"
#include"player.h"
#include"main.h"

bool AttackFlg[6];

void Player_Initialize() {
	WeaponImage = LoadGraph("Resource/Images/Weapon.png");
	BoxColor = GetColor(255,0,0);
	BoxNumber_x = 0;
	BoxNumber_y = 0;
	box_x = 0;
	box_y = 0;
	AttackCount = 0;
	AreaNum = 0;
	for (int i = 0; i < 6; i++) {
		AttackFlg[i] = 0;
	}
	
}
void Player_Finalize() {
	DeleteGraph(WeaponImage);
}
void Player_Update() {
	if (AttackFlg[AreaNum] == false) {
		if (g_KeyFlg & PAD_INPUT_RIGHT) {
			if (++BoxNumber_x > 2) BoxNumber_x = 2;
		}
		if (g_KeyFlg & PAD_INPUT_LEFT) {
			if (--BoxNumber_x < 0) BoxNumber_x = 0;
		}
		if (g_KeyFlg & PAD_INPUT_DOWN) {
			if (++BoxNumber_y > 1) BoxNumber_y = 1;
		}
		if (g_KeyFlg & PAD_INPUT_UP) {
			if (--BoxNumber_y < 0) BoxNumber_y = 0;
		}
		AreaNum = BoxNumber_x;
		if (BoxNumber_y > 0)AreaNum += 3;
		if (g_KeyFlg & PAD_INPUT_A) {
			AttackFlg[AreaNum] = true;
		}
	}
	if (AttackFlg[AreaNum] == true) {
		AttackCount++;
		if (AttackCount > 8) {
			AttackFlg = false;
			AttackCount = 0;
		}
	}
}
void Player_Draw() {
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawLine(0, 240, 640, 240, 0x000000);
	DrawLine(213, 0, 213, 480, 0x000000);
	DrawLine(426, 0, 426, 480, 0x000000);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
	DrawBox(BoxNumber_x * 213, BoxNumber_y * 240, BoxNumber_x * 213 + 214, BoxNumber_y * 241 + 241, BoxColor, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	if (AttackFlg == true) {
		DrawRotaGraph(BoxNumber_x * 213 + 106, BoxNumber_y * 240 + 120, 0.3, 0, WeaponImage,TRUE, FALSE);
		DrawString(300, 200, "�{�^����������", 0x000000);
	}
}