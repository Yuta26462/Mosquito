#pragma once

static int box_x, box_y;
static int WeaponImage;
static int Flyswatter_SE;
static int BoxNumber_x,BoxNumber_y;
static int AttackCount;
static float BoxColor;
extern int AreaNum;
extern bool AttackFlg;
extern int AttackInterval;

void Player_Initialize();
void Player_Finalize();
void Player_Update();
void Player_Draw();