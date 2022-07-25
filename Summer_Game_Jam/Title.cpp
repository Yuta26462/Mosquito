#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"
#include"player.h"

void Title::Initialize() const {
	Player_Initialize();
}
void Title::Finalize() const{
	Player_Finalize();
}

Title::Title() {
	Pointer_img = LoadGraph("Resource/Images/pointer.png");
	Help_img = LoadGraph("Resource/Images/help.png");
	Credit_img = LoadGraph("Resource/Images/Credit.png");
	Menu_img = LoadGraph("Resource/Images/menu.png");
	SelectNo = 0;
	MenuChangeFlg = 0;
}

BaseScene* Title::Update() {

	{	//メニュー
		if (GetSelectY() == -1) { if (SelectNo > 0)SelectNo--; }
		if (GetSelectY() == 1){if (SelectNo < 3)SelectNo++; }

		if (g_KeyFlg & 16) {
			switch (SelectNo)
			{
			case 0:
				return new GameMain();
				break;
			case 1:
				MenuChangeFlg = 1;
				break;
			case 2:
				MenuChangeFlg = 2;
				break;
			case 3:
				return nullptr;
				break;
			default:
				break;
			}
		}

		if (MenuChangeFlg == 1 || MenuChangeFlg == 2) {
			if (g_KeyFlg & 32)MenuChangeFlg = 0;
		}

		return this;
	}

	////zキーでゲームメインへ移動
	//if (g_KeyFlg & PAD_INPUT_A) {
	//	return new GameMain();
	//}//スペースキーでゲーム終了
	//else if (g_KeyFlg & PAD_INPUT_Y) {
	//	return nullptr;
	//}
	//else {
	//	return this;
	//}
}

void Title::Draw() const {

	if (MenuChangeFlg == 1) {//操作説明
		DrawGraph(0, 0, Help_img, FALSE);
		DrawString(100, 200, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 230, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 260, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 290, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 320, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 350, "zキーで次のシーンへ", 0xDC6560);
	}
	else if (MenuChangeFlg == 2) {//クレジット
		DrawGraph(0, 0, Credit_img, FALSE);
		DrawString(100, 200, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 230, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 260, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 290, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 320, "zキーで次のシーンへ", 0xDC6560);
		DrawString(100, 350, "zキーで次のシーンへ", 0xDC6560);


	}else {
		//タイトル画像表示
		DrawGraph(0, 0, Title_img, FALSE);
		DrawString(100, 400, "zキーで次のシーンへ", 0x000000);
		DrawString(400, 400, "スペースキーで終了", 0x000000);
		DrawCircleAA(200, 270 + SelectNo * 45, 16.0f, 3, 0xDC6560, TRUE);
		DrawGraph(230, 250, Menu_img, TRUE);

	}
}