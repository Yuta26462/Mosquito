#include"DxLib.h"
#include"player.h"
#include"main.h"

bool AttackFlg[6];

void Player_Initialize() {
	WeaponImage = LoadGraph("Resource/Images/Weapon.png");
	Mosquito_SE = LoadSoundMem("Resource/Sounds/SE/Mosquito.wav");
	BoxColor = GetColor(255, 0, 0);
	BoxNumber_x = 1;
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
	//static int NowArea = 0;
	if (AttackFlg[AreaNum] == false) {

		//Aボタンで攻撃
		if (g_KeyFlg & 16) {
			AttackFlg[AreaNum] = true;
			
		}

		
		//左
		if (GetJoyPadY() > 0 && GetJoyPadX() < -150) { BoxNumber_x = 0; BoxNumber_y = 1;}
		else if ((GetJoyPadY() < 0) && GetJoyPadX() < -150) { BoxNumber_x = 0; BoxNumber_y = 0;}

		//真ん中
		if (GetJoyPadY() > 0 && GetJoyPadX() == 0) { BoxNumber_x = 1; BoxNumber_y = 1;}
		else if ((GetJoyPadY() < 0) && GetJoyPadX() == 0) { BoxNumber_x = 1; BoxNumber_y = 0;}

		//右
		if (GetJoyPadY() > 0 && GetJoyPadX() > 150) { BoxNumber_x = 2; BoxNumber_y = 1;}
		else if ((GetJoyPadY() < 0) && GetJoyPadX() > 150) { BoxNumber_x = 2; BoxNumber_y = 0;}
	}
	switch (BoxNumber_x)
	{
	case 0:
		if (!BoxNumber_y)AreaNum = 0;
		else  AreaNum = 3;
		break;
	case 1:
		if (!BoxNumber_y)AreaNum = 1;
		else  AreaNum = 4;
		break;
	case 2:
		if (!BoxNumber_y)AreaNum = 2;
		else AreaNum = 5;
		break;
	default:
		break;
	}
	
	//NowArea = AreaNum;
	if (AttackFlg[AreaNum] == true/* && AreaNum == NowArea*/) {
		PlaySoundMem(Mosquito_SE, DX_PLAYTYPE_BACK, TRUE);
		AttackCount++;
		if (AttackCount > 8) {
			AttackFlg[AreaNum] = false;
			AttackCount = 0;
		}
	}

}
void Player_Draw() {
	DrawFormatString(100, 100, 0x000000, "areanum:%d", AreaNum);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 100);
	DrawLine(0, 240, 640, 240, 0x000000);
	DrawLine(213, 0, 213, 480, 0x000000);
	DrawLine(426, 0, 426, 480, 0x000000);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 64);
	DrawBox(BoxNumber_x * 213, BoxNumber_y * 240, BoxNumber_x * 213 + 214, BoxNumber_y * 241 + 241, BoxColor, TRUE);
	SetDrawBlendMode(DX_BLENDMODE_ALPHA, 255);
	if (AttackFlg[AreaNum] == true) {
		DrawRotaGraph(BoxNumber_x * 213 + 106, BoxNumber_y * 240 + 120, 0.3, 0, WeaponImage, TRUE, FALSE);
		DrawString(300, 200, "ボタン押したよ", 0x000000);
	}
}