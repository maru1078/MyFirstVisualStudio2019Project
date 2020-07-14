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

	std::cout << "�v���O�����J�n\n" << std::endl;

	GameObjectManager::CreateGameObject(name + (alphabet++)).lock()->AddComponent();
	GameObjectManager::CreateGameObject(name + (alphabet++)).lock()->AddComponent();

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
			GameObjectManager::CreateGameObject(name + (alphabet++)).lock()->AddComponent();
		}

		std::cout << std::endl;
	}

	std::cout << "�v���O�����I��" << std::endl;

	return 0;
}