#pragma once

enum Enemy_Vecor { UP, DOWN, RIGHT, LEFT };

class Enemy {
private:
	bool flg;
	int pos;
	int NowX, NowY;       //���ݒn
	//int Move_X, Move_Y;   �ړ���
	float Enemy_angle;
	int Enemy_cnt;
	int Enemy_time;
	int Enemy_vector;
	int Died_enemy;
	bool Spawn_flg;
public:
	void InitEnemy(Enemy* enemy);		//�Ꮙ�����֐�
	void DrawEnemy(int enemy_x,int enemy_y) const;		//��`��֐�
	void MoveEnemy(Enemy* enemy);		//��ړ��֐�
	void CreateEnemy(Enemy* enemy);		//�ᐶ���֐�
	void ChangeAngle(Enemy* enemy,int num);		//��p�x�ύX�֐�
	void GetEnemyPos(int* enemy_x, int* enemy_y, int enemy_pos);					//��o���ʒu����֐�
	float GetEnemyX() const;
	int GetEnemyY() const;
};