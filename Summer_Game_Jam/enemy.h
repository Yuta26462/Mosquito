#pragma once
#define RandMaxX 1280
#define RandMaxY 960
#define Radius 5  //“G‚Ì”¼Œa

static bool flg;
static int img;
static int PosX, PosY;    //Œ»İ‚ÌÀ•W
static int MoveX, MoveY;  //ˆÚ“®—Ê
static int speed;
static int score;

void DrawEnemy();
void MoveEnemy();