#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	bool flg;
	float x;
	int y;
	int pos;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	bool Spawn_flg;
public:
	void InitEnemy(Enemy* enemy);		//‰á‰Šú‰»ŠÖ”
	void DrawEnemy(int enemy_x,int enemy_y) const;		//‰á•`‰æŠÖ”
	void MoveEnemy(Enemy* enemy);		//‰áˆÚ“®ŠÖ”
	void CreateEnemy(Enemy* enemy);		//‰á¶¬ŠÖ”
	void GetEnemyPos(float* enemy_x, int* enemy_y, int enemy_pos);					//‰áoŒ»ˆÊ’uŒˆ’èŠÖ”
	float GetEnemyX() const;
	int GetEnemyY() const;

};