#ifndef GAME_OBJECT_H_
#define GAME_OBJECT_H_

#include <string>
#include <vector>
#include <memory>
#include "../ComponentManager/ComponentManager.h"

class Component;

class GameObject : public std::enable_shared_from_this<GameObject>
{
public:

	GameObject(const std::string& name);

public:

	void Destroy();
	bool IsDead() const;

	const std::string& GetName() const;

	template<class T, class... Args>
	void AddComponent(Args... args);

private:

	std::string m_name;
	std::vector<std::weak_ptr<Component>> m_components;
	bool m_isDead{ false };
};

template<class T, class... Args>
inline void GameObject::AddComponent(Args... args)
{
	auto component = ComponentManager::CreateComponent<T>(args...);
	component.lock()->SetGameObject(weak_from_this());
	m_components.push_back(component);
}

#endif // !GAME_OBJECT_H_
