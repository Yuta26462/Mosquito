#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	bool flg;
	int pos;
	int NowX, NowY;       //Œ»İ’n
	float Enemy_angle;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	int Died_enemy;
	bool Spawn_flg;
	int Enemy_Area;
	int Died_flg;
public:
	void InitEnemy(Enemy* enemy);		//‰á‰Šú‰»ŠÖ”
	void DrawEnemy(int enemy_x, int enemy_y, bool flg/*, bool* died_flg*/) const;		//‰á•`‰æŠÖ”
	//void Draw(Enemy)
	void MoveEnemy(Enemy* enemy, int time);		//‰áˆÚ“®ŠÖ”
	void CreateEnemy(Enemy* enemy);		//‰á¶¬ŠÖ”
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//‰áoŒ»ˆÊ’uŒˆ’èŠÖ”
	void DeleteEnemy(Enemy* enemy ,int num);
	bool GetEnemyFlg() const;
	int GetEnemyX() const;
	int GetEnemyY() const;
	int GetDied_enemy() const;
	int GetEnemyDflg() const;
};

int GetEnemyVector();