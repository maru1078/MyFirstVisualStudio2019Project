#ifndef COMPONENT_MAIN_LIST_H_
#define COMPONENT_MAIN_LIST_H_

#include <memory>
#include <list>
#include <string>

class Component;

class ComponentMainList
{
public:

	void Add(const std::shared_ptr<Component>& component);
	void RemoveDeadComponent();
	void ExecuteUpdate() const;
	void ExecuteInput(const std::string& inputStr) const;

private:

	std::list<std::shared_ptr<Component>> m_components;
};

#endif // !COMPONENT_MAIN_LIST_H_

