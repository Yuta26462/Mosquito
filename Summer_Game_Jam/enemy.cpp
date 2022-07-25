#include "DxLib.h"
#include"enemy.h"

void DrawEnemy() {
	PosX = GetRand(RandMaxX);
	PosY = GetRand(RandMaxY);
	//ƒ‰ƒ“ƒ_ƒ€‚É•`‰æ
	DrawCircle(PosX, PosY, Radius, 0x000000);
}

void MoveEnemy() {
	PosX += MoveX;
	PosY += MoveY;
}