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

	template<class T>
	static void AddUpdatePriority(float priority);

private:

	static std::unordered_multimap<float, std::shared_ptr<Component>> m_addComponents;

	// Update関数の優先度を管理するためのもの
	static UpdatePriorityList m_updatePriorityList;

	// 優先度をつけて更新関数を呼ぶためのもの
	static ComponentUpdateMap m_updateMap;

	// コンポーネントをメインで管理するためのもの
	static ComponentMainList m_mainList;

	// 優先度をつけて描画関数を呼ぶためのもの
	static ComponentDrawMap m_drawMap;
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
