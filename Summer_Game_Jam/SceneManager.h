#pragma once
#include "BaseScene.h"

class SceneManager : public BaseScene {
private:
	BaseScene* nScene;		//現在のシーン
public:
	SceneManager(BaseScene* scene):nScene(scene){}
	~SceneManager() {
		delete nScene;
	}
	BaseScene* Update() override;
	void Draw() const override;
};