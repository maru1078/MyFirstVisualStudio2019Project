#include "ComponentManager.h"
#include "../Component/Component.h"

std::list<std::shared_ptr<Component>> ComponentManager::m_addComponents;
ComponentMainList ComponentManager::m_mainList;
ComponentDrawMap ComponentManager::m_drawMap;

void ComponentManager::UpdateComponentList()
{
    for (const auto& component : m_addComponents)
    {
        m_mainList.Add(component);
        m_drawMap.Add(component);
    }

    m_addComponents.clear();
}

void ComponentManager::RemoveDeadComponent()
{
    m_mainList.RemoveDeadComponent();
    m_drawMap.RemoveDeadComponent();
}

void ComponentManager::Update()
{
    m_mainList.ExecuteUpdate();
}

void ComponentManager::Draw()
{
    m_drawMap.ExecuteDraw();
}

void ComponentManager::SendInputStr(const std::string& inputStr)
{
    m_mainList.ExecuteInput(inputStr);
}
