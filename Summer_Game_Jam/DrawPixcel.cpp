#include"DxLib.h"

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); //ウィンドウモードを有効
	SetWindowSizeChangeEnableFlag(FALSE, FALSE); //ウィンドウを手動で変更できないようにし、ウィンドウのサイズに合わせて拡大しないようにする
	SetWindowSize(640, 480); //画面サイズを横640、480に変更
	if (DxLib_Init() == -1) return -1;

	DrawBox(320, 240,500, 600, 0xffffff,FALSE);
	DrawString(100, 100, "Hallo World", 0xffffff);

	WaitKey();

	DxLib_End();

	return 0;
}