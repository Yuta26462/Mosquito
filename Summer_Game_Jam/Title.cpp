#include "Title.h"
#include "GameMain.h"
#include "Result.h"
#include "main.h"
#include "DxLib.h"
#include"player.h"
#include "sleep.h"

void Title::Initialize() const {
	Sleep_Initialize();
	Player_Initialize();
	Sleep_Initialize();
	PlaySoundMem(Title_BGM, DX_PLAYTYPE_BACK, TRUE);
}
void Title::Finalize() const{
	Sleep_Finalize();
	Player_Finalize();
	Sleep_Finalize();
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
		if (GetSelectY() == -1 && SelectNo > 0 && MenuChangeFlg == 0) {
				SelectNo--;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}
		if (GetSelectY() == 1 && SelectNo < 3 && MenuChangeFlg == 0){
				SelectNo++;
				PlaySoundMem(Selecter_SE, DX_PLAYTYPE_BACK, TRUE);
		}

		if (g_KeyFlg & 16) {
			PlaySoundMem(OK_SE, DX_PLAYTYPE_BACK, TRUE);
			switch (SelectNo)
			{
			case 0:
				StopSoundMem(Title_BGM);
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
		DrawString(140, 160, "蚊が６つに分けられた枠内に出現するよ！", 0xffffff);
		DrawString(140, 190, "スティックで蚊がいるところにカーソルを合わせて、", 0xffffff);
		DrawString(140, 220, "Aボタンを押したら蚊を倒すことができるよ！", 0xffffff);
		DrawString(140, 250, "間違えずに連続で蚊を倒していくと", 0xffffff);
		DrawString(140, 280, "コンボが発生して、獲得できるスコアが増えていくから", 0xffffff);
		DrawString(140, 310, "頑張ってたくさん倒そう！！", 0xffffff);
		DrawStringToHandle(90, 400, "Bボタンでタイトルに戻る", 0xFFFFFF, MenuFont, 0xDC6560);
	}
	else if (MenuChangeFlg == 2) {//クレジット
		DrawGraph(0, 0, Credit_img, FALSE);
		DrawString(100, 130, "タイトル      蚊", 0xffffff);
		DrawString(100, 160, "制作者        国際電子ビジネス専門学校 Lチーム", 0xffffff);
		DrawString(130, 190, "素材利用", 0xffffff);
		DrawString(100, 220, "画像　　 　 みんちりえ        ", 0xffffff);
		DrawString(100, 250, "            いらすとや        ", 0xffffff);
		DrawString(100, 280, "BGM         ", 0xffffff);
		DrawString(100, 310, "            ", 0xffffff);
		DrawString(100, 340, "SE          魔王魂　　　　     【森田交一】システム49", 0xffffff);
		DrawString(100, 370, "            効果音ラボ　　　   【効果音ラボ】キャンセル5", 0xffffff);
		DrawString(100, 400, "            効果音工房　　　   【効果音工房】カーソル移動-11", 0xffffff);
		DrawString(100, 430, "            ニコニ・コモンズ   【でぃめとろ丼】夜の虫の音 ", 0xffffff);


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