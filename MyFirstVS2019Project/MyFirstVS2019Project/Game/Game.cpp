#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"

#include <iostream>
#include <memory>

void Game::Run()
{
	std::string input = "";

	// 1体は最初に作っておく
	GameObjectManager::CreateGameObject("ObjectA").lock()->AddComponent();

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

			GameObjectManager::CreateGameObject(name).lock()->AddComponent();
		}

		std::cout << std::endl;
	}

	std::cout << "プログラム終了" << std::endl;
}
