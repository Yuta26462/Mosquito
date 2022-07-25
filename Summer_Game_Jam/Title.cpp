#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"

Title::Title() {
	SelectNo = 0;
}

BaseScene* Title::Update() {

	{	//メニュー
		if (GetSelectY() == -1) { if (SelectNo > 0)SelectNo--; }
		if (GetSelectY() == 1){if (SelectNo < 2)SelectNo++; }

		if (g_KeyFlg & 16) {
			switch (SelectNo)
			{
			case 0:
				return new GameMain();
				break;
			case 1:
				return new Result();
				break;
			case 2:
				return new Title();
				break;
			default:
				break;
			}
		}
	}

	//zキーでゲームメインへ移動
	if (g_KeyFlg & PAD_INPUT_A) {
		return new GameMain();
	}//スペースキーでゲーム終了
	else if (g_KeyFlg & PAD_INPUT_M) {
		return nullptr;
	}
	else {
		return this;
	}
}

void Title::Draw() const {
	//タイトル画像表示
	DrawGraph(0, 0, Title_img, FALSE);
	DrawString(100, 400, "zキーで次のシーンへ", 0x000000);
	DrawString(400, 400, "スペースキーで終了", 0x000000);
	DrawCircleAA(250, 270 + SelectNo * 50, 10.2f, 3, 0xFFFFFF, TRUE);
	DrawFormatString(200, 200, 0xFFFFFF, "%d", GetSelectX());
	DrawFormatString(200, 250, 0xFFFFFF, "%d", GetSelectY());
	DrawFormatString(200, 280, 0xFFFFFF, "SelectNo:%d", SelectNo);
}

void TitleMenu(void) {

}