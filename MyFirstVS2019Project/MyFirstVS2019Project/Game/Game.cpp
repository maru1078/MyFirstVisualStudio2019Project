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

	// 1�͍̂ŏ��ɍ���Ă���
	auto gameObject = GameObjectManager::CreateGameObject("ObjectA");
	gameObject.lock()->AddComponent<TestOutput>();
	gameObject.lock()->AddComponent<DestroyObject>("ObjectB");

	std::cout << "�v���O�����J�n\n" << std::endl;

	while (input != "end")
	{
		std::cout << "�t���[���X�V" << std::endl;

		// �Q�[���I�u�W�F�N�g��A�R���|�[�l���g�̏���
		ComponentManager::Update();

		std::cout << std::endl;

		ComponentManager::Draw();

		std::cout << std::endl;

		std::cin >> input;

		if (input == "add")
		{
			std::string name;
			std::cout << "�ǉ�����I�u�W�F�N�g�̖��O�����-> ";
			std::cin >> name;

			GameObjectManager::CreateGameObject(name).lock()->AddComponent<TestOutput>();
		}

		std::cout << std::endl;

		// ���S�t���O�����������͍̂폜
		GameObjectManager::RemoveDeadGameObject();
		ComponentManager::RemoveDeadComponent();
	}

	std::cout << "�v���O�����I��" << std::endl;
}
