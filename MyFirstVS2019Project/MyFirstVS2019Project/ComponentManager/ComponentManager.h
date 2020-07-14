#ifndef COMPONENT_MANAGER_H_
#define COMPONENT_MANAGER_H_

#include <list>
#include <memory>

class Component;

class ComponentManager
{
public:

	static void Update();
	static void Draw();

	static std::weak_ptr<Component> CreateComponent();

private:

	static std::list<std::shared_ptr<Component>> m_components;
};

#endif // !COMPONENT_MANAGER_H_

