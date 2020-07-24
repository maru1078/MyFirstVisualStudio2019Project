#include "GameObjectGenerator.h"

#include "../ComponentManager/ComponentManager.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../GameObject/GameObject.h"
#include "../TestOutput/TestOutput.h"

GameObjectGenerator::GameObjectGenerator(const std::string& inputStr, char splitter)
	: m_generateStr{ inputStr }
	, m_splitter{ splitter }
{
}

GameObjectGenerator::GameObjectGenerator(const std::weak_ptr<const GameObjectGenerator>& other)
	: m_generateStr{ other.lock()->m_generateStr }
	, m_splitter{ other.lock()->m_splitter }
{
}

std::weak_ptr<Component> GameObjectGenerator::CloneComponent() const
{
	return ComponentManager::CreateComponent<GameObjectGenerator>(
		std::dynamic_pointer_cast<const GameObjectGenerator>(shared_from_this()));
}

void GameObjectGenerator::Input(const std::string& inputStr)
{
	int idx = inputStr.find(m_splitter);

	// �����ł��Ȃ��Ƃ��͑����^�[��
	if (idx == std::string::npos) return;

	std::string command = inputStr.substr(0, idx);
	if (command == m_generateStr)
	{
		std::string objectName = inputStr.substr(idx + 1, inputStr.length());
		auto gameObject = GameObjectManager::CreateGameObject(objectName);

		// �ǉ����ꂽ���ǂ����m�F�̂��߁uTestOutput�v�����Ă���
		gameObject.lock()->CreateComponent<TestOutput>();
	}
}
