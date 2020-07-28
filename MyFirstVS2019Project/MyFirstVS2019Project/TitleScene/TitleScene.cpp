#include "TitleScene.h"
#include "../GameObject/GameObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TitleSceneOutputer/TitleSceneOutputer.h"
#include "../SceneChanger/SceneChanger.h"

void TitleScene::Start()
{
	auto outputer = GameObjectManager::CreateGameObject("SceneOutputer");
	outputer.lock()->CreateComponent<TitleSceneOutputer>();

	auto sceneChanger = GameObjectManager::CreateGameObject("SceneChanger");
	sceneChanger.lock()->CreateComponent<SceneChanger>("Start");
}

void TitleScene::End()
{
	// �^�C�g���V�[������̃I�u�W�F�N�g���폜
	//GameObjectManager::FindGameObject("SceneOutputer").lock()->Destroy();
	//GameObjectManager::FindGameObject("SceneChanger").lock()->Destroy();
	GameObjectManager::SendMessage("ChangeToMainScene");
}
