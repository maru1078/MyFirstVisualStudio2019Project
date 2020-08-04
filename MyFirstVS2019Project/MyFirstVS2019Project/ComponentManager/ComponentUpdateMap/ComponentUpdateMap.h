#ifndef COMPONENT_UPDATE_MAP_H_
#define COMPONENT_UPDATE_MAP_H_

#include <memory>
#include <map>

class Component;

class ComponentUpdateMap
{
public:

	void ExecuteUpdate() const;

public:

	void Add(float priority, const std::weak_ptr<Component>& component);
	void RemoveDeadComponent();

private:

	std::multimap<float, std::weak_ptr<Component>> m_updateMap;
};

#endif // !COMPONENT_UPDATE_MAP_H_

