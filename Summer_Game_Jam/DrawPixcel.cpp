#include"DxLib.h"

int WINAPI WinMain(HINSTANCE hlnstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	ChangeWindowMode(TRUE); //�E�B���h�E���[�h��L��
	SetWindowSizeChangeEnableFlag(FALSE, FALSE); //�E�B���h�E���蓮�ŕύX�ł��Ȃ��悤�ɂ��A�E�B���h�E�̃T�C�Y�ɍ��킹�Ċg�債�Ȃ��悤�ɂ���
	SetWindowSize(640, 480); //��ʃT�C�Y����640�A480�ɕύX
	if (DxLib_Init() == -1) return -1;

	DrawBox(320, 240,500, 600, 0xffffff,FALSE);
	DrawString(100, 100, "Hallo World", 0xffffff);

	WaitKey();

	DxLib_End();

	return 0;
}