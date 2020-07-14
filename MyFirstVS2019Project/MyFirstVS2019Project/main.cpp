#include <iostream>
#include "ComponentManager/ComponentManager.h"
#include "Component/Component.h"
#include "GameObject/GameObject.h"

int main()
{
	std::string input;

	std::cout << "プログラム開始" << std::endl;

	auto g = std::make_shared<GameObject>("Test");
	g->AddComponent();

	while (input != "end")
	{
		// ゲームオブジェクトや、コンポーネントの処理
		ComponentManager::Update();
		ComponentManager::Draw();

		std::cin >> input;
	}

	std::cout << "プログラム終了" << std::endl;

	return 0;
}