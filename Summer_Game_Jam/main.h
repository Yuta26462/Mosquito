#pragma once

extern int	g_KeyFlg;			// ���̓L�[���
//�摜�p�ϐ�
extern int Title_img;
extern int GameMain_img;
extern int Result_img;
extern int Enemy_img;
extern int Die_Enemy_img;
extern int PlayCount;
extern int MaxScore;
extern int NewScore;

int GetSelectX(void);		//�A�i���O�X�e�B�b�N���͎擾	-1:��	1�F��
int GetSelectY(void);		//�A�i���O�X�e�B�b�N���͎擾	-1:��	1�F��

int GetJoyPadX(void);		//�A�i���O�X�e�B�b�NX���W���͎擾
int GetJoyPadY(void);		//�A�i���O�X�e�B�b�NY���W���͎擾

int ReadRanking(void);