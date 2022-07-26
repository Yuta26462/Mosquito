#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	int pos;
	int NowX, NowY;       //現在地
	float Enemy_angle;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	int Died_enemy;
	bool Spawn_flg;
	int Enemy_Area;
	bool Enemy_Die;
public:
	bool flg;
	void InitEnemy(Enemy* enemy);		//蚊初期化関数
	void DrawEnemy(int enemy_x,int enemy_y,bool flg) const;		//蚊描画関数
	void MoveEnemy(Enemy* enemy, int time);		//蚊移動関数
	void CreateEnemy(Enemy* enemy);		//蚊生成関数
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//蚊出現位置決定関数
	void DeleteEnemy(Enemy* enemy ,int num);
	int GetEnemyX() const;
	int GetEnemyY() const;
	bool GetEnemyFlg() const;
	int GetDied_enemy()const;
	bool GetEnemyDieFlg() const;
};

int GetEnemyVector();