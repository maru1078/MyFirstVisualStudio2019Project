#ifndef GAME_OBJECT_MANAGER_H_
#define GAME_OBJECT_MANAGER_H_

#include <forward_list>
#include <memory>
#include <string>

class GameObject;

class GameObjectManager
{
public:

	static std::weak_ptr<GameObject> FindGameObject(const std::string& name);
	static std::forward_list<std::weak_ptr<GameObject>> FindGameObjects(const std::string& name);

	static void UpdateGameObjectList();

	static void RemoveDeadGameObject();

	static std::weak_ptr<GameObject> CreateGameObject(const std::string& name);

	static std::weak_ptr<GameObject> CloneGameObject(const std::weak_ptr<GameObject>& gameObject);

	// 全てのゲームオブジェクトにメッセージを送信する
	static void SendMessage(const std::string& message);

private:

	static std::forward_list<std::shared_ptr<GameObject>> m_addGameObjects;
	static std::forward_list<std::shared_ptr<GameObject>> m_gameObjects;

};

#endif // !GAME_OBJECT_MANAGER_H_

