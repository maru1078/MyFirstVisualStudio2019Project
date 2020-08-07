#include "TestOutput.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include <iostream>

TestOutput::TestOutput(float drawPriority)
	: Component{ drawPriority }
{
}

std::weak_ptr<Component> TestOutput::CloneComponent() const
{
	return ComponentManager::CreateComponent<TestOutput>(GetDrawPriority());
}

void TestOutput::Update()
{
	std::cout << GetGameObject().lock()->GetName() << " Update" << std::endl;
}

void TestOutput::Draw()
{
	std::cout << GetGameObject().lock()->GetName() << " Draw" << std::endl;
}

void TestOutput::OnCollide(const std::weak_ptr<GameObject>& other)
{
	std::cout << GetGameObject().lock()->GetName() << "OnCollide" << std::endl;
}
