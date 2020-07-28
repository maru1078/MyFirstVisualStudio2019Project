#include "SceneChanger.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"
#include "../SceneManager/SceneManager.h"
#include "../MainScene/MainScene.h"

SceneChanger::SceneChanger(const std::string& changeStr)
	: m_changeStr{ changeStr }
{
}

std::weak_ptr<Component> SceneChanger::CloneComponent() const
{
	return ComponentManager::CreateComponent<SceneChanger>(m_changeStr);
}

void SceneChanger::Input(const std::string& inputStr)
{
	if (inputStr == m_changeStr)
	{
		SceneManager::CreateCurrentScene<MainScene>();
	}
}

void SceneChanger::HandleMessage(const std::string& message)
{
	if (message == "ChangeToMainScene")
	{
		GetGameObject().lock()->Destroy();
	}
}
