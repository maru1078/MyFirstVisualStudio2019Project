#include "DestroyObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../GameObject/GameObject.h"

DestroyObject::DestroyObject(const std::string& objectName)
	: m_objectName{ objectName }
{
}

void DestroyObject::Update()
{
	auto gameObjects = GameObjectManager::FindGameObjects(m_objectName);

	for (const auto& gameObject : gameObjects)
	{
		gameObject.lock()->Destroy();
	}
}
