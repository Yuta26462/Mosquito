#pragma once
#include "BaseScene.h"

class Result : public BaseScene {
public:
	virtual ~Result() {};
	virtual BaseScene* Update() override;
	virtual void Draw() const override;
};