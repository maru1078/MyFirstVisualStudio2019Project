#include "Game.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"

#include <iostream>
#include <memory>

void Game::Run()
{
	std::string input = "";

	// 1�͍̂ŏ��ɍ���Ă���
	GameObjectManager::CreateGameObject("ObjectA").lock()->AddComponent();

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

			GameObjectManager::CreateGameObject(name).lock()->AddComponent();
		}

		std::cout << std::endl;
	}

	std::cout << "�v���O�����I��" << std::endl;
}
