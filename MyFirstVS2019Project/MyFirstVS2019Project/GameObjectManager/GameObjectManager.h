#ifndef GAME_OBJECT_MANAGER_H_
#define GAME_OBJECT_MANAGER_H_

#include <forward_list>
#include <memory>
#include <string>

class GameObject;

class GameObjectManager
{
public:

	static std::forward_list<std::weak_ptr<GameObject>> FindGameObjects(const std::string& name);

	static void UpdateGameObjectList();

	static void RemoveDeadGameObject();

	static std::weak_ptr<GameObject> CreateGameObject(const std::string& name);

private:

	static std::forward_list<std::shared_ptr<GameObject>> m_addGameObjects;
	static std::forward_list<std::shared_ptr<GameObject>> m_gameObjects;

};

#endif // !GAME_OBJECT_MANAGER_H_

