#pragma once
#include "BaseScene.h"
#include "enemy.h"


class GameMain : public BaseScene {
private:
	Enemy enemy[10];
public:
	virtual ~GameMain() {};
	virtual BaseScene* Update() override;
	virtual void Initialize() const override;
	virtual void Finalize() const override;
	virtual void Draw() const override;
};