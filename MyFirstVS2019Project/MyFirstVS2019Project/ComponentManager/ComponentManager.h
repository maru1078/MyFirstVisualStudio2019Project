#ifndef COMPONENT_MANAGER_H_
#define COMPONENT_MANAGER_H_

#include <list>
#include <memory>
#include <string>
#include <unordered_map>
#include "ComponentDrawMap/ComponentDrawMap.h"
#include "ComponentMainList/ComponentMainList.h"
#include "ComponentUpdateMap/ComponentUpdateMap.h"
#include "UpdatePriorityList/UpdatePriorityList.h"
#include "ColliderList/ColliderList.h"

class Component;

class ComponentManager
{
public:

	static void UpdateComponentList();
	static void RemoveDeadComponent();

	static void Update();
	static void Draw();
	static void Collide(); // �Փ˔�����s��

	static void SendInputStr(const std::string& inputStr);

public:

	template<class T, class... Args>
	static std::weak_ptr<Component> CreateComponent(const Args&... args);

	template<class T>
	static void AddUpdatePriority(float priority);

	static void AddCollisionGroupPair(int first, int second);

private:

	static std::unordered_multimap<float, std::shared_ptr<Component>> m_addComponents;

	// Update�֐��̗D��x���Ǘ����邽�߂̂���
	static UpdatePriorityList m_updatePriorityList;

	// �D��x�����čX�V�֐����ĂԂ��߂̂���
	static ComponentUpdateMap m_updateMap;

	// �R���|�[�l���g�����C���ŊǗ����邽�߂̂���
	static ComponentMainList m_mainList;

	// �D��x�����ĕ`��֐����ĂԂ��߂̂���
	static ComponentDrawMap m_drawMap;

	// �Փ˔����p�̃��X�g
	static ColliderList m_colliderList;
};

template<class T, class... Args>
inline std::weak_ptr<Component> ComponentManager::CreateComponent(const Args&... args)
{
	auto component = std::make_shared<T>(args...);
	m_addComponents.emplace(m_updatePriorityList.GetUpdatePriority<T>(), component);

	return component;
}

template<class T>
inline void ComponentManager::AddUpdatePriority(float priority)
{
	m_updatePriorityList.AddPriority<T>(priority);
}

#endif // !COMPONENT_MANAGER_H_
