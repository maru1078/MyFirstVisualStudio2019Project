#include "GameObjectManager.h"
#include "../GameObject/GameObject.h"

std::forward_list<std::shared_ptr<GameObject>> GameObjectManager::m_gameObjects;

std::weak_ptr<GameObject> GameObjectManager::CreateGameObject(const std::string& name)
{
	auto gameObject = std::make_shared<GameObject>(name);
	m_gameObjects.push_front(gameObject);

	return gameObject;
}
