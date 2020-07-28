#include "TitleSceneOutputer.h"
#include <iostream>

#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"

std::weak_ptr<Component> TitleSceneOutputer::CloneComponent() const
{
	return ComponentManager::CreateComponent<TitleSceneOutputer>();
}

void TitleSceneOutputer::Update()
{
	std::cout << "TitleScene‚Å‚·" << std::endl;
}

void TitleSceneOutputer::HandleMessage(const std::string& message)
{
	if (message == "ChangeToMainScene")
	{
		GetGameObject().lock()->Destroy();
	}
}
