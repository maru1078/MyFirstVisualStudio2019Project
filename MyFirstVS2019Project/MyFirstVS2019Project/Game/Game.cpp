#include "Game.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../SceneManager/SceneManager.h"
#include "../TitleScene/TitleScene.h"

#include "../TestOutput/TestOutput.h"

#include <iostream>

bool Game::m_isExit{ false };

void Game::Run()
{
	std::string input = "";

	SceneManager::CreateCurrentScene<TitleScene>();

	ComponentManager::AddUpdatePriority<TestOutput>(-1.0f);
	ComponentManager::AddCollisionGroupPair(1, 2);

	std::cout << "�v���O�����J�n\n" << std::endl;

	while (!m_isExit)
	{
		std::cout << "�t���[���X�V" << std::endl;

		GameObjectManager::UpdateGameObjectList();
		ComponentManager::UpdateComponentList();

		// �Q�[���I�u�W�F�N�g��A�R���|�[�l���g�̏���
		ComponentManager::Update();

		std::cout << std::endl;

		ComponentManager::Draw();

		std::cout << std::endl;

		std::cin >> input;

		ComponentManager::SendInputStr(input);

		std::cout << std::endl;

		ComponentManager::Collide();

		std::cout << std::endl;

		// ���S�t���O�����������͍̂폜
		ComponentManager::RemoveDeadComponent();
		GameObjectManager::RemoveDeadGameObject();
	}

	std::cout << "�v���O�����I��" << std::endl;
}

void Game::ExitGame()
{
	m_isExit = true;
}
