#pragma once
#include "BaseScene.h"
#include "enemy.h"


class GameMain : public BaseScene {
private:
	Enemy enemy[10];
	mutable int TimeLimt = 1860;
	mutable int Main_BGM, MainUp_BGM;
public:
	GameMain();
	virtual ~GameMain() {};
	virtual BaseScene* Update() override;
	virtual void Initialize() const override;
	virtual void Finalize() const override;
	virtual void Draw() const override;
	int GetTime() const;
};