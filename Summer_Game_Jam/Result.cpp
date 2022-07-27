#include "Result.h"
#include "Title.h"
#include "main.h"
#include "DxLib.h"
#include "sleep.h"
#include"GameMain.h"

Result::Result() {
	GameClear_BGM = LoadSoundMem("Resource/Sounds/BGM/GameClear.wav");
	GameOver_BGM = LoadSoundMem("Resource/Sounds/BGM/GameOver.wav");
	GameOver_Face = LoadGraph("Resource/Images/Player/GameOver_Face.png");
	Clear_Face = LoadGraph("Resource/Images/Player/Clear_Face.png");
	TextCount = 0;

	if (finishFlg == true) {
		PlaySoundMem(GameOver_BGM, DX_PLAYTYPE_BACK, TRUE);
	}else {
		PlaySoundMem(GameClear_BGM, DX_PLAYTYPE_BACK, TRUE);
	}
}

void Result::Initialize() const {

}
void Result::Finalize() const {

}

BaseScene* Result::Update() {
	TextCount++;
	//Bボタンでタイトルへ
	if (g_KeyFlg & 32) {
		if (finishFlg == true) {
			StopSoundMem(GameOver_BGM);
		}
		else {
			StopSoundMem(GameClear_BGM);
		}
		return new Title();
	}
	else {
		return this;
	}
}

void Result::Draw() const {
	//DrawGraph(0, 0, Result_img, FALSE);
	if (finishFlg == true) {
		DrawRotaGraph(270, 285, 2.0, 0, GameOver_Face, TRUE);
		if (TextCount > 60) {
			SetFontSize(40);
			DrawFormatString(230, 50, 0x000000, "撃退失敗...");
		}
		if (TextCount > 120) {
			//DrawRotaString(500, 400, 1.0, 1.0, 0.0, 0.0, 0, 0x000000, 0x000000, FALSE, "スコア:");
			SetFontSize(30);
			DrawFormatString(450, 400, 0x000000, "スコア:%d", enemy->GetScore());
		}
	}
	else {
		DrawRotaGraph(320, 275, 1.0, 0, Clear_Face, TRUE);
		if (TextCount > 60) {
			SetFontSize(40);
			DrawFormatString(230, 30, 0x000000,"撃退成功！！！");
		}
		if (TextCount > 120) {
			//DrawRotaString(500, 400, 1.0, 1.0, 0.0, 0.0, 0, 0x000000, 0x000000, TRUE, "スコア:");
			SetFontSize(30);
			DrawFormatString(450, 400, 0x000000, "スコア:%d", enemy->GetScore());
		}
	}
}