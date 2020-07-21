#include "TestOutput.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include <iostream>

std::weak_ptr<Component> TestOutput::CloneComponent() const
{
	return ComponentManager::CreateComponent<TestOutput>();
}

void TestOutput::Update()
{
	std::cout << GetGameObject().lock()->GetName() << " Update" << std::endl;
}

void TestOutput::Draw()
{
	std::cout << GetGameObject().lock()->GetName() << " Draw" << std::endl;
}
