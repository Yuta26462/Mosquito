#include"DxLib.h"
#include"player.h"
#include"main.h"

void Player_Initialize() {
	WeaponImage = LoadGraph("images/Weapon.png");
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
	if (g_KeyFlg & PAD_INPUT_A) {
		AttackFlg = true;
	}
	if (AttackFlg == true) {
		AttackCount++;
		if (AttackCount > 30) {
			AttackFlg = false;
			AttackCount = 0;
		}
	}
}
void Player_Draw() {
	DrawLine(0, 240, 640, 240, 0xffffff);
	DrawLine(213, 0, 213, 480, 0xffffff);
	DrawLine(426, 0, 426, 480, 0xffffff);
	DrawBox(BoxNumber_x * 213, BoxNumber_y * 240, BoxNumber_x * 213 + 214, BoxNumber_y * 241 + 241, BoxColor, FALSE);
	if (AttackFlg == true) {
		DrawRotaGraph(BoxNumber_x * 213, BoxNumber_y * 240, 0.5, 0, WeaponImage,TRUE, FALSE);
		DrawString(300, 200, "�{�^����������", 0x000000);
	}
}