#ifndef COMPONENT_MANAGER_H_
#define COMPONENT_MANAGER_H_

#include <list>
#include <memory>
#include <string>

class Component;

class ComponentManager
{
public:

	static void UpdateComponentList();
	static void RemoveDeadComponent();

	static void Update();
	static void Draw();

	static void SendInputStr(const std::string& inputStr);

public:

	template<class T, class... Args>
	static std::weak_ptr<Component> CreateComponent(const Args&... args);

private:

	static std::list<std::shared_ptr<Component>> m_addComponents;
	static std::list<std::shared_ptr<Component>> m_components;
};

template<class T, class... Args>
inline std::weak_ptr<Component> ComponentManager::CreateComponent(const Args&... args)
{
	auto component = std::make_shared<T>(args...);
	m_addComponents.push_back(component);

	return component;
}

#endif // !COMPONENT_MANAGER_H_
