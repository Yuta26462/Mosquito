#pragma once
#include "BaseScene.h"
#include "enemy.h"

class GameMain : public BaseScene {
private:
	mutable int TimeLimt;
	mutable int Main_BGM, MainUp_BGM;
	mutable int Wind_chimes_SE;
	mutable int Moon_img, Sun_img;
	mutable int MoonX,MoonY,SunX,SunY;
	mutable int BackgroundColor, Bright;
	//bool StartFlg;
	static int StatusFont;
	
public:
	GameMain();
	virtual ~GameMain() {};
	virtual BaseScene* Update() override;
	virtual void Initialize() const override;
	virtual void Finalize() const override;
	virtual void Draw() const override;
	int GetTime() const;
	static int GetFont();
};