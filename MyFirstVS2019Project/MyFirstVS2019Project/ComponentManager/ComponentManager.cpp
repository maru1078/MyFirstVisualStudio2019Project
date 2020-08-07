#include "ComponentManager.h"
#include "../Component/Component.h"

std::unordered_multimap<float, std::shared_ptr<Component>> ComponentManager::m_addComponents;
UpdatePriorityList ComponentManager::m_updatePriorityList;
ComponentUpdateMap ComponentManager::m_updateMap;
ComponentMainList ComponentManager::m_mainList;
ComponentDrawMap ComponentManager::m_drawMap;
ColliderList ComponentManager::m_colliderList;

void ComponentManager::UpdateComponentList()
{
    for (const auto& pair : m_addComponents)
    {
        m_mainList.Add(pair.second);
        m_updateMap.Add(pair.first, pair.second);
        m_drawMap.Add(pair.second);
        m_colliderList.CheckAndAdd(pair.second);
    }

    m_addComponents.clear();
}

void ComponentManager::RemoveDeadComponent()
{
    m_mainList.RemoveDeadComponent();
    m_updateMap.RemoveDeadComponent();
    m_drawMap.RemoveDeadComponent();
}

void ComponentManager::Update()
{
    m_updateMap.ExecuteUpdate();
}

void ComponentManager::Draw()
{
    m_drawMap.ExecuteDraw();
}

void ComponentManager::Collide()
{
    m_colliderList.ExecuteIsCollide();
}

void ComponentManager::SendInputStr(const std::string& inputStr)
{
    m_mainList.ExecuteInput(inputStr);
}
