#include "enemy.h"
#include "main.h"
#define _USE_MATH_DEFINES
#include <math.h>
#include "DxLib.h"

#define SCREEN_WIDTH 1280
#define SCREEN_HIGHT 960

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

void Enemy::DrawEnemy(int enemy_x, int enemy_y) const{
	DrawCircle(enemy_x, enemy_y, 10, 0x000000, FALSE);
	//DrawRotaGraph(enemy_x, enemy_y, 10, 0.2, 0, Title_img, TRUE, FALSE);
}

void Enemy::MoveEnemy(Enemy* enemy) {
	if (timer++ % 25 == 0 && enemy->Enemy_cnt <= 10) {
		enemy->CreateEnemy(enemy,enemy->Died_enemy);
	}
	//if (timer % 2) {
	for (int i = 0; i < 10; i++) {

		//ボールの移動
		enemy[i].NowX += enemy->Move_X;
		enemy[i].NowY += enemy->Move_Y;

		//壁・天井での反射
		if (enemy[i].NowX < 5 || enemy[i].NowX > SCREEN_WIDTH - 5)      //横の壁
		{
			if (enemy[i].NowX < 5) {
				enemy[i].NowX = 5;
			}
		if (enemy[i].flg) {

			if ((enemy[i].x <= 20 || enemy[i].x >= 620) && !enemy[i].Spawn_flg) {
				if (enemy[i].pos <= 1) {
					enemy[i].x += 20;
				}
				else
				{
					enemy[i].x -= 20;
				}
			}
			else {
				enemy[i].NowX = SCREEN_WIDTH - 5;
				enemy[i].Spawn_flg = true;
			}

			if (enemy[i].Enemy_time++ % 300) {
				enemy[i].Enemy_vector = GetRand(3);
			}
			if (enemy[i].Spawn_flg) {
				switch (enemy[i].Enemy_vector) {
				case UP:
					enemy[i].y -= 15;
					break;
				case DOWN:
					enemy[i].y += 15;
					break;
				case RIGHT:
					if (enemy[i].pos <= 1) {
						enemy[i].x += 15;
					}
					else
					{
						enemy[i].x += 10;
					}
					break;
				case LEFT:
					if (enemy[i].pos <= 1) {
						enemy[i].x -= 10;
					}
					else
					{
						enemy[i].x -= 15;
					}
					break;
				default:
					break;
				}
				/*if (Enemy_vector <= 1) {
					enemy[i].x += (GetRand(2) - 1);
				}
				else {
					enemy[i].y += (GetRand(2) - 1);
				}*/
			}
		if (enemy[i].NowY < 5)                         //上の壁
		{
			enemy[i].Enemy_angle = (1 - enemy[i].Enemy_angle);
			ChangeAngle(enemy,i);
		}

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


			if (enemy[i].Spawn_flg && (enemy[i].x < -5 || enemy[i].x > 645 || enemy[i].y < -5 || enemy[i].y > 485)) {
				enemy[i].flg = false;
				enemy[i].Spawn_flg = false;
				enemy[i].Enemy_time = 0;
				enemy->Enemy_cnt--;
			}
		}
	}
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
}

void Enemy::CreateEnemy(Enemy* enemy,int died_enemy) {
	for (int i = 0; i < 10; i++) {
		if (!enemy[i].flg) {
			enemy[i].flg = true;
			enemy[i].pos = GetRand(3);
			GetEnemyPos(&enemy[i].NowX, &enemy[i].NowY, enemy[i].pos);
			enemy[i].Enemy_angle = 0.625;
			ChangeAngle(enemy, i);
			enemy->Enemy_cnt++;
		}
	}
}

void Enemy::GetEnemyPos(float* enemy_NowX, int* enemy_NowY, int enemy_pos) {
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

void Enemy::ChangeAngle(Enemy* enemy, int num) {
	float rad = enemy[num].Enemy_angle * (float)M_PI * 2;
	Move_X = (int)(5 * cosf(rad));
	Move_Y = (int)(5 * sinf(rad));
}

float Enemy::GetEnemyX() const{
	return x;
}

int Enemy::GetEnemyY() const {
	return y;
}



