#pragma once
#include "BaseScene.h"
#include "enemy.h"


class GameMain : public BaseScene {
private:
	mutable int TimeLimt;
	mutable int Main_BGM, MainUp_BGM;
	mutable int Wind_chimes_SE;
	bool StartFlg;
	int StatusFont;
public:
	GameMain();
	virtual ~GameMain() {};
	virtual BaseScene* Update() override;
	virtual void Initialize() const override;
	virtual void Finalize() const override;
	virtual void Draw() const override;
	int GetTime() const;
};