#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutput/TestOutput.h"
#include "../DestroyObject/DestroyObject.h"
#include "../CloneObject/CloneObject.h"
#include "../GameTerminator/GameTerminator.h"

#include <iostream>
#include <memory>

bool Game::m_isExit{ false };

void Game::Run()
{
	std::string input = "";

	// 1体は最初に作っておく
	{
		auto gameObject = GameObjectManager::CreateGameObject("ObjectA");
		gameObject.lock()->CreateComponent<TestOutput>();
		gameObject.lock()->CreateComponent<DestroyObject>("ObjectB");
		gameObject.lock()->CreateComponent<CloneObject>(2);
	}

	// ゲーム終了処理などを行うオブジェクトは別にしておく
	{
		auto gameObject = GameObjectManager::CreateGameObject("GameController");
		gameObject.lock()->CreateComponent<GameTerminator>("end");
	}

	std::cout << "プログラム開始\n" << std::endl;

	while (/*input != "end"*/!m_isExit)
	{
		std::cout << "フレーム更新" << std::endl;

		GameObjectManager::UpdateGameObjectList();
		ComponentManager::UpdateComponentList();

		// ゲームオブジェクトや、コンポーネントの処理
		ComponentManager::Update();

		std::cout << std::endl;

		ComponentManager::Draw();

		std::cout << std::endl;

		std::cin >> input;

		//if (input == "add")
		//{
		//	std::string name;
		//	std::cout << "追加するオブジェクトの名前を入力-> ";
		//	std::cin >> name;

		//	GameObjectManager::CreateGameObject(name).lock()->CreateComponent<TestOutput>();
		//}

		ComponentManager::SendInputStr(input);

		std::cout << std::endl;

		// 死亡フラグが立ったものは削除
		GameObjectManager::RemoveDeadGameObject();
		ComponentManager::RemoveDeadComponent();
	}

	std::cout << "プログラム終了" << std::endl;
}

void Game::ExitGame()
{
	m_isExit = true;
}
