#include "enemy.h"
#include "player.h"
#include "main.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "DxLib.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HIGHT 960
#define Move_X 15
#define Move_Y 15

static int timer = 0;


void Enemy::InitEnemy(Enemy* enemy) {
	for (int i = 0; i < 10; i++) {
		enemy[i].flg = false;
		enemy[i].NowX = 0;
		enemy[i].NowY = 0;
		enemy[i].pos = 0;
		enemy[i].Enemy_time = 0;
		enemy[i].Spawn_flg = false;
	}
	enemy->Enemy_cnt = 0;
}

void Enemy::DrawEnemy(int enemy_x, int enemy_y, bool flg) const{
	if (flg) {
		DrawRotaGraph(enemy_x, enemy_y, 1.0, 0, Enemy_img, FALSE, FALSE);
		//DrawCircle(enemy_x, enemy_y, 10, 0x000000, FALSE);
	}
}

void Enemy::MoveEnemy(Enemy* enemy) {
	if (timer++ % 25 == 0 && enemy->Enemy_cnt <= 10) {
		enemy->CreateEnemy(enemy/*,enemy->Died_enemy*/);
	}
	if (timer % 2) {
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
						enemy[i].NowY -= Move_Y;
						break;
					case DOWN:
						enemy[i].NowY += Move_Y;
						break;
					case RIGHT:
						if (enemy[i].pos <= 1) {
							enemy[i].NowX += Move_X - 5;
						}
						else
						{
							enemy[i].NowY += Move_Y - 5;
						}
						break;
					case LEFT:
						if (enemy[i].pos <= 1) {
							enemy[i].NowX -= Move_X - 5;
						}
						else
						{
							enemy[i].NowX -= Move_Y - 5;
						}
						break;
					default:
						break;
					}

					enemy[i].Enemy_Area = enemy[i].NowX / 213;
					if (enemy[i].NowY > 240)enemy[i].Enemy_Area += 3;
					if (AttackFlg[enemy[i].Enemy_Area] || (enemy[i].Spawn_flg && (enemy[i].NowX < -5 || enemy[i].NowX > 645 || enemy[i].NowY < -5 || enemy[i].NowY > 485))) {
						DeleteEnemy(enemy, i);
					}
				}
			}
		}
	}
}
void Enemy::CreateEnemy(Enemy* enemy) {
	for (int i = 0; i < 10; i++) {
		if (!enemy[i].flg) {
			enemy[i].flg = true;
			enemy[i].pos = GetRand(3);
			GetEnemyPos(&enemy[i].NowX, &enemy[i].NowY, enemy[i].pos);
			enemy->Enemy_cnt++;
		}
	}
}

void Enemy::GetEnemyPos(int* enemy_NowX, int* enemy_NowY, int enemy_pos) {
	switch (enemy_pos) {
	case 0:
		*enemy_NowX = -30;
		*enemy_NowY = 50;
		break;
	case 1:
		*enemy_NowX = -30;
		*enemy_NowY = 430;
		break;
	case 2:
		*enemy_NowX = 670;
		*enemy_NowY = 50;
		break;
	case 3:
		*enemy_NowX = 670;
		*enemy_NowY = 430;
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

void Enemy::DeleteEnemy(Enemy* enemy,int num) {
	enemy[num].flg = false;
	enemy->Enemy_cnt--;
	enemy[num].Spawn_flg = false;
	enemy[num].Enemy_time = 0;
}

int Enemy::GetEnemyX() const{
	return NowX;
}

int Enemy::GetEnemyY() const {
	return NowY;
}

bool Enemy::GetEnemyFlg() const{
	return flg;
}



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