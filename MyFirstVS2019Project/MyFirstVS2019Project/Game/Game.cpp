#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../TestOutput/TestOutput.h"
#include "../DestroyObject/DestroyObject.h"
#include "../CloneObject/CloneObject.h"
#include "../GameTerminator/GameTerminator.h"
#include "../GameObjectCreator/GameObjectCreator.h"
#include "../SceneManager/SceneManager.h"
#include "../TitleScene/TitleScene.h"

#include <iostream>

bool Game::m_isExit{ false };

void Game::Run()
{
	std::string input = "";

	SceneManager::CreateCurrentScene<TitleScene>();

	std::cout << "プログラム開始\n" << std::endl;

	while (!m_isExit)
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

		ComponentManager::SendInputStr(input);

		std::cout << std::endl;

		// 死亡フラグが立ったものは削除
		ComponentManager::RemoveDeadComponent();
		GameObjectManager::RemoveDeadGameObject();
	}

	std::cout << "プログラム終了" << std::endl;
}

void Game::ExitGame()
{
	m_isExit = true;
}
