#pragma once

static int ImageSleep;		//�Q�Ă�摜
static int ImageSleep2;		//�Q�ڂ��摜
static int gauge = 0, gaugeMax = 100;
static int black = GetColor(0, 0, 0);
static int blue = GetColor(0, 255, 255);
static int red = GetColor(255, 255, 255);

void Sleep_Initialize();
void Sleep_Finalize();
void Sleep_Update();
void Sleep_Draw();