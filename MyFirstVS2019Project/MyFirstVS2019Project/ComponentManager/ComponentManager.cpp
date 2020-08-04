#include "ComponentManager.h"
#include "../Component/Component.h"

std::list<std::shared_ptr<Component>> ComponentManager::m_addComponents;
std::list<std::shared_ptr<Component>> ComponentManager::m_components;
ComponentDrawMap ComponentManager::m_drawMap;

void ComponentManager::UpdateComponentList()
{
    for (const auto& component : m_addComponents)
    {
        m_components.push_back(component);
        m_drawMap.Add(component);
    }

    m_addComponents.clear();
}

void ComponentManager::RemoveDeadComponent()
{
    m_components.remove_if([](const auto& component)
        {
            return component->IsDead();
        });

    m_drawMap.RemoveDeadComponent();
}

void ComponentManager::Update()
{
    for (const auto& component : m_components)
    {
        // 追加されたうえで削除されてるかどうかの確認のため、今はコメント化。
        //if (component->IsDead()) continue;

        component->Update();
    }
}

void ComponentManager::Draw()
{
    //for (const auto& component : m_components)
    //{
    //    // 追加されたうえで削除されてるかどうかの確認のため、今はコメント化。
    //    //if (component->IsDead()) continue;

    //    component->Draw();
    //}

    m_drawMap.ExecuteDraw();
}

void ComponentManager::SendInputStr(const std::string& inputStr)
{
    for (const auto& component : m_components)
    {
        component->Input(inputStr);
    }
}
