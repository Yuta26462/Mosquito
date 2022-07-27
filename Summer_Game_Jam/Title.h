#pragma once
#include "BaseScene.h"

class Title : public BaseScene {
private:
	int MenuFont;
	int SelectNo;
	int Menu_img;
	int Pointer_img;
	int Help_img;
	int Credit_img;
	int Pad_img;
	int MenuChangeFlg;
	int OK_SE;
	int Selecter_SE;
	int Return_SE;
	int Title_BGM;
public:
	Title();
	virtual ~Title() {};
	virtual BaseScene* Update() override;
	virtual void Initialize() const override;
	virtual void Finalize() const override;
	virtual void Draw() const override;
};