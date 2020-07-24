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

	// 1�͍̂ŏ��ɍ���Ă���
	{
		auto gameObject = GameObjectManager::CreateGameObject("ObjectA");
		gameObject.lock()->CreateComponent<TestOutput>();
		gameObject.lock()->CreateComponent<DestroyObject>("ObjectB");
		gameObject.lock()->CreateComponent<CloneObject>(2);
	}

	// �Q�[���I�������Ȃǂ��s���I�u�W�F�N�g�͕ʂɂ��Ă���
	{
		auto gameObject = GameObjectManager::CreateGameObject("GameController");
		gameObject.lock()->CreateComponent<GameTerminator>("end");
	}

	std::cout << "�v���O�����J�n\n" << std::endl;

	while (/*input != "end"*/!m_isExit)
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

		//if (input == "add")
		//{
		//	std::string name;
		//	std::cout << "�ǉ�����I�u�W�F�N�g�̖��O�����-> ";
		//	std::cin >> name;

		//	GameObjectManager::CreateGameObject(name).lock()->CreateComponent<TestOutput>();
		//}

		ComponentManager::SendInputStr(input);

		std::cout << std::endl;

		// ���S�t���O�����������͍̂폜
		GameObjectManager::RemoveDeadGameObject();
		ComponentManager::RemoveDeadComponent();
	}

	std::cout << "�v���O�����I��" << std::endl;
}

void Game::ExitGame()
{
	m_isExit = true;
}
