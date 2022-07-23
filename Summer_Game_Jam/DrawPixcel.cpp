#include "DxLib.h"

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	if (DxLib_Init() == -1) return -1;

	DrawBox(320, 240,500, 600, 0xffffff,FALSE);

	WaitKey();

	DxLib_End();

	return 0;
}