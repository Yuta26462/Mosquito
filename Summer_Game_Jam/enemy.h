#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	bool flg;
	int pos;
	int NowX, NowY;       //現在地
	//int Move_X, Move_Y;   移動量
	float Enemy_angle;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	int Died_enemy;
	bool Spawn_flg;
public:
	void InitEnemy(Enemy* enemy);		//蚊初期化関数
	void DrawEnemy(int enemy_x,int enemy_y) const;		//蚊描画関数
	void MoveEnemy(Enemy* enemy);		//蚊移動関数
	void CreateEnemy(Enemy* enemy);		//蚊生成関数
	void ChangeAngle(Enemy* enemy,int num);		//蚊角度変更関数
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//蚊出現位置決定関数
	float GetEnemyX() const;
	int GetEnemyY() const;
};