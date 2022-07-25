#include "SceneManager.h"

void SceneManager::Initialize() const {
	nScene->Initialize();
}
void SceneManager::Finalize() const {
	nScene->Finalize();
}
BaseScene* SceneManager::Update() {
	BaseScene* p = nScene->Update();
	if (p != nScene) {
		delete nScene;
		nScene = p;
	}
	return p;
}

void SceneManager::Draw() const {
	nScene->Draw();
}