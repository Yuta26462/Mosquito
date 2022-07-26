#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	int pos;
	int NowX, NowY;       //Œ»İ’n
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
	void InitEnemy(Enemy* enemy);		//‰á‰Šú‰»ŠÖ”
	void DrawEnemy(int enemy_x,int enemy_y,bool flg) const;		//‰á•`‰æŠÖ”
	void MoveEnemy(Enemy* enemy, int time);		//‰áˆÚ“®ŠÖ”
	void CreateEnemy(Enemy* enemy);		//‰á¶¬ŠÖ”
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//‰áoŒ»ˆÊ’uŒˆ’èŠÖ”
	void DeleteEnemy(Enemy* enemy ,int num);
	int GetEnemyX() const;
	int GetEnemyY() const;
	bool GetEnemyFlg() const;
	int GetDied_enemy()const;
	bool GetEnemyDieFlg() const;
};

int GetEnemyVector();