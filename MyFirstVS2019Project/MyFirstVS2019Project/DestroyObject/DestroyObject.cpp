#include "DestroyObject.h"
#include "../GameObjectManager/GameObjectManager.h"
#include "../GameObject/GameObject.h"
#include "../ComponentManager/ComponentManager.h"

DestroyObject::DestroyObject(const std::string& objectName)
	: m_objectName{ objectName }
{
}

std::weak_ptr<Component> DestroyObject::CloneComponent()
{
	return ComponentManager::CreateComponent<DestroyObject>(m_objectName);
}

void DestroyObject::Update()
{
	auto gameObjects = GameObjectManager::FindGameObjects(m_objectName);

	for (const auto& gameObject : gameObjects)
	{
		gameObject.lock()->Destroy();
	}
}
