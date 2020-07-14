#include <iostream>
#include "ComponentManager/ComponentManager.h"
#include "Component/Component.h"
#include "GameObject/GameObject.h"

int main()
{
	std::string input;

	std::cout << "�v���O�����J�n" << std::endl;

	auto g = std::make_shared<GameObject>("Test");
	g->AddComponent();

	while (input != "end")
	{
		// �Q�[���I�u�W�F�N�g��A�R���|�[�l���g�̏���
		ComponentManager::Update();
		ComponentManager::Draw();

		std::cin >> input;
	}

	std::cout << "�v���O�����I��" << std::endl;

	return 0;
}