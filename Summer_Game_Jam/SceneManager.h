#pragma once
#include "BaseScene.h"

class SceneManager : public BaseScene {
private:
	BaseScene* nScene;		//åªç›ÇÃÉVÅ[Éì
public:
	SceneManager(BaseScene* scene):nScene(scene){}
	~SceneManager() {
		delete nScene;
	}
	BaseScene* Update() override;
	void Initialize() const override;
	void Finalize() const override;
	void Draw() const override;
};