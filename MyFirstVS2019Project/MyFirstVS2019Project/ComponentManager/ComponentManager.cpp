#include "ComponentManager.h"
#include "../Component/Component.h"

std::list<std::shared_ptr<Component>> ComponentManager::m_addComponents;
std::list<std::shared_ptr<Component>> ComponentManager::m_components;
std::multimap<float, std::shared_ptr<Component>> ComponentManager::m_drawMap;

void ComponentManager::UpdateComponentList()
{
    for (const auto& component : m_addComponents)
    {
        m_components.push_back(component);
        m_drawMap.emplace(component->GetDrawPriority(), component);
    }

    m_addComponents.clear();
}

void ComponentManager::RemoveDeadComponent()
{
    m_components.remove_if([](const auto& component)
        {
            return component->IsDead();
        });

    for (auto it = m_drawMap.begin(); it != m_drawMap.end();)
    {
        if ((*it).second->IsDead())
        {
            it = m_drawMap.erase(it);
        }
        else
        {
            ++it;
        }
    }
}

void ComponentManager::Update()
{
    for (const auto& component : m_components)
    {
        // �ǉ����ꂽ�����ō폜����Ă邩�ǂ����̊m�F�̂��߁A���̓R�����g���B
        //if (component->IsDead()) continue;

        component->Update();
    }
}

void ComponentManager::Draw()
{
    //for (const auto& component : m_components)
    //{
    //    // �ǉ����ꂽ�����ō폜����Ă邩�ǂ����̊m�F�̂��߁A���̓R�����g���B
    //    //if (component->IsDead()) continue;

    //    component->Draw();
    //}

    for (const auto& pair : m_drawMap)
    {
        // �ǉ����ꂽ�����ō폜����Ă邩�ǂ����̊m�F�̂��߁A���̓R�����g���B
        //if (component->IsDead()) continue;

        pair.second->Draw();
    }
}

void ComponentManager::SendInputStr(const std::string& inputStr)
{
    for (const auto& component : m_components)
    {
        component->Input(inputStr);
    }
}
