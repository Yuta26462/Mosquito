#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	bool flg;
	float x;
	int y;
	int pos;
	int Move_X;
	int Move_Y;
	float Enemy_angle;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	bool Spawn_flg;
public:
	void InitEnemy(Enemy* enemy);		//蚊初期化関数
	void DrawEnemy(int enemy_x,int enemy_y) const;		//蚊描画関数
	void MoveEnemy(Enemy* enemy);		//蚊移動関数
	void CreateEnemy(Enemy* enemy);		//蚊生成関数
	void ChangeAngle(Enemy* enemy,int num);		//蚊角度変更関数
	void GetEnemyPos(float* enemy_x, int* enemy_y, int enemy_pos);					//蚊出現位置決定関数
	float GetEnemyX() const;
	int GetEnemyY() const;

};