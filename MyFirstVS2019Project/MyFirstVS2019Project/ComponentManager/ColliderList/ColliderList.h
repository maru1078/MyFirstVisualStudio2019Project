#ifndef COLLIDER_LIST_H_
#define COLLIDER_LIST_H_

#include <forward_list>
#include <memory>

class Component;
class Collider;

class ColliderList
{
public:

	void CheckAndAdd(const std::weak_ptr<Component>& component);
	void RemoveDeadComponent();
	void ExecuteIsCollide() const;

private:

	std::forward_list<std::weak_ptr<Collider>> m_colliderList;
};

#endif // !COLLIDER_LIST_H_

