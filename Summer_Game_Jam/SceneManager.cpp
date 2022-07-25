#include "SceneManager.h"

void SceneManager::Initialize() const {

}
void SceneManager::Finalize() const {

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