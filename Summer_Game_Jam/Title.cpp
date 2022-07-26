#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"
#include"player.h"

void Title::Initialize() const {
	Player_Initialize();
	PlaySoundMem(Title_BGM, DX_PLAYTYPE_BACK, TRUE);
}
void Title::Finalize() const{
	Player_Finalize();
}

Title::Title() {
	MenuFont = CreateFontToHandle("MenuFont", 40, 1, DX_FONTTYPE_ANTIALIASING_EDGE_4X4);;
	Pointer_img = LoadGraph("Resource/Images/pointer.png");
	Help_img = LoadGraph("Resource/Images/help.png");
	Credit_img = LoadGraph("Resource/Images/Credit.png");
	Menu_img = LoadGraph("Resource/Images/menu.png");
	OK_SE = LoadSoundMem("Resource/Sounds/SE/OK.wav");
	Selecter_SE = LoadSoundMem("Resource/Sounds/SE/Selecter.wav");
	Return_SE = LoadSoundMem("Resource/Sounds/SE/Return.wav");
	Title_BGM = LoadSoundMem("Resource/Sounds/BGM/Title.wav");
	SelectNo = 0;
	MenuChangeFlg = 0;
}

BaseScene* Title::Update() {

	{	//メニュー
		if (GetSelectY() == -1 && SelectNo > 0) {
				SelectNo--;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}
		if (GetSelectY() == 1 && SelectNo < 3){
				SelectNo++;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}

		if (g_KeyFlg & 16) {
			PlaySoundMem(OK_SE, DX_PLAYTYPE_BACK, TRUE);
			switch (SelectNo)
			{
			case 0:
				return new GameMain();
				break;
			case 1:
				//操作説明
				MenuChangeFlg = 1;
				break;
			case 2:
				//クレジット
				MenuChangeFlg = 2;
				break;
			case 3:
				DxLib_End();
				break;
			default:
				break;
			}
		}

		if (MenuChangeFlg == 1 || MenuChangeFlg == 2) {
			//Bボタンで戻る
			if (g_KeyFlg & 32) { PlaySoundMem(Return_SE, DX_PLAYTYPE_BACK, TRUE); MenuChangeFlg = 0; }
		}

		return this;
	}
}

void Title::Draw() const {

	if (MenuChangeFlg == 1) {//操作説明
		DrawGraph(0, 0, Help_img, FALSE);
		DrawString(100, 200, "蚊が６つに分けられた枠内に出現するよ！", 0xDC6560);
		DrawString(100, 230, "スティックや十字ボタンで蚊がいるところに合わせて、", 0xDC6560);
		DrawString(100, 260, "Aボタンを押したら蚊を倒すことができるよ！", 0xDC6560);
		DrawString(100, 290, "間違えずに連続で蚊を倒していくと", 0xDC6560);
		DrawString(100, 320, "コンボが発生して、獲得できるスコアが増えていくから", 0xDC6560);
		DrawString(100, 350, "頑張ってたくさん倒そう！！", 0xDC6560);
		DrawStringToHandle(120, 400, "Bボタンでタイトルに戻る", 0xFFFFFF, MenuFont, 0xDC6560);
	}
	else if (MenuChangeFlg == 2) {//クレジット
		DrawGraph(0, 0, Credit_img, FALSE);
		DrawString(100, 200, "タイトル　　　蚊", 0xDC6560);
		DrawString(100, 230, "制作者　　　　国際電子ビジネス専門学校 Lチーム", 0xDC6560);
		DrawString(100, 260, "素材利用", 0xDC6560);
		DrawString(100, 290, "画像　　　　みんちりえ（ https://min-chi.material.jp/ ）", 0xDC6560);
		DrawString(100, 320, "BGM", 0xDC6560);
		DrawString(100, 350, "SE", 0xDC6560);


	}else {
		//タイトル画像表示
		DrawGraph(0, 0, Title_img, FALSE);
		DrawStringToHandle(230, 250, "スタート", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 295, "操作説明", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 340, "クレジット", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawStringToHandle(230, 385, "ゲーム終了", 0xFFFFFF, MenuFont, 0xDC6560);
		DrawCircleAA(200, 270 + SelectNo * 45, 16.0f, 3, 0xDC6560, TRUE);
		

	}
}