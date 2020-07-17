#include "TestOutput.h"
#include "../GameObject/GameObject.h"
#include <iostream>

void TestOutput::Update()
{
	std::cout << GetGameObject().lock()->GetName() << " Update" << std::endl;
}

void TestOutput::Draw()
{
	std::cout << GetGameObject().lock()->GetName() << " Draw" << std::endl;
}
