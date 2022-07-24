#pragma once
#include "BaseScene.h"

class Title : public BaseScene {
private:
	int SelectNo;
public:
	virtual ~Title() {};
	virtual BaseScene* Update() override;
	virtual void Draw() const override;
};