#pragma once
#define RandMaxX 1280
#define RandMaxY 960
#define Radius 5  //�G�̔��a

static bool flg;
static int img;
static int PosX, PosY;    //���݂̍��W
static int MoveX, MoveY;  //�ړ���
static int speed;
static int score;

void DrawEnemy();
void MoveEnemy();