#include "GameObjectCreator.h"

#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../GameObject/GameObject.h"
#include "../TestOutput/TestOutput.h"

GameObjectCreator::GameObjectCreator(const std::string& inputStr, char splitter)
	: m_createStr{ inputStr }
	, m_splitter{ splitter }
{
}

GameObjectCreator::GameObjectCreator(const std::weak_ptr<const GameObjectCreator>& other)
	: m_createStr{ other.lock()->m_createStr }
	, m_splitter{ other.lock()->m_splitter }
{
}

std::weak_ptr<Component> GameObjectCreator::CloneComponent() const
{
	return ComponentManager::CreateComponent<GameObjectCreator>(
		std::dynamic_pointer_cast<const GameObjectCreator>(shared_from_this()));
}

void GameObjectCreator::Input(const std::string& inputStr)
{
	int idx = inputStr.find(m_splitter);

	// 分割できないときは即リターン
	if (idx == std::string::npos) return;

	std::string command = inputStr.substr(0, idx);
	if (command == m_createStr)
	{
		std::string objectName = inputStr.substr(idx + 1, inputStr.length());
		auto gameObject = GameObjectManager::CreateGameObject(objectName);

		// 追加されたかどうか確認のため「TestOutput」をつけておく
		gameObject.lock()->CreateComponent<TestOutput>();
	}
}
