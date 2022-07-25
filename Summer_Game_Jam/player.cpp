#include"DxLib.h"
#include"player.h"
#include"main.h"

bool AttackFlg;

void Player_Initialize() {
	WeaponImage = LoadGraph("Resource/Images/Weapon.png");
	BoxColor = GetColor(255,0,0);
	BoxNumber_x = 0;
	BoxNumber_y = 0;
	box_x = 0;
	box_y = 0;
	AttackCount = 0;
	AttackFlg = 0;
}
void Player_Finalize() {
	DeleteGraph(WeaponImage);
}
void Player_Update() {
	if (AttackFlg == false) {
		if (g_KeyFlg & PAD_INPUT_RIGHT || GetSelectX() == 1) {
			if (++BoxNumber_x > 2) BoxNumber_x = 2;
		}
		if (g_KeyFlg & PAD_INPUT_LEFT || GetSelectX() == -1) {
			if (--BoxNumber_x < 0) BoxNumber_x = 0;
		}
		if (g_KeyFlg & PAD_INPUT_DOWN || GetSelectY() == 1) {
			if (++BoxNumber_y > 1) BoxNumber_y = 1;
		}
		if (g_KeyFlg & PAD_INPUT_UP || GetSelectY() == -1) {
			if (--BoxNumber_y < 0) BoxNumber_y = 0;
		}
		if (g_KeyFlg & PAD_INPUT_A || g_KeyFlg & 32) {
			AttackFlg = true;
		}
		if (GetJoyPadY() > 0 && GetJoyPadX() < 50 && GetJoyPadX() > -50) { BoxNumber_x = 1; BoxNumber_y = 1; }
		else if((GetJoyPadY() < 0) && GetJoyPadY() < 50 && GetJoyPadY() > -50){BoxNumber_x = 1; BoxNumber_y = 0; }
	}
	if (AttackFlg == true) {
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
		DrawString(300, 200, "ƒ{ƒ^ƒ“‰Ÿ‚µ‚½‚æ", 0x000000);
	}
}