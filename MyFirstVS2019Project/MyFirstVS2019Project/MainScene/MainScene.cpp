#include "MainScene.h"
#include "../GameObject/GameObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutput/TestOutput.h"
#include "../GameTerminator/GameTerminator.h"
#include "../DestroyObject/DestroyObject.h"
#include "../CloneObject/CloneObject.h"
#include "../GameObjectCreator/GameObjectCreator.h"
#include "../Collider/Collider.h"

void MainScene::Start()
{
	// 1体は最初に作っておく
	{
		auto gameObject = GameObjectManager::CreateGameObject("ObjectA");
		gameObject.lock()->CreateComponent<TestOutput>(1.0f);
		gameObject.lock()->CreateComponent<DestroyObject>("ObjectB");
		gameObject.lock()->CreateComponent<CloneObject>(2);
		gameObject.lock()->CreateComponent<Collider>(1);
	}

	// ゲーム終了処理などを行うオブジェクトは別にしておく
	{
		auto gameObject = GameObjectManager::CreateGameObject("GameController");
		gameObject.lock()->CreateComponent<GameTerminator>("end");
		gameObject.lock()->CreateComponent<GameObjectCreator>("add", '_');
		gameObject.lock()->CreateComponent<Collider>(2);
	}
}

void MainScene::End()
{
	// 特になし
}
