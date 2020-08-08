#ifndef COLLIDER_LIST_H_
#define COLLIDER_LIST_H_

#include <forward_list>
#include <memory>
#include <vector>
#include <utility>

class Component;
class Collider;

class ColliderList
{
public:

	void CheckAndAdd(const std::weak_ptr<Component>& component);
	void RemoveDeadComponent();
	void ExecuteIsCollide() const;
	void AddCollisionGroupPair(int first, int second);

private: 

	bool CheckCollisionPair(int group1, int group2) const;

private:

	std::forward_list<std::weak_ptr<Collider>> m_colliderList;
	std::vector<std::pair<int, int>> m_groupArray;
};

#endif // !COLLIDER_LIST_H_

