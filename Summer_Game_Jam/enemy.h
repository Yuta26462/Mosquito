#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	int pos;
	int NowX, NowY;       //���ݒn
	float Enemy_angle;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	int Died_enemy;
	bool Spawn_flg;
	int Enemy_Area;
	bool Enemy_AliveFlg;
	bool Died_flg;
public:
	bool flg;
	void InitEnemy(Enemy* enemy);		//�Ꮙ�����֐�
	void DrawEnemy(Enemy enemy) const;		//��`��֐�
	//void Drawene(Enemy enmey) const; int enemy_x, int enemy_y, bool flg/*, bool* died_flg*/
	void MoveEnemy(Enemy* enemy, int time);		//��ړ��֐�
	void CreateEnemy(Enemy* enemy,int Make_enemys);		//�ᐶ���֐�
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//��o���ʒu����֐�
	void DeleteEnemy(Enemy* enemy ,int num);
	void CheckEnemyAlive(Enemy* enemy);
	bool GetEnemyFlg() const;
	int GetEnemyX() const;
	int GetEnemyY() const;
	int GetDied_enemy() const;
	void SetEnemyDflg(Enemy* enemy,int num);
	int GetEnemyMakes(int died_enemy);
	bool GetEnemyAliveFlg(Enemy* enemy);
	//int GetEnemy_Area() const;
};

int GetEnemyVector();