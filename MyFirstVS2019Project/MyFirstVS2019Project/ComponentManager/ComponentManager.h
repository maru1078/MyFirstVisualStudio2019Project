#ifndef COMPONENT_MANAGER_H_
#define COMPONENT_MANAGER_H_

#include <list>
#include <memory>

class Component;

class ComponentManager
{
public:

	static void RemoveDeadComponent();

	static void Update();
	static void Draw();

public:

	template<class T, class... Args>
	static std::weak_ptr<Component> CreateComponent(Args... args);

private:

	static std::list<std::shared_ptr<Component>> m_components;
};

template<class T, class... Args>
inline std::weak_ptr<Component> ComponentManager::CreateComponent(Args ...args)
{
	auto component = std::make_shared<T>(args...);
	m_components.push_back(component);

	return component;
}

#endif // !COMPONENT_MANAGER_H_
