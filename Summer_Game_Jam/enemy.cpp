#include "enemy.h"
#include "player.h"
#include "main.h"
#include "GameMain.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "DxLib.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HIGHT 960
#define Move_X 15
#define Move_Y 15

Enemy enemy[10];

void Enemy::InitEnemy(Enemy* enemy) {
	for (int i = 0; i < 10; i++) {
		enemy[i].flg = false;
		enemy[i].NowX = 0;
		enemy[i].NowY = 0;
		enemy[i].pos = 0;
		enemy[i].Enemy_time = 0;
		enemy[i].Spawn_flg = false;
	}
	for (int j = 0; j < 6; j++) {
		EnemyIntoArea[j] = 0;
	}
	enemy->Died_enemy = 0;
	enemy->Enemy_cnt = 0;
	enemy->Score = 0;
	enemy->Combo = 0;
	MissingSE= LoadSoundMem("Resource/Sounds/SE/swing1.wav");
}

void Enemy::DrawEnemy(Enemy enemy) const {
	static int DieImg_Tyme = 0;
	if (enemy.flg) {
		DrawRotaGraph(enemy.GetEnemyX(), enemy.GetEnemyY(), 0.1, 0, Enemy_img, TRUE, FALSE);
	}
	
}

void Enemy::MoveEnemy(int time) {
	if (AttackInterval <= 0)SetCombo(FALSE);
	CheckEnemyIntoArea(enemy);
	if (time % SetEnemySpawn(time) == 0 ) {
		enemy->CreateEnemy(enemy, 2);
	}
	if (time % 2) {
		for (int i = 0; i < 10; i++) {
			if (enemy[i].flg) {

				if ((enemy[i].NowX <= 20 || enemy[i].NowX >= 620) && !enemy[i].Spawn_flg) {
					if (enemy[i].pos <= 1) {
						enemy[i].NowX += Move_X;
					}
					else
					{
						enemy[i].NowX -= Move_X;
					}
				}
				else {
					enemy[i].Spawn_flg = true;
				}

				if (enemy[i].Enemy_time++ % 30) {
					enemy[i].Enemy_vector = GetRand(3);
				}
				if (enemy[i].Spawn_flg) {
					switch (enemy[i].Enemy_vector) {
					case UP:
						enemy[i].NowY -= 10;
						break;
					case DOWN:
						enemy[i].NowY += 10;
						break;
					case RIGHT:
						if (enemy[i].pos <= 1) {
							enemy[i].NowX += enemy[i].speed;
						}
						break;
					case LEFT:
						if (enemy[i].pos > 1) {
							enemy[i].NowX -= enemy[i].speed;
						}
						break;
					default:
						break;
					}


					enemy[i].Enemy_Area = enemy[i].NowX / 213;
					if (enemy[i].NowY > 240)enemy[i].Enemy_Area += 3;

					if (AttackFlg) {
						if (AreaNum == enemy[i].Enemy_Area) {
							DrawFormatString(enemy[i].NowX, enemy[i].NowY+10, 0xffffff, "%dcombo", Combo);
							enemy->SetScore();
							enemy->SetCombo(TRUE);
							enemy->Died_enemy++;
							DeleteEnemy(enemy, i);
						}
						else if (EnemyIntoArea[AreaNum] <= 0) {
							Missflg = true;
							//PlaySoundMem(MissingSE, DX_PLAYTYPE_BACK, TRUE);
							enemy->SetCombo(FALSE);
						}
					}
					
					if (enemy[i].Spawn_flg && (enemy[i].NowX < -5 || enemy[i].NowX > 645 || enemy[i].NowY < 25 || enemy[i].NowY > 485)) {
						DeleteEnemy(enemy, i);
					}
				}
			}
		}
	}
}

int SetEnemySpawn(int timelimit) {
	if (timelimit >= 1200 )return 120;
	else if (timelimit >= 600)return 60;
	else if (timelimit >= 0)return 30;
	else return -1;
}

int Enemy::SetEnemySpeed() {
	int rand_num = GetRand(5);
	if (rand_num <= 2)return 15;
	else if (rand_num <= 4)return 30;
	else if (rand_num <= 5) return 50;
	else return -1;
}

void Enemy::CreateEnemy(Enemy* enemy, int Make_enemys) {
	int made_enemys = 0;

	for (int i = 0; i < 10; i++) {
		if (made_enemys < Make_enemys) {
			if (!enemy[i].flg) {
				made_enemys++;
				enemy[i].flg = true;
				enemy[i].pos = GetRand(3);
				GetEnemyPos(&enemy[i].NowX, &enemy[i].NowY, enemy[i].pos);
				enemy[i].speed = SetEnemySpeed();
				enemy->Enemy_cnt++;
			}
		}
	}

}

int Enemy::GetEnemyMakes(int died_enemy) {
	if (died_enemy < 10)return 3;
	else if (died_enemy < 20)return 5;
	else if (died_enemy < 30)return 10;
	else return -1;
}

int GetEnemyVector() {
	int Enemy_vect = GetRand(9);
	if (Enemy_vect >= 0 && Enemy_vect < 3)return RIGHT;
	else if (Enemy_vect >= 3 && Enemy_vect < 6)return LEFT;
	else if (Enemy_vect >= 6 && Enemy_vect < 8)return UP;
	else if (Enemy_vect >= 8 && Enemy_vect < 10)return DOWN;
	else return -1;
}

void Enemy::GetEnemyPos(int* enemy_NowX, int* enemy_NowY, int enemy_pos) {
	switch (enemy_pos) {
	case 0:
		*enemy_NowX = -30;
		*enemy_NowY = 100;
		break;
	case 1:
		*enemy_NowX = -30;
		*enemy_NowY = 410;
		break;
	case 2:
		*enemy_NowX = 670;
		*enemy_NowY = 380;
		break;
	case 3:
		*enemy_NowX = 670;
		*enemy_NowY = 380;
		break;
	default:
		break;
	}
}



void Enemy::DeleteEnemy(Enemy* enemy, int num) {
	enemy[num].flg = false;
	enemy->Enemy_cnt--;
	enemy[num].Spawn_flg = false;
	enemy[num].Enemy_time = 0;
}

void Enemy::CheckEnemyAlive(Enemy* enemy) {
	int i = 0;
	for (i = 0; i < 10; i++) {
		if (enemy[i].flg == true) {
			Enemy_AliveFlg = true;
			break;
		}
	}
	if (i >= 10) {
		Enemy_AliveFlg = false;
	}
}

void Enemy::CheckEnemyIntoArea(Enemy* enemy) {
	int NewEnemy_num[6] = { 0,0,0,0,0,0 };
	for (int i = 0; i < 10; i++) {
		if (enemy[i].flg) {
			switch (enemy[i].Enemy_Area)
			{
			case 0:
				NewEnemy_num[0]++;
				break;
			case 1:
				NewEnemy_num[1]++;
				break;
			case 2:
				NewEnemy_num[2]++;
				break;
			case 3:
				NewEnemy_num[3]++;
				break;
			case 4:
				NewEnemy_num[4]++;
				break;
			case 5:
				NewEnemy_num[5]++;
				break;
			default:
				continue;
			}
		}
	}
	for (int j = 0; j < 6; j++) {
		EnemyIntoArea[j] = NewEnemy_num[j];
	}
}

int Enemy::GetEnemyX() const {
	return NowX;
}

int Enemy::GetEnemyY() const {
	return NowY;
}

bool Enemy::GetEnemyFlg() const {
	return flg;
}

int Enemy::GetDied_enemy() const {
	return Died_enemy;
}

bool Enemy::GetEnemyAliveFlg(Enemy* enemy) {
	return Enemy_AliveFlg;
}

int Enemy::GetScore() const {
	return Score;
}

void Enemy::SetScore() {
	Score += ((Combo / 10) + 1) * 100;
}

int Enemy::GetCombo() const {
	return Combo;
}

void Enemy::SetCombo(int combo_flg) {
	if (combo_flg) {
		Combo++;
	}
	else {
		Combo = 0;
	}

}

bool Enemy::GetMissFlg() {
	return Missflg;
}

//int Enemy::GetEnemy_Area() const {
//	return Enemy_Area;
//}

int Enemy::GetEnemyIntoArea(int num) const {
	return EnemyIntoArea[num];
}

int Enemy::GetMissSE() {
	return MissingSE;
}
