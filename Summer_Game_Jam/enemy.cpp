#include "DxLib.h"
#include"enemy.h"

void CreateEnemy() {
	//ランダムに描画
	DrawCircle(GetRand(RandMaxX), GetRand(RandMaxY), 5, 0x000000, TRUE);
}

void EnemyControl() {

}