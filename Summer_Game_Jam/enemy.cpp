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

//static int timer = 0;
//int GameMain::Enemy_cnt;

//void Enemy::Drawene(Enemy* enemy) {
//	DrawString(0, 0, "aa", 0x000000);
//}

void Enemy::InitEnemy(Enemy* enemy) {
	for (int i = 0; i < 10; i++) {
		enemy[i].flg = false;
		enemy[i].NowX = 0;
		enemy[i].NowY = 0;
		enemy[i].pos = 0;
		enemy[i].Enemy_time = 0;
		enemy[i].Spawn_flg = false;
	}
	enemy->Died_enemy = 0;
	enemy->Enemy_cnt = 0;
}

void Enemy::DrawEnemy(Enemy enemy) const {
	static int DieImg_Tyme = 0;
	if (enemy.flg) {
		DrawRotaGraph(enemy.GetEnemyX(), enemy.GetEnemyY(), 0.1, 0, Enemy_img, TRUE, FALSE);
		//DrawFormatString(enemy.GetEnemyX(), enemy.GetEnemyY(), 0x000000, "%d", enemy.Died_flg);


	}
	else if (enemy.Died_flg) {
		if (60 > DieImg_Tyme++)DrawRotaGraph(enemy.GetEnemyX(), enemy.GetEnemyY(), 0, 1, 0, Die_Enemy_img, TRUE, FALSE);
		else {
			enemy.Died_flg = false;
			DieImg_Tyme = 0;
		}
	}
}

void Enemy::MoveEnemy(Enemy* enemy, int time) {
	if (time % 60 == 0 && enemy->Enemy_cnt <= enemy->GetEnemyMakes(enemy->Died_enemy)) {
		enemy->CreateEnemy(enemy, 3/*,enemy->Died_enemy*/);
	}
	if (time % 2) {
		for (int i = 0; i < 20; i++) {
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
					enemy[i].Enemy_vector = GetRand(3);//GetEnemyVector();
				}
				if (enemy[i].Spawn_flg) {
					switch (enemy[i].Enemy_vector) {
					case UP:
						enemy[i].NowY -= Move_Y;
						break;
					case DOWN:
						enemy[i].NowY += Move_Y;
						break;
					case RIGHT:
						if (enemy[i].pos <= 1) {
							enemy[i].NowX += Move_X;
						}
						/*else
						{
							enemy[i].NowX += Move_X - 5;
						}*/
						break;
					case LEFT:
						if (enemy[i].pos > 1) {
							enemy[i].NowX -= Move_X;
						}
						/*else
						{
							enemy[i].NowX -= Move_X - 5;
						}*/
						break;
					default:
						break;
					}


					enemy[i].Enemy_Area = enemy[i].NowX / 213;
					if (enemy[i].NowY > 240)enemy[i].Enemy_Area += 3;
					if (AttackFlg[enemy[i].Enemy_Area]) {
						enemy->Died_enemy++;
						enemy->SetEnemyDflg(enemy, i);
						DeleteEnemy(enemy, i);
					}

					if (enemy[i].Spawn_flg && (enemy[i].NowX < -5 || enemy[i].NowX > 645 || enemy[i].NowY < -5 || enemy[i].NowY > 485)) {
						DeleteEnemy(enemy, i);
					}
				}
			}
		}
	}
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
				enemy->Enemy_cnt++;
			}
		}
	}

}

int Enemy::GetEnemyMakes(int died_enemy) {
	if (died_enemy < 20)return 3;
	else if (died_enemy < 40)return 5;
	else if (died_enemy < 60)return 10;
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
		*enemy_NowY = 70;
		break;
	case 1:
		*enemy_NowX = -30;
		*enemy_NowY = 410;
		break;
	case 2:
		*enemy_NowX = 670;
		*enemy_NowY = 70;
		break;
	case 3:
		*enemy_NowX = 670;
		*enemy_NowY = 410;
		break;
	default:
		break;
	}
}

//void Enemy::ChangeAngle(Enemy* enemy, int num) {
//	float rad = enemy[num].Enemy_angle * (float)M_PI * 2;
//	Move_X = (int)(5 * cosf(rad));
//	Move_Y = (int)(5 * sinf(rad));
//}

void Enemy::DeleteEnemy(Enemy* enemy, int num) {
	enemy[num].flg = false;
	enemy[num].Died_flg = false;
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


int Enemy::GetEnemyX() const {
	return NowX;
}

int Enemy::GetEnemyY() const {
	return NowY;
}

bool Enemy::GetEnemyFlg() const {
	return flg;
}

void Enemy::SetEnemyDflg(Enemy* enemy, int num) {
	enemy[num].Died_flg = true;
}

int Enemy::GetDied_enemy() const {
	return Died_enemy;
}

bool Enemy::GetEnemyAliveFlg(Enemy* enemy) {
	return Enemy_AliveFlg;
}
//int Enemy::GetEnemy_Area() const {
//	return Enemy_Area;
//}


////ボールの移動
		//enemy[i].NowX += enemy->Move_X;
		//enemy[i].NowY += enemy->Move_Y;
//壁・天井での反射
		//if (enemy[i].NowX < 5 || enemy[i].NowX > SCREEN_WIDTH - 5)      //横の壁
		//{
		//	if (enemy[i].NowX < 5) {
		//		enemy[i].NowX = 5;
		//	}
/*if (Enemy_vector <= 1) {
					enemy[i].x += (GetRand(2) - 1);
				}
				else {
					enemy[i].y += (GetRand(2) - 1);
				}*/

				//if (enemy[i].NowY < 5)                         //上の壁
				//{
				//	enemy[i].Enemy_angle = (1 - enemy[i].Enemy_angle);
				//	ChangeAngle(enemy,i);
				//}

			//	//画面下を超えたらゲームオーバー
			//	if (enemy[i].NowY > SCREEN_HIGHT + 5) {
			//		ballState = BALL_STATE::IDLE;
			//		}
			//	}


			//	if (ballState != BALL_STATE::IDLE) {
			//		enemy[i].NowX += g_MoveX;
			//		enemy[i].NowY += g_MoveY;
			//	}
			//	else {
			//		enemy[i].NowX = bar.getX() + (bar.getWidth() / 2);
			//		enemy[i].NowY = bar.getY() - ((bar.getHeight() + radius) / 2);
			//	}
			//}
		//}
	//for (int i = 0; i < 10; i++) {

	//	//ボールの移動
	//	enemy[i].x += enemy->Move_X;
	//	enemy[i].y += enemy->Move_Y;

	//	//壁・天井での反射
	//	if (enemy[i].x < 5 || enemy[i].x > SCREEN_WIDTH - 5)      //横の壁
	//	{
	//		if (enemy[i].x < 5) {
	//			enemy[i].x = 5;
	//		}
	//		else {
	//			enemy[i].x = SCREEN_WIDTH - 5;
	//		}
	//		enemy[i].Enemy_angle = (1 - enemy[i].Enemy_angle) + 0.5f;
	//		if (enemy[i].Enemy_angle > 1) enemy[i].Enemy_angle -= 1.0f;
	//		ChangeAngle(enemy,i);
	//	}

	//	if (enemy[i].y < 5)                         //上の壁
	//	{
	//		enemy[i].Enemy_angle = (1 - enemy[i].Enemy_angle);
	//		ChangeAngle(enemy,i);
	//	}

	//	//画面下を超えたらゲームオーバー
	//	if (enemy[i].y > SCREEN_HIGHT + 5) {
	//		ballState = BALL_STATE::IDLE;
	//		}
	//	}


	//	if (ballState != BALL_STATE::IDLE) {
	//		enemy[i].x += g_MoveX;
	//		enemy[i].y += g_MoveY;
	//	}
	//	else {
	//		enemy[i].x = bar.getX() + (bar.getWidth() / 2);
	//		enemy[i].y = bar.getY() - ((bar.getHeight() + radius) / 2);
	//	}
	//}