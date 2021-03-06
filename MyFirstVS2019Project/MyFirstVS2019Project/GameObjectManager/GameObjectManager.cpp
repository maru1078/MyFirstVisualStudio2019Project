#include "GameObjectManager.h"
#include "../GameObject/GameObject.h"

std::forward_list<std::shared_ptr<GameObject>> GameObjectManager::m_addGameObjects;
std::forward_list<std::shared_ptr<GameObject>> GameObjectManager::m_gameObjects;

std::weak_ptr<GameObject> GameObjectManager::FindGameObject(const std::string& name)
{
	for (const auto& gameObject : m_gameObjects)
	{
		if (gameObject->GetName() == name)
		{
			return gameObject;
		}
	}

	return std::weak_ptr<GameObject>();
}

std::forward_list<std::weak_ptr<GameObject>> GameObjectManager::FindGameObjects(const std::string& name)
{
	std::forward_list<std::weak_ptr<GameObject>> result;

	for (const auto& gameObject : m_gameObjects)
	{
		if (gameObject->GetName() == name)
		{
			result.push_front(gameObject);
		}
	}

	return result;
}

void GameObjectManager::UpdateGameObjectList()
{
	for (const auto& gameObject : m_addGameObjects)
	{
		m_gameObjects.push_front(gameObject);
	}

	m_addGameObjects.clear();
}

void GameObjectManager::RemoveDeadGameObject()
{
	m_gameObjects.remove_if([](const auto& gameObject) 
		{
			return gameObject->IsDead();
		});
}

std::weak_ptr<GameObject> GameObjectManager::CreateGameObject(const std::string& name)
{
	auto gameObject = std::make_shared<GameObject>(name);
	m_addGameObjects.push_front(gameObject);

	return gameObject;
}

std::weak_ptr<GameObject> GameObjectManager::CloneGameObject(const std::weak_ptr<GameObject>& gameObject)
{
	auto clone = std::make_shared<GameObject>(gameObject);
	m_addGameObjects.push_front(clone);

	return clone;
}

void GameObjectManager::SendMessage(const std::string& message)
{
	for (const auto& gameObject : m_gameObjects)
	{
		gameObject->SendMessage(message);
	}
}
