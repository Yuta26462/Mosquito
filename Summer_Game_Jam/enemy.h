#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	int pos;
	int NowX, NowY;       //���ݒn
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
	void InitEnemy(Enemy* enemy);		//�Ꮙ�����֐�
	void DrawEnemy() const;		//��`��֐�
	//void Drawene(Enemy enmey) const; int enemy_x, int enemy_y, bool flg/*, bool* died_flg*/
	void MoveEnemy(int time);		//��ړ��֐�
	int SetEnemySpeed();					
	void CreateEnemy(int Make_enemys);		//�ᐶ���֐�
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//��o���ʒu����֐�
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