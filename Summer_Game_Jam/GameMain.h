#pragma once
#include "BaseScene.h"


class GameMain : public BaseScene {
public:
	virtual ~GameMain() {};
	virtual BaseScene* Update() override;
	virtual void Initialize() const override;
	virtual void Finalize() const override;
	virtual void Draw() const override;
};