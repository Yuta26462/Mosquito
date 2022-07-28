#pragma once

extern int	g_KeyFlg;			// 入力キー情報
//画像用変数
extern int Title_img;
extern int GameMain_img;
extern int Result_img;
extern int Enemy_img;
extern int Die_Enemy_img;
extern int PlayCount;
extern int MaxScore;
extern int NewScore;

int GetSelectX(void);		//アナログスティック入力取得	-1:←	1：→
int GetSelectY(void);		//アナログスティック入力取得	-1:↑	1：↓

int GetJoyPadX(void);		//アナログスティックX座標入力取得
int GetJoyPadY(void);		//アナログスティックY座標入力取得

int ReadRanking(void);