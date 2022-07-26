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
	bool Enemy_AliveFlg;
	int Died_flg;
	mutable int ComboTimer;
	mutable bool Combo_displayFlg;
	mutable int DeadEnemynum;

public:
	bool flg;
	void InitEnemy(Enemy* enemy);		//‰á‰Šú‰»ŠÖ”
	void DrawEnemy(int enemy_x, int enemy_y, bool flg/*, bool* died_flg*/) const;		//‰á•`‰æŠÖ”
	//void Draw(Enemy)
	void MoveEnemy(Enemy* enemy, int time);		//‰áˆÚ“®ŠÖ”
	void CreateEnemy(Enemy* enemy,int Make_enemys);		//‰á¶¬ŠÖ”
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//‰áoŒ»ˆÊ’uŒˆ’èŠÖ”
	void DeleteEnemy(Enemy* enemy ,int num);
	void CheckEnemyAlive(Enemy* enemy);
	bool GetEnemyFlg() const;
	int GetEnemyX() const;
	int GetEnemyY() const;
	int GetDied_enemy() const;
	int GetEnemyDflg() const;
	int GetEnemyMakes(int died_enemy);
	bool GetEnemyAliveFlg(Enemy* enemy);
	//int GetEnemy_Area() const;
};

int GetEnemyVector();