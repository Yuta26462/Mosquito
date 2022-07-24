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
	void InitEnemy(Enemy* enemy);		//�Ꮙ�����֐�
	void DrawEnemy(int enemy_x,int enemy_y) const;		//��`��֐�
	void MoveEnemy(Enemy* enemy);		//��ړ��֐�
	void CreateEnemy(Enemy* enemy);		//�ᐶ���֐�
	void GetEnemyPos(float* enemy_x, int* enemy_y, int enemy_pos);					//��o���ʒu����֐�
	float GetEnemyX() const;
	int GetEnemyY() const;

};