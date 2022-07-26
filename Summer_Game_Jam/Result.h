#pragma once
#include "BaseScene.h"

class Result : public BaseScene {
	int GameClear_BGM, GameOver_BGM;
public:
	Result();
	virtual ~Result() {};
	virtual BaseScene* Update() override;
	virtual void Initialize() const override;
	virtual void Finalize() const override;
	virtual void Draw() const override;
};