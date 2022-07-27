#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	int pos;
	int NowX, NowY;       //Œ»İ’n
	int speed;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	int Died_enemy;
	bool Spawn_flg;
	int Enemy_Area;
	bool Enemy_AliveFlg;
	int EnemyIntoArea[6];
	int Score;
	int Combo;
	bool Missflg;
	int MissingSE;
	int Drawtimer;
public:
	//Enemy();
	bool flg;
	void InitEnemy(Enemy* enemy);		//‰á‰Šú‰»ŠÖ”
	void DrawEnemy() const;		//‰á•`‰æŠÖ”
	//void Drawene(Enemy enmey) const; int enemy_x, int enemy_y, bool flg/*, bool* died_flg*/
	void MoveEnemy(int time);		//‰áˆÚ“®ŠÖ”
	int SetEnemySpeed();					
	void CreateEnemy(int Make_enemys);		//‰á¶¬ŠÖ”
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//‰áoŒ»ˆÊ’uŒˆ’èŠÖ”
	void DeleteEnemy(int num);
	void CheckEnemyAlive(Enemy* enemy);
	void CheckEnemyIntoArea(Enemy* enemy);
	bool GetEnemyFlg() const;
	int GetEnemyX() const;
	int GetEnemyY() const;
	int GetDied_enemy() const;
	int SetEnemyMakes(int time);
	bool GetEnemyAliveFlg(Enemy* enemy);
	int GetScore()const;
	void SetScore();
	int GetCombo()const;
	void SetCombo(int combo_flg);
	//int GetEnemy_Area() const;
	int GetEnemyIntoArea(int num)const;
	bool GetMissFlg();
	int GetMissSE();
};
extern Enemy enemy[15];

int GetEnemyVector();
int SetEnemySpawn(int timelimit);