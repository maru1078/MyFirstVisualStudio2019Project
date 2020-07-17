#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutput/TestOutput.h"
#include "../DestroyObject/DestroyObject.h"

#include <iostream>
#include <memory>

void Game::Run()
{
	std::string input = "";

	// 1体は最初に作っておく
	auto gameObject = GameObjectManager::CreateGameObject("ObjectA");
	gameObject.lock()->AddComponent<TestOutput>();
	gameObject.lock()->AddComponent<DestroyObject>("ObjectB");

	std::cout << "プログラム開始\n" << std::endl;

	while (input != "end")
	{
		std::cout << "フレーム更新" << std::endl;

		// ゲームオブジェクトや、コンポーネントの処理
		ComponentManager::Update();

		std::cout << std::endl;

		ComponentManager::Draw();

		std::cout << std::endl;

		std::cin >> input;

		if (input == "add")
		{
			std::string name;
			std::cout << "追加するオブジェクトの名前を入力-> ";
			std::cin >> name;

			GameObjectManager::CreateGameObject(name).lock()->AddComponent<TestOutput>();
		}

		std::cout << std::endl;

		// 死亡フラグが立ったものは削除
		GameObjectManager::RemoveDeadGameObject();
		ComponentManager::RemoveDeadComponent();
	}

	std::cout << "プログラム終了" << std::endl;
}
