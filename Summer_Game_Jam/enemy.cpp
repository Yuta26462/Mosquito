#include "DxLib.h"
#include"enemy.h"

void DrawEnemy() {
	PosX = GetRand(RandMaxX);
	PosY = GetRand(RandMaxY);
	//�����_���ɕ`��
	DrawCircle(PosX, PosY, Radius, 0x000000);
}

void MoveEnemy() {
	PosX += MoveX;
	PosY += MoveY;
}