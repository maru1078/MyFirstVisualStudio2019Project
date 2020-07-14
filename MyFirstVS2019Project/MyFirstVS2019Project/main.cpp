#include <iostream>
#include "GameObjectManager/GameObjectManager.h"
#include "ComponentManager/ComponentManager.h"
#include "Component/Component.h"
#include "GameObject/GameObject.h"

int main()
{
	std::string name = "Object";
	char alphabet = 'A';

	std::string input;

	std::cout << "プログラム開始\n" << std::endl;

	GameObjectManager::CreateGameObject(name + (alphabet++)).lock()->AddComponent();
	GameObjectManager::CreateGameObject(name + (alphabet++)).lock()->AddComponent();

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
			GameObjectManager::CreateGameObject(name + (alphabet++)).lock()->AddComponent();
		}

		std::cout << std::endl;
	}

	std::cout << "プログラム終了" << std::endl;

	return 0;
}