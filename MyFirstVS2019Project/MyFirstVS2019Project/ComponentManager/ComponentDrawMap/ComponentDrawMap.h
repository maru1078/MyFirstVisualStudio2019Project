#ifndef COMPONENT_DRAW_LIST_H_
#define COMPONENT_DRAW_LIST_H_

#include <memory>
#include <map>

class Component;

class ComponentDrawMap
{
public:

	void ExecuteDraw() const;

public:

	void Add(const std::weak_ptr<Component>& component);
	void RemoveDeadComponent();

private:

	std::multimap<float, std::weak_ptr<Component>> m_drawMap;
};

#endif // !COMPONENT_DRAW_LIST_H_

