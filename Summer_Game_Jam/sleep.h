#pragma once
#include "GameMain.h"

static int ImageSleep;		//�Q�Ă�摜
static int ImageSleep2;		//�Q�ڂ��摜
static int gauge = 0, gaugeMax = 20;
static int black = GetColor(0, 0, 0);
static int blue = GetColor(0, 255, 255);
static int red = GetColor(255, 255, 255);

void Sleep_Initialize();
void Sleep_Finalize();
void Sleep_Update(Enemy* enemy);
void Sleep_Draw();